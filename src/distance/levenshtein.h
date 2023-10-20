#pragma once
#include <distance/distance.h>


class LevenshteinDistance : public IStringDistance {
 public:
  LevenshteinDistance(int insertCost, int deleteCost, int replaceCost);
  LevenshteinDistance();

  double similarity(const std::string& s1, const std::string& s2) const override;


 private:
  int insertCost_ = 1;
  int deleteCost_ = 1;
  int replaceCost_ = 1;
};