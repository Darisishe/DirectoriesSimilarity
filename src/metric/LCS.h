#pragma once
#include <metric/metric.h>
#include <vector>


// Metric based on longest common substring
// Uses string hashes
// Asymptotics O(nlog^2n)
class LCSMetric : public IStringMetric {
 public:
  LCSMetric(long long p, long long mod);

  LCSMetric();

  double similarity(const std::string& first, const std::string& second) const;

 private:
  bool check_for_k_substring(const std::vector<long long>& first_prefix_hash, 
                             const std::vector<long long>& second_prefix_hash, size_t k) const;
                             
  std::vector<long long> prefix_hash(const std::string& s) const;

  long long substring_hash(const std::vector<long long>& prefix_hash, 
                           size_t i, size_t j, size_t norm_pow) const;

 private:
  const long long p_ = 263;
  const long long mod_ = 1e9 + 7;
  mutable std::vector<long long> p_pow_ = std::vector<long long>(1, 1);
};