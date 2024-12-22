#pragma once
#include <string>


class LevenshteinMetric {
 public:
  LevenshteinMetric(int insertCost, int deleteCost, int replaceCost);
  LevenshteinMetric();

  double similarity(const std::string& s1, const std::string& s2) const; // returns percentage


 private:
  int insert_cost_ = 1;
  int delete_cost_ = 1;
  int replace_cost_ = 1;
};
