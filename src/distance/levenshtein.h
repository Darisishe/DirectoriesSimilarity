#pragma once
#include <distance/distance.h>


class LevenshteinDistance : public IStringDistance {
 public:
  LevenshteinDistance(int insertCost, int deleteCost, int replaceCost);
  LevenshteinDistance();

  double similarity(const std::string& s1, const std::string& s2) const override;


 private:
  int insert_cost_ = 1;
  int delete_cost_ = 1;
  int replace_cost_ = 1;
};
