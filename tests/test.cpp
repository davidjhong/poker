#include "gtest/gtest.h"
#include "../include/Card.h"
#include "../include/Deck.h"

TEST(CardTests, typicalCardTest) {
    Card* testCard = new Card(3, "Spades", "Three of Spades");

    EXPECT_EQ(testCard->getRank(), 3);
    EXPECT_EQ(testCard->getSuit(), "Spades");
    EXPECT_EQ(testCard->getName(), "Three of Spades");
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