#include "gtest/gtest.h"
#include "../include/Player.h"
#include "../include/Card.h"
#include "../include/handRank.h"
#include "../include/Pot.h"
#include "../include/Deck.h"
#include "../include/Hand.h"

// Player Test Suite

TEST(playerTests, playerInitTest) {
  Player* testPlayer = new Player("Jason", 100);
  EXPECT_EQ(testPlayer->getBalance(), 100);
  EXPECT_EQ(testPlayer->getName(), "Jason");
}

// Card Test Suite

TEST(CardTests, typicalCardTest) {
  Card* testCard = new Card(3, "Spades", "Three of Spades");

  EXPECT_EQ(testCard->getRank(), 3);
  EXPECT_EQ(testCard->getSuit(), "Spades");
  EXPECT_EQ(testCard->getName(), "Three of Spades");
}

class StubHand {
    private: 
      vector<Card*> hand;
    public:
      StubHand(vector<Card*> testCards) {

        for (int i = 0; i < testCards.size(); i++)
        {
          hand.push_back(testCards[i]);
        }
      }
      vector<Card*> getCurrentHand() const {
        return this->hand;
      }
};

TEST(HandRankTests, hasHighCardTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades");
    Card* card2 = new Card(5, "Spades", "Five of Spades");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts");
    Card* card4 = new Card(9, "Spades", "Nine of Spades");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 50);
}


TEST(HandRankTests, hasPairTest) {

    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades");
    Card* card2 = new Card(5, "Spades", "Five of Spades");
    Card* card3 = new Card(6, "Hearts", "Six of Hearts");
    Card* card4 = new Card(5, "Spades", "Five of Spades");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 100);
}

TEST(HandRankTests, hasTwoPairTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades");
    Card* card2 = new Card(5, "Spades", "Five of Spades");
    Card* card3 = new Card(1, "Hearts", "One of Hearts");
    Card* card4 = new Card(5, "Spades", "Five of Spades");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 150);
}



// Pot Test Suite

TEST(PotTest, addToPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);
}

// Deck Test Suite

TEST(DeckTests, constructorTest) {
  Deck* testDeck = new Deck();

  Card* firstCard = testDeck->nextCard();
  Card* secondCard = testDeck->nextCard();
  Card* thirdCard = testDeck->nextCard();
  Card* fourthCard = testDeck->nextCard();
  Card* fifthCard = testDeck->nextCard();

  EXPECT_EQ(firstCard->getName(), "Ace of Diamonds");
  EXPECT_EQ(secondCard->getName(), "Ace of Hearts");
  EXPECT_EQ(thirdCard->getName(), "Ace of Clovers");
  EXPECT_EQ(fourthCard->getName(), "Ace of Spades");
  EXPECT_EQ(fifthCard->getName(), "Two of Diamonds");

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
}


// Hand Test Suite

TEST(handTests, emptyHandTest)
{
  Hand* testHand = new Hand();

  vector<string> cards;
  EXPECT_EQ(testHand->getCardNames(), cards);
}

TEST(handTests, getHandFilledHandTest)
{
  Hand* testHand = new Hand();
  
  Card* card1 = new Card(1, "Spades", "Ace of Spades");
  Card* card2 = new Card(2, "Spades", "Two of Spades");
  Card* card3 = new Card(3, "Diamonds", "Three of Diamonds");
  Card* card4 = new Card(4, "Hearts", "Four of Hearts");

  testHand->addCard(card1);
  testHand->addCard(card2);
  testHand->addCard(card3);
  testHand->addCard(card4);

  vector<Card*> cards = {card1, card2, card3, card4};
  EXPECT_EQ(testHand->getHand(), cards);
}

TEST(handTests, expectDeathMaxHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades");
  Card* card2 = new Card(5, "Spades", "Five of Spades");
  Card* card3 = new Card(10, "Spades", "Ten of Spades");
  Card* card4 = new Card(4, "Spades", "Four of Spades");
  Card* card5 = new Card(2, "Spades", "Two of Spades");
  Card* card6 = new Card(1, "Spades", "One of Spades");
  Card* card7 = new Card(11, "Spades", "Jack of Spades");
  
  testHand->addCard(card1);
  testHand->addCard(card2);
  testHand->addCard(card3);
  testHand->addCard(card4);
  testHand->addCard(card5);
  testHand->addCard(card6);
  testHand->addCard(card7);

  Card* overflowCard = new Card(5, "Hearts", "Five of Hearts");

  EXPECT_DEATH(testHand->addCard(overflowCard), "Tried adding card to a hand of 7 cards, which is the max");
}

TEST(handTests, ThreeCardHandNameTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades");
  Card* card2 = new Card(5, "Spades", "Five of Spades");
  Card* card3 = new Card(10, "Spades", "Ten of Spades");

  testHand->addCard(card1);
  testHand->addCard(card2);
  testHand->addCard(card3);

  // test->Hand
  vector<string> cards;
  cards.push_back(card1->getName());
  cards.push_back(card2->getName());
  cards.push_back(card3->getName());

  EXPECT_EQ(testHand->getCardNames(), cards);
}

TEST(handTests, clearHandTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades");
  Card* card2 = new Card(5, "Spades", "Five of Spades");
  Card* card3 = new Card(10, "Spades", "Ten of Spades");

  testHand->addCard(card1);
  testHand->addCard(card2);
  testHand->addCard(card3);

  vector<Card*> cards;

  testHand->clearHand();

  EXPECT_EQ(testHand->getHand(), cards);
}

TEST(handTests, getStrengthTest)
{
  Hand* testHand = new Hand();

  Card* card1 = new Card(3, "Spades", "Three of Spades");
  Card* card2 = new Card(5, "Spades", "Five of Spades");
  Card* card3 = new Card(10, "Spades", "Ten of Spades");

  testHand->addCard(card1);
  testHand->addCard(card2);
  testHand->addCard(card3);

  testHand->calculateStrength();
  EXPECT_EQ(testHand->getStrength(), 50);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}