#pragma once
#include <string>
#include <vector>


// Metric based on longest common substring
// Uses string hashes
// Asymptotics O(nlog^2n)
class LCSMetric {
 public:

  LCSMetric();

  double similarity(const std::string& first, const std::string& second) const; // returns percentage

 private:
  bool check_for_k_substring(const std::vector<unsigned long long>& first_prefix_hash, 
                             const std::vector<unsigned long long>& second_prefix_hash, size_t k) const;
                             
  std::vector<unsigned long long> prefix_hash(const std::string& s) const;

  unsigned long long substring_hash(const std::vector<unsigned long long>& prefix_hash, 
                           size_t i, size_t j, size_t norm_pow) const;

 private:
  const unsigned long long p_ = 263;
  mutable std::vector<unsigned long long> p_pow_ = std::vector<unsigned long long>(1, 1);
};