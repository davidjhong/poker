#include "gtest/gtest.h"
#include "../header/Pot.h"

// Pot Test Suite

TEST(PotTest, potConstructorTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  delete testPot;
}

TEST(PotTest, setHighestBetTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  testPot->setHighestBet(300);
  EXPECT_EQ(testPot->getHighestBet(), 300);

  delete testPot;
}

TEST(PotTest, resetPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);

  testPot->setHighestBet(300);
  EXPECT_EQ(testPot->getHighestBet(), 300);

  testPot->resetPot();

  ASSERT_EQ(testPot->getHighestBet(), 0);
  ASSERT_EQ(testPot->getPot(), 0);

  delete testPot;
}

TEST(PotTest, addToPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);

  delete testPot;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
