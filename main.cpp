#include <iostream>
#include <metric/levenshtein.h>
#include <metric/LCS.h>
#include <metric/counting.h>
#include <directories_comparator.hpp>

int main() {
  std::string dir1, dir2;
  double percentage;

  std::cout << "Enter first directory: ";
  std::cin >> dir1;

  std::cout << "Enter second directory: ";
  std::cin >> dir2;

  std::cout << "Enter percentage of similarity: ";
  std::cin >> percentage; 

  // Use LevenshteinMetric for better precision
  
  // Use LCSMetric for better performance time 

  // Use CountingMetric if you don't care much about precision (or ordering of symbols)
  // and want to have a very good speed performance

  DirectoriesComparator<CountingMetric> comparator(dir1, dir2, percentage);
  SimilarityInfo info = comparator.calculateSimilarities();
  
  std::cout << "\nSimilar files:\n";
  for (auto& entry : info.similar) {
    std::cout << entry.to_string() << "\n";
  }

  std::cout << "\nUnique files in " + dir1 + ":\n";
  for (auto& file : info.unique_in_dir1) {
    std::cout << file << "\n";
  }

  std::cout << "\nUnique files in " + dir2 + ":\n";
  for (auto& file : info.unique_in_dir2) {
    std::cout << file << "\n";
  }
  
  return 0;
}
