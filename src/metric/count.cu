#include <string>
#include <vector>

#define MAX_VALUE 256
#define BLOCKS 32
#define THREADS 128

__global__ void count(int *array, int *output, size_t n) {

  size_t b_id = blockIdx.x;
  size_t b_num = gridDim.x;
  size_t t_id = threadIdx.x;
  size_t t_num = blockDim.x;

  // initialize a shared memory array to store the count for each block.
  __shared__ int count[MAX_VALUE];

  // set intial values to zeros. Each thread sets its own share to zero.
  size_t t_size = (t_num > MAX_VALUE ? 1 : MAX_VALUE / t_num);
  size_t offset = t_id * t_size;
  for (size_t i = offset; i < offset + t_size && i < MAX_VALUE; ++i)
    count[i] = 0;

  // wait until all threads have completed the initialization process.
  __syncthreads();

  // accumulate the counts of each value. Each thread counts a certain portion
  // of the array.
  size_t b_size = (b_num > n ? 1 : n / b_num);
  size_t b_offset = b_id * b_size;

  t_size = (t_num > b_size ? 1 : b_size / t_num);

  offset = b_offset + t_id * t_size;
  for (size_t i = offset; i < offset + t_size && i < b_offset + b_size && i < n;
       ++i)
    atomicAdd(&count[array[i]], 1);

  // wait until all threads have completed the couting phase.
  __syncthreads();

  // copy the block count into global memory. Each thread copies its portion to
  // the global memory.
  t_size = (t_num > MAX_VALUE ? 1 : MAX_VALUE / t_num);
  size_t t_offset = t_id * t_size;
  offset = b_id * MAX_VALUE + t_offset;

  if (offset + t_size <= (b_id + 1) * MAX_VALUE)
    memcpy(&output[offset], &count[t_offset], sizeof(int) * t_size);
}

std::vector<size_t> count_symbols(const std::string &str) {
  size_t n = str.size();
  int deviceCount = 0;
  cudaError_t error_id = cudaGetDeviceCount(&deviceCount);

  if (error_id != cudaSuccess || deviceCount == 0) {
    // If no GPU available, just run on CPU
    std::vector<size_t> counts(MAX_VALUE);
    for (auto c : str) {
      ++counts[static_cast<unsigned char>(c)];
    }

    return counts;
  
  } else {

    int *array = new int[n];
    for (size_t i = 0; i < n; ++i) {
      array[i] = static_cast<unsigned char>(str[i]);
    }

    int *d_array;
    int *d_output;
    cudaMalloc((void **)&d_array, sizeof(int) * n);
    cudaMalloc((void **)&d_output, sizeof(int) * BLOCKS * MAX_VALUE);

    cudaMemcpy(d_array, array, sizeof(int) * n, cudaMemcpyHostToDevice);
    cudaMemset(d_output, 0, sizeof(int) * BLOCKS * MAX_VALUE);

    count<<<BLOCKS, THREADS>>>(d_array, d_output, n);

    int output[BLOCKS * MAX_VALUE];
    cudaMemcpy(output, d_output, sizeof(int) * BLOCKS * MAX_VALUE,
               cudaMemcpyDeviceToHost);

    // output contains chunks of counts
    std::vector<size_t> counts(MAX_VALUE);
    for (size_t i = 0; i < MAX_VALUE; ++i) {
      for (size_t j = 0; j < BLOCKS; ++j) {
        counts[i] += output[j * MAX_VALUE + i];
      }
    }

    cudaFree(d_array);
    cudaFree(d_output);

    delete[] array;

    return counts;
  }
}
