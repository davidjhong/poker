#include "gtest/gtest.h"
#include "../include/Card.h"
#include "../include/handRank.h"

TEST(CardTests, typicalCardTest) {
    Card* testCard = new Card(3, "Spades", "Three of Spades");

    EXPECT_EQ(testCard->getRank(), 3);
    EXPECT_EQ(testCard->getSuit(), "Spades");
    EXPECT_EQ(testCard->getName(), "Three of Spades");
}

class stubHand {
    private: 
      vector<Card*> hand;
      handRank handRanker;
    public:
      stubHand() {
        Card* card1 = new Card(1, "Spades", "One of Spades")
        Card* card2 = new Card(2, "Spades", "Two of Spades")
        Card* card3 = new Card(5, "Hearts", "Five of Hearts")
        Card* card4 = new Card(5, "Spades", "Five of Spades")
        
        hand.push_back(card1);
        hand.push_back(card2);
        hand.push_back(card3);
        hand.push_back(card4);  
      }
};

TEST(HandRankTests, hasPairTest) {
    stubHand testHand = new stubHand();
    
    EXPECT_EQ(testHand.handRanker.getFinalRank(), 100);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}