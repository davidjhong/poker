#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Deck.h"
#include "../header/Hand.h"
#include "../header/Settings.h"
#include "../header/Display.h"
#include "../header/RoundHandler.h"

// Player Test Suite

TEST(playerTests, playerConstructorTest) {
  Player* testPlayer = new Player("Jason", 100, false);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
}

TEST(playerTests, playerBalanceTest) {
  Player* testPlayer = new Player("Jason", 1000, false);

  testPlayer->setBalance(800);
  EXPECT_EQ(testPlayer->getBalance(), 800);

  testPlayer->addToBalance(500);
  EXPECT_EQ(testPlayer->getBalance(), 1300);
}

TEST(playerTests, playerHandConstructorTest) {
  Player* testPlayer = new Player("Kevin", 0, false);
  EXPECT_EQ(testPlayer->getBalance(), 0);
  EXPECT_EQ(testPlayer->getHand()->getStrength(), 0);
}

TEST(playerTests, isPlayingTest) {
  Player* testPlayer = new Player("Kevin", 0, false);
  EXPECT_TRUE(testPlayer->getIsPlaying());

  testPlayer->setIsPlaying(false);
  EXPECT_FALSE(testPlayer->getIsPlaying());
}

TEST(playerTests, currentBetTests) {
  Player* testPlayer = new Player("Kevin", 500, false);

  EXPECT_EQ(testPlayer->getBalance(), 500);
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);
  
  testPlayer->setCurrentBet(250);
  EXPECT_EQ(testPlayer->getCurrentBet(), 250);

  testPlayer->clearCurrentBet();
  EXPECT_EQ(testPlayer->getCurrentBet(), 0);
  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
