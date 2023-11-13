#include "gtest/gtest.h"
#include "../include/Card.h"
#include "../include/Pot.h"

TEST(CardTests, typicalCardTest) {
    Card* testCard = new Card(3, "Spades", "Three of Spades");

    EXPECT_EQ(testCard->getRank(), 3);
    EXPECT_EQ(testCard->getSuit(), "Spades");
    EXPECT_EQ(testCard->getName(), "Three of Spades");
}

TEST(PotTest, addToPotTest) {
  Pot *testPot;
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}