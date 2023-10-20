#pragma once
#include <string>


// interface for class, that measures difference between strings
// (implement this interface, if you want to use other metric then Levenshtein's)
class IStringDistance {
 public:
  virtual ~IStringDistance() = default;
  virtual double similarity(const std::string& s1, const std::string& s2) const = 0; // returns percentage
};