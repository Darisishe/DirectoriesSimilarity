#include <metric/LCS.h>
#include <algorithm>
#include <set>

LCSMetric::LCSMetric() {

}

double LCSMetric::similarity(const std::string& first, const std::string& second) const {
  // add new elements to p_pow if needed
  p_pow_.reserve(std::max(first.size(), second.size()));
  for (size_t i = p_pow_.size(); i < std::max(first.size(), second.size()); ++i) {
    p_pow_.push_back(p_pow_[i - 1] * p_);
  }

  auto first_prefix_hash = prefix_hash(first);
  auto second_prefix_hash = prefix_hash(second);

  size_t max_len = std::min(first.size(), second.size());
  size_t left = 0;
  size_t right = max_len + 1;
  while (right - left > 1) {
    size_t mid = (left + right) / 2;
    if (check_for_k_substring(first_prefix_hash, second_prefix_hash, mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  
  return 100 * static_cast<double>(left) / std::max(first.size(), second.size());
}

bool LCSMetric::check_for_k_substring(const std::vector<unsigned long long>& first_prefix_hash, 
                                      const std::vector<unsigned long long>& second_prefix_hash,
                                      size_t k) const {
  std::set<unsigned long long> substring_hashes; 
  size_t pow = std::max(first_prefix_hash.size(), second_prefix_hash.size()) - 1;

  // add all substrings of size k of first string to set
  for (size_t i = 0; i < first_prefix_hash.size() - k + 1; ++i) {
    unsigned long long hash = substring_hash(first_prefix_hash, i, i + k - 1, pow);
    substring_hashes.insert(hash);
  }

  // check if any k-substring in second string present in set
  for (size_t i = 0; i < second_prefix_hash.size() - k + 1; ++i) {
    unsigned long long hash = substring_hash(second_prefix_hash, i, i + k - 1, pow);
    if (substring_hashes.count(hash)) {
      return true;
    }
  }

  return false;
}

std::vector<unsigned long long> LCSMetric::prefix_hash(const std::string& s) const {
  std::vector<unsigned long long> prefix_hash(s.size());
  for (size_t i = 0; i < s.size(); ++i) {
    prefix_hash[i] = (p_pow_[i] * static_cast<unsigned char>(s[i]));
    if (i > 0) {
      prefix_hash[i] += prefix_hash[i - 1];
    }
  }
  return prefix_hash;
}

unsigned long long LCSMetric::substring_hash(const std::vector<unsigned long long>& prefix_hash, 
                                    size_t i, size_t j, size_t norm_pow) const {
    unsigned long long hash = prefix_hash[j];
    if (i > 0)
      hash -= prefix_hash[i - 1];
    hash *= p_pow_[norm_pow - i];
    return hash;
}