#pragma once
#include "distance/distance.h"
#include <file/file.h>


class SimilarityEntry {
 public:
  SimilarityEntry(const std::string& file1, const std::string& file2, double similarity);
  std::string to_string() const;
  double getSimilarity() const;
  
 private:
  std::string file1_;
  std::string file2_;
  double similarity_;
};