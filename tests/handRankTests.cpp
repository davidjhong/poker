#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Deck.h"
#include "../header/Hand.h"

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
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};

    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 10);
}


TEST(HandRankTests, hasPairTest) {
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 59);
}

TEST(HandRankTests, hasTwoPairTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card3 = new Card(1, "Hearts", "One of Hearts", "♥");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(8, "Spades", "Eight of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 105);
}

TEST(HandRankTests, hasTwoPairTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card3 = new Card(10, "Hearts", "Ten of Hearts", "♥");
    Card* card4 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 110);
}

TEST(HandRankTests, hasThreeOfKindTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(1, "Clubs", "One of Clubs", "♣");
    Card* card3 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(1, "Hearts", "One of Hearts", "♥");

    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 151);
}

TEST(HandRankTests, hasThreeOfKindTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(9, "Hearts", "Nine of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(10, "Spades", "Ten of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 155);
}

TEST(HandRankTests, hasStraightTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(1, "Spades", "One of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(3, "Hearts", "Three of Hearts", "♥");
    Card* card4 = new Card(4, "Spades", "Four of Spades", "♠");
    Card* card5 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 205);
}

TEST(HandRankTests, hasStraightTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(6, "Hearts", "Six of Hearts", "♥");
    Card* card3 = new Card(7, "Hearts", "Seven of Hearts", "♥");
    Card* card4 = new Card(8, "Clubs", "Eight of Clubs", "♣");
    Card* card5 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card6 = new Card(11, "Spades", "Jack of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 209);
}

TEST(HandRankTests, hasFullHouse) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 308);
}

TEST(HandRankTests, hasFullHouseTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(11, "Spades", "Jack of Spades", "♠");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    EXPECT_EQ(testHand->getStrength(), 307);
}

TEST(HandRankTests, hasFourOfKind) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(2, "Clubs", "Two of Clubs", "♣");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(2, "Diamonds", "Two of Diamonds", "♦");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(5, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 352);
}

TEST(HandRankTests, hasFourOfKindTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card2 = new Card(5, "Hearts", "Five of Hearts", "♥");
    Card* card3 = new Card(2, "Hearts", "Two of Hearts", "♥");
    Card* card4 = new Card(5, "Clubs", "Five of Clubs", "♣");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(5, "Diamonds", "Five of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 355);
}

TEST(HandRankTests, hasStraightFlushTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(3, "Spades", "Three of Spades", "♠");
    Card* card3 = new Card(4, "Spades", "Four of Spades", "♠");
    Card* card4 = new Card(5, "Spades", "Five of Spades", "♠");
    Card* card5 = new Card(6, "Spades", "Six of Spades", "♠");
    Card* card6 = new Card(8, "Spades", "Five of Spades", "♠");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 406);
}


TEST(HandRankTests, hasStraightFlushTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(5, "Diamonds", "Five of Diamonds", "♦");
    Card* card2 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
    Card* card3 = new Card(7, "Diamonds", "Seven of Diamonds", "♦");
    Card* card4 = new Card(8, "Diamonds", "Eight of Diamonds", "♦");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(9, "Diamonds", "Nine of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 409);
}


TEST(HandRankTests, hasRoyalFlushTest) {
    vector<Card*> testCards;
    Card* card1 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card2 = new Card(3, "Spades", "Three of Spades", "♠");
    Card* card3 = new Card(10, "Diamonds", "Ten of Diamonds", "♦");
    Card* card4 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
    Card* card5 = new Card(12, "Diamonds", "Queen of Diamonds", "♦");
    Card* card6 = new Card(13, "Diamonds", "King of Diamonds", "♦");
    Card* card7 = new Card(14, "Diamonds", "Ace of Diamonds", "♦");
    testCards.push_back(card1);
    testCards.push_back(card2);
    testCards.push_back(card3);
    testCards.push_back(card4);
    testCards.push_back(card5);
    testCards.push_back(card6);
    testCards.push_back(card7);

    StubHand* testHand = new StubHand(testCards);
    HandRank* handRanker = new HandRank();
    
    EXPECT_EQ(handRanker->getFinalRank(testHand->getCurrentHand()), 464);
}

TEST(HandRankTests, hasRoyalFlushTest2) { // Testing with real functions instead of stubhand
    Hand* testHand = new Hand();
    Card* card1 = new Card(9, "Spades", "Nine of Spades", "♠");
    Card* card2 = new Card(10, "Diamonds", "Ten of Diamonds", "♦");
    Card* card3 = new Card(11, "Diamonds", "Jack of Diamonds", "♦");
    Card* card4 = new Card(12, "Diamonds", "Queen of Diamonds", "♦");
    Card* card5 = new Card(2, "Spades", "Two of Spades", "♠");
    Card* card6 = new Card(13, "Diamonds", "King of Diamonds", "♦");
    Card* card7 = new Card(14, "Diamonds", "Ace of Diamonds", "♦");
    testHand->addCard(card1);
    testHand->addCard(card2);

    vector<Card*> communityCards = {card3,card4,card5,card6,card7};
    
    testHand->calculateStrength(communityCards);
    
    ASSERT_EQ(testHand->getStrength(), 464);
}