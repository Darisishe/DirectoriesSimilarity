#include <distance/levenshtein.h>
#include <vector>
#include <algorithm>

LevenshteinDistance::LevenshteinDistance(int i, int d, int r)
  : insert_cost_(i), delete_cost_(d), replace_cost_(r) {
}

LevenshteinDistance::LevenshteinDistance() {

}

double LevenshteinDistance::similarity(const std::string& first, const std::string& second) const { 
  size_t n = first.size();
  size_t m = second.size();

  std::vector<int> cur_distance(m + 1);
  cur_distance[0] = 0;
  for (int j = 1; j <= m; ++j)
    cur_distance[j] = cur_distance[j - 1] + insert_cost_;

  for (int i = 1; i <= n; ++i) {
     std::vector<int> prev_distance = cur_distance;
     cur_distance[0] = prev_distance[0] + delete_cost_;

    for (int j = 1; j <= m; ++j) {
      if (first[i - 1] != second[j - 1]) {
        cur_distance[j] = std::min({prev_distance[j] + delete_cost_,
                                    cur_distance[j - 1] + insert_cost_,
                                    prev_distance[j - 1] + replace_cost_});
      } else {
        cur_distance[j] = prev_distance[j - 1];
      }
     }
  }

  
  return 100 - 100 * static_cast<double>(cur_distance[m]) / std::max(n, m); 
}
