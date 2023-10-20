#include <distance/levenshtein.h>
#include <vector>
#include <algorithm>

LevenshteinDistance::LevenshteinDistance(int i, int d, int r)
  : insertCost_(i), deleteCost_(d), replaceCost_(r) {
}

LevenshteinDistance::LevenshteinDistance() {

}

double LevenshteinDistance::similarity(const std::string& first, const std::string& second) const { 
  size_t n = first.size();
  size_t m = second.size();
  std::vector<std::vector<int>> distance(n, std::vector<int>(m)); 
  distance[0][0] = 0;
 
  for (int j = 1; j < m; ++j)
    distance[0][j] = distance[0][j - 1] + insertCost_;

  for (int i = 1; i < n; ++i)
    distance[i][0] = distance[i - 1][0] + deleteCost_;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (first[i] != second[j]) {
        distance[i][j] = std::min({distance[i - 1][j] + deleteCost_,
                                  distance[i][j - 1] + insertCost_,
                                  distance[i - 1][j - 1] + replaceCost_});
      } else {
        distance[i][j] = distance[i - 1][j - 1];
      }
    }
  }

  return 100 - 100 * static_cast<double>(distance[n - 1][m - 1]) / std::max(n, m); 
}