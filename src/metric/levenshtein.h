#pragma once
#include <metric/metric.h>


class LevenshteinMetric : public IStringMetric {
 public:
  LevenshteinMetric(int insertCost, int deleteCost, int replaceCost);
  LevenshteinMetric();

  double similarity(const std::string& s1, const std::string& s2) const override;


 private:
  int insert_cost_ = 1;
  int delete_cost_ = 1;
  int replace_cost_ = 1;
};
