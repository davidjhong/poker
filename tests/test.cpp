#include "gtest/gtest.h"
#include "../include/Player.h"
#include "../include/Card.h"
#include "../include/handRank.h"
#include "../include/Pot.h"
#include "../include/Deck.h"

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



TEST(PotTest, addToPotTest) {
  Pot *testPot = new Pot();
  EXPECT_EQ(testPot->getPot(), 0);
  testPot->addToPot(100);
  EXPECT_EQ(testPot->getPot(), 100);
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}