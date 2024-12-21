#pragma once
#include <similarity_entry/entry.h>
#include <metric/metric.h>
#include <file/file.h>
#include <vector>


// return value of calculateSimilarities:
struct SimilarityInfo {
  std::vector<SimilarityEntry> similar;
  std::vector<std::string> unique_in_dir1;
  std::vector<std::string> unique_in_dir2;
};

class DirectoriesComparator {
 public:
  DirectoriesComparator(const std::string& dir1, const std::string& dir2, double percentage, const IStringMetric& metric);
  
  SimilarityInfo calculateSimilarities();

 private:
  static std::vector<File> readDirectory(const std::string& dir);

 private:
  const IStringMetric& metric_;
  const std::vector<File> directory1_;
  const std::vector<File> directory2_;
  const double percentage_;
};