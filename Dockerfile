FROM nvidia/cuda:11.8.0-devel-ubuntu20.04

ENV DEBIAN_FRONTEND=noninteractive
# Install dependencies
RUN apt-get update && \
    apt-get install -y build-essential unzip git cmake g++ libgtest-dev libtbb-dev && \
    apt-get clean

# Set working directory
WORKDIR /app

# Copy source files to the container
COPY . /app

# Run cmake and make
RUN cmake -S . -B build && cmake --build build

CMD ["/app/run_example.sh"]
