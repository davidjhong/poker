#include "gtest/gtest.h"

TEST(testUnit, testHello) {
    EXPECT_EQ("hello world", "hello world");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}