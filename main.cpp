#include "distance/levenshtein.h"
#include <iostream>
#include <directories_comparator.h>

int main() {
  std::cout << LevenshteinDistance().similarity("aboba", "abob") << std::endl;
  std::string dir1, dir2;
  double percentage;
  std::cout << "Enter first directory: ";
  std::cin >> dir1;

  std::cout << "Enter second directory: ";
  std::cin >> dir2;

  std::cout << "Enter percentage of similarity: ";
  std::cin >> percentage;

  LevenshteinDistance metric;
  DirectoriesComparator comparator(dir1, dir2, percentage, metric);
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
  
}