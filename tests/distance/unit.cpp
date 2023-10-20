#include <gtest/gtest.h>
#include <distance/levenshtein.h>

TEST(StringDistanceTestSuite, LevenshteinTest) {
  LevenshteinDistance metric;
  EXPECT_NEAR(metric.similarity("111", "22222"), 0, 1e-7);
  EXPECT_NEAR(metric.similarity("ABA", "B"), 100/3.0, 1e-7);
  EXPECT_NEAR(metric.similarity("AAAA", "A"), 25.0, 1e-7);
}
