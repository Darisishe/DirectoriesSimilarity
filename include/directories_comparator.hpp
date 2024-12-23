#pragma once
#include <similarity_entry/entry.h>
#include <file/file.h>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <fstream>

#include <tbb/parallel_for.h>
#include <mutex>

// return value of calculateSimilarities:
struct SimilarityInfo {
  std::vector<SimilarityEntry> similar;
  std::vector<std::string> unique_in_dir1;
  std::vector<std::string> unique_in_dir2;
};

template <typename Metric>
class DirectoriesComparator {
 public:
  DirectoriesComparator(const std::string& dir1, const std::string& dir2, double percentage);
  
  SimilarityInfo calculateSimilarities();

 private:
  static std::vector<File> readDirectory(const std::string& dir);

 private:
  const std::vector<File> directory1_;
  const std::vector<File> directory2_;
  const double percentage_;
};

template<typename Metric>
DirectoriesComparator<Metric>::DirectoriesComparator(const std::string &dir1,
                                             const std::string &dir2,
                                             double percentage)
    : percentage_(percentage),
      directory1_(readDirectory(dir1)), directory2_(readDirectory(dir2)) {}


template<typename Metric>
std::vector<File> DirectoriesComparator<Metric>::readDirectory(const std::string &dir) {
  std::vector<File> directory;
  for (const auto &entry : std::filesystem::directory_iterator(dir)) {
    std::string path = entry.path();
    // filename without the rest of path:
    std::string name = path.substr(path.find_last_of("/\\") + 1);

    // getting file content:
    std::ifstream input_file(path, std::ios_base::binary);
    std::ostringstream str_stream;
    str_stream << input_file.rdbuf();

    directory.emplace_back(dir + "/" + name, str_stream.str());
  }
  return directory;
}


template<typename Metric>
SimilarityInfo DirectoriesComparator<Metric>::calculateSimilarities() {
  std::vector<bool> is_unique_dir1(directory1_.size(), true);
  std::vector<bool> is_unique_dir2(directory2_.size(), true);

  SimilarityInfo info;
  
  std::mutex lock;
  // Parallelize over files in first directory
  tbb::parallel_for(tbb::blocked_range<int>(0, directory1_.size()),
                    [&](tbb::blocked_range<int> r) {
                      for (int i = r.begin(); i < r.end(); ++i) {
                        for (int j = 0; j < directory2_.size(); ++j) {
                          const File &file1 = directory1_[i];
                          const File &file2 = directory2_[j];

                          double similarity = Metric().similarity(
                              file1.getContent(), file2.getContent());

                          if (similarity >= percentage_) {
                            std::lock_guard guard(lock);

                            is_unique_dir1[i] = false;
                            is_unique_dir2[j] = false;

                            info.similar.emplace_back(
                                file1.getName(), file2.getName(), similarity);
                            
                          }
                        }
                      }
                    }

  );

  // let's sort info.similar, so equal pairs will be first in vector:
  std::sort(info.similar.begin(), info.similar.end(),
            [](const SimilarityEntry &a, const SimilarityEntry &b) {
              return a.getSimilarity() > b.getSimilarity();
            });

  // now let's build 2 vectors of unique files in each directory:
  for (int i = 0; i < directory1_.size(); ++i) {
    if (is_unique_dir1[i])
      info.unique_in_dir1.push_back(directory1_[i].getName());
  }

  for (int i = 0; i < directory2_.size(); ++i) {
    if (is_unique_dir2[i])
      info.unique_in_dir2.push_back(directory2_[i].getName());
  }

  return info;
}