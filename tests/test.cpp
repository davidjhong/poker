#include "gtest/gtest.h"
#include "../include/Card.h"
#include "../include/handRank.h"

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



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}