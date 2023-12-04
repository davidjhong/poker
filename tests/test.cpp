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




// Round Handler Test Suite

// TEST(roundHandlerTests, callTest)
// {
//   ostream os;
//   vector<Player*> testPlayers = {new Player("Kevin", 200), new Player("Jason", 300)};
//   // Player* testPlayer1 = new Player("Kevin", 200);
//   // Player* testPlayer2 = new Player("Jason", 300);

//   RoundHandler* testHandler = new RoundHandler(os, testPlayers);

//   // testHandler->
// }





// COMBO NAME TEST

// TEST(handTests, getComboNameTest)
// {
//   Hand* hand = new Hand();
//   vector<Card*> &communityCards;

//   Card* card1 = new Card(3, "Spades", "Three of Spades");
//   Card* card2 = new Card(5, "Spades", "Five of Spades");
//   Card* card3 = new Card(10, "Spades", "Ten of Spades");

//   hand->addCard(card1);
//   hand->addCard(card2);
//   hand->addCard(card3);

//   hand->calculateStrength(communityCards);
//   EXPECT_EQ(hand->getComboName(), "High Card");

// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
