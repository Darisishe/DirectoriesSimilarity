#include <gtest/gtest.h>
#include <graph/graph.h>
#include <iostream>

TEST(GraphTestSuite, ProducerTest) {
  EXPECT_EQ("Hello World!", Graph::Produce());
}
