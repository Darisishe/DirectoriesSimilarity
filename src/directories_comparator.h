#pragma once
#include <similarity_entry/entry.h>
#include <distance/levenshtein.h>
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
  DirectoriesComparator(const std::string& dir1, const std::string& dir2, double percentage, const IStringDistance& metric);
  
  SimilarityInfo calculateSimilarities();

 private:
  static std::vector<File> readDirectory(const std::string& dir);

 private:
  const IStringDistance& metric_;
  std::vector<File> directory1_;
  std::vector<File> directory2_;
  double percentage_;
};