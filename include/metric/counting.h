
#pragma once
#include <string>

// Just a metric that counts symbols
// And calculates similarity based on the distribution of chars counts
// So this metric don't care about characters order
// And almost always not accurate at all
// But much more faster due to ease of algo and use of CUDA
class CountingMetric {
 public:
  CountingMetric();

  double similarity(const std::string& s1, const std::string& s2) const; // returns percentage
};
