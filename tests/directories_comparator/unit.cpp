#include <gtest/gtest.h>
#include <directories_comparator.hpp>
#include <metric/levenshtein.h>
#include <metric/LCS.h>
#include <metric/counting.h>

template<typename Metric>
static void equal_files_test() {
  DirectoriesComparator<Metric> comparator("../testing_directories/test_dir1", "../testing_directories/test_dir2", 0);
  auto result = comparator.calculateSimilarities();
  ASSERT_EQ(result.similar[0].to_string(), "../testing_directories/test_dir1/aaa - ../testing_directories/test_dir2/bbb");
}

TEST(ComparatorTestSuite, EqualFilesTestLevenshtein) {
  equal_files_test<LevenshteinMetric>();
}

TEST(ComparatorTestSuite, EqualFilesTestLCS) {
  equal_files_test<LCSMetric>();
}

TEST(ComparatorTestSuite, EqualFilesTestCounting) {
  equal_files_test<CountingMetric>();
}

template<typename Metric>
static void unique_files_test() {
  DirectoriesComparator<Metric> comparator("../testing_directories/test_dir3", "../testing_directories/test_dir4", 20);
  auto result = comparator.calculateSimilarities();

  // similarity of files should be less then 20%
  ASSERT_EQ(result.unique_in_dir1.size(), 1);
  ASSERT_EQ(result.unique_in_dir2.size(), 1);
  ASSERT_EQ(result.unique_in_dir1[0], "../testing_directories/test_dir3/ccc");
  ASSERT_EQ(result.unique_in_dir2[0], "../testing_directories/test_dir4/ccc");
}

TEST(ComparatorTestSuite, UniqueFilesTestLevenshtein) {
  unique_files_test<LevenshteinMetric>();
}

TEST(ComparatorTestSuite, UniqueFilesTestLCS) {
  unique_files_test<LCSMetric>();
}

TEST(ComparatorTestSuite, UniqueFilesTestCounting) {
  unique_files_test<CountingMetric>();
}

