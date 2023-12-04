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



// Hand Test Suite

TEST(handTests, emptyHandTest)
{
  Hand* testHand = new Hand();

  vector<string> cards;
  EXPECT_EQ(testHand->getCardNames(), cards);
}

TEST(handTests, handConstructorTest) {
  Card* jack = new Card(11, "Spades", "Jack of Spades", "♠");
  Card* queen = new Card(12, "Heart", "Queen of Hearts", "♥");
  vector<Card*> jackQueen = {jack, queen};



  Hand *testHand = new Hand(jackQueen);

  EXPECT_EQ(testHand->getCard(0), jack);
  EXPECT_EQ(testHand->getCard(1), queen);
}

TEST(handTests, getHandFilledHandTest)
{
  Hand* testHand = new Hand();
  
  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(2, "Spades", "Two of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> cards = {card1, card2};
  EXPECT_EQ(testHand->getHand(), cards);
}

TEST(handTests, expectDeathMaxHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
  
  testHand->addCard(card1);
  testHand->addCard(card2);


  Card* overflowCard = new Card(5, "Hearts", "Five of Hearts", "♥");

  // EXPECT_DEATH(testHand->addCard(overflowCard), "Tried adding card to a hand of 2 cards, which is the max");
}

TEST(handTests, ThreeCardHandNameTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  // test->Hand
  vector<string> cards;
  cards.push_back(card1->getName());
  cards.push_back(card2->getName());

  EXPECT_EQ(testHand->getCardNames(), cards);
}

TEST(handTests, clearHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> cards;

  testHand->clearHand();

  EXPECT_EQ(testHand->getHand(), cards);
}

TEST(handTests, getStrengthTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades", "♠");
  Card* card2 = new Card(10, "Spades", "Ten of Spades", "♠");

  testHand->addCard(card1);
  testHand->addCard(card2);

  vector<Card*> emptyCommunityCards;

  testHand->calculateStrength(emptyCommunityCards);
  EXPECT_EQ(testHand->getStrength(), 10);


}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
