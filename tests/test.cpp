#include "gtest/gtest.h"
#include "../include/Player.h"
#include "../include/Card.h"

TEST(playerTests, playerInitTest) {
  Player* testPlayer = new Player("Jason", 100);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
}

TEST(CardTests, typicalCardTest) {
    Card* testCard = new Card(3, "Spades", "Three of Spades");

    EXPECT_EQ(testCard->getRank(), 3);
    EXPECT_EQ(testCard->getSuit(), "Spades");
    EXPECT_EQ(testCard->getName(), "Three of Spades");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}