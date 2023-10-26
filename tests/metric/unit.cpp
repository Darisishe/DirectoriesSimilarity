#include <gtest/gtest.h>
#include <metric/levenshtein.h>
#include <metric/LCS.h>

TEST(StringMetricTestSuite, LevenshteinTest) {
  LevenshteinMetric metric;
  EXPECT_NEAR(metric.similarity("111", "22222"), 0, 1e-7);
  EXPECT_NEAR(metric.similarity("ABA", "B"), 100/3.0, 1e-7);
  EXPECT_NEAR(metric.similarity("AAAA", "A"), 25.0, 1e-7);
}

TEST(StringMetricTestSuite, LCSTest) {
  LCSMetric metric;
  EXPECT_NEAR(metric.similarity("111", "22222"), 0, 1e-7);
  EXPECT_NEAR(metric.similarity("ABA", "B"), 100/3.0, 1e-7);
  EXPECT_NEAR(metric.similarity("AAAA", "A"), 25.0, 1e-7);
  EXPECT_NEAR(metric.similarity("subsub|subsubsub|subsupsu","supsup(subsub)"), 24.0, 1e-7);
}
