#include "gtest/gtest.h"
#include "../include/Player.h"

TEST(playerTests, playerInitTest) {
  Player* testPlayer = new Player("Jason", 100);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}