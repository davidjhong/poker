#include "gtest/gtest.h"
#include "../header/Card.h"
#include "../header/Deck.h"


// Deck Test Suite

TEST(CardTests, constructorTest) {
  Card* heartCard = new Card(5, "Hearts", "Five of Hearts", "♥");
  Card* diamondCard = new Card(5, "Diamonds", "Five of Diamonds", "♦");

  EXPECT_EQ(heartCard->getRank(), 5);
  EXPECT_EQ(diamondCard->getRank(), 5);
  
  EXPECT_EQ(heartCard->getSuit(), "Hearts");
  EXPECT_EQ(diamondCard->getSuit(), "Diamonds");
  
  EXPECT_EQ(heartCard->getSuitSymbol(), "♥");
  EXPECT_EQ(diamondCard->getSuitSymbol(), "♦");

  EXPECT_EQ(heartCard->getName(), "Five of Hearts");
  EXPECT_EQ(diamondCard->getName(), "Five of Diamonds");
  
}

TEST(CardTests, largerRankTest) {
  Card* heartCard = new Card(11, "Hearts", "Jack of Hearts", "♥");
  Card* diamondCard = new Card(12, "Diamonds", "Queen of Diamonds", "♦");

  EXPECT_EQ(heartCard->getRank(), 11);
  EXPECT_EQ(diamondCard->getRank(), 12);
  
  EXPECT_EQ(heartCard->getSuit(), "Hearts");
  EXPECT_EQ(diamondCard->getSuit(), "Diamonds");
  
  EXPECT_EQ(heartCard->getSuitSymbol(), "♥");
  EXPECT_EQ(diamondCard->getSuitSymbol(), "♦");

  EXPECT_EQ(heartCard->getName(), "Jack of Hearts");
  EXPECT_EQ(diamondCard->getName(), "Queen of Diamonds");
  
}

TEST(DeckTests, constructorTest) {
  Deck* testDeck = new Deck();

  Card* firstCard = testDeck->nextCard();
  Card* secondCard = testDeck->nextCard();
  Card* thirdCard = testDeck->nextCard();
  Card* fourthCard = testDeck->nextCard();
  Card* fifthCard = testDeck->nextCard();

  EXPECT_EQ(firstCard->getName(), "Ace of Diamonds");
  EXPECT_EQ(secondCard->getName(), "Ace of Hearts");
  EXPECT_EQ(thirdCard->getName(), "Ace of Clubs");
  EXPECT_EQ(fourthCard->getName(), "Ace of Spades");
  EXPECT_EQ(fifthCard->getName(), "Two of Diamonds");
  
  delete testDeck;

}

TEST(DeckTests, shuffleDeckTest) {
  Deck* testDeck = new Deck();

  testDeck->shuffleDeck(false);
  
  Card* firstCard = testDeck->nextCard();
  Card* secondCard = testDeck->nextCard();
  Card* thirdCard = testDeck->nextCard();
  Card* fourthCard = testDeck->nextCard();
  Card* fifthCard = testDeck->nextCard();

  EXPECT_EQ(firstCard->getName(), "Two of Diamonds");
  EXPECT_EQ(secondCard->getName(), "King of Spades");
  EXPECT_EQ(thirdCard->getName(), "Three of Spades");
  EXPECT_EQ(fourthCard->getName(), "Four of Spades");
  EXPECT_EQ(fifthCard->getName(), "Seven of Diamonds");

  delete testDeck;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
