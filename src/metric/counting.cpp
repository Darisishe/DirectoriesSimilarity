#include <metric/counting.h>
#include <vector>
#include <algorithm>

std::vector<size_t> count_symbols(const std::string& str);

CountingMetric::CountingMetric() {

}

double CountingMetric::similarity(const std::string& first, const std::string& second) const {

    std::vector<size_t> chars_counts_first = count_symbols(first);
    std::vector<size_t> chars_counts_second = count_symbols(second);

    double sum = 0;
    for (size_t i = 0; i < 256; ++i) {
        long long diff = (long long) chars_counts_first[i] - (long long) chars_counts_second[i];
        sum += std::abs(diff); 
    }

    return std::max(0.0, 100 - 100 * sum / std::max(first.size(), second.size()));
}