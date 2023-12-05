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


// DISPLAY TESTS


TEST(DisplayTest, displayGameStatusTest)
{
  Player* player = new Player();
  player -> setName("chloe");
  player -> setBalance(200);

  // set up the hand with some cards
  
  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Two of Spades", "♠");
  Card* card3 = new Card(11, "Diamonds", "Three of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  
  player->getHand()->addCard(card1);
  player->getHand()->addCard(card2);
 
  vector<Card*> cards = {card1, card2};
  vector<Card*> communityCards = {card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  ostringstream out; 
  Display displayStats;

  displayStats.displayGameStatus(out, communityCards, player, pot);

  EXPECT_EQ(out.str(),
    "chloe, it's your turn!\n"
    "You have 200 chips\n"
    "Pot: 100\n"
    "Your hand:\n"

    " ----\n"
    "| ♠ |\n"
    "| A |\n"
    " ----\n"
    "Community cards:"
    " ----\n"
    "| ♠ |\n"
    "| 2 |\n"
    " ----\n"
    "1. call\n"
    "2. raise\n"
    "3. check\n"
    "4. fold\n");
}


TEST(displayTest, displayBetweenTurnsTest)
{
  ostringstream out;
  Display* displayTurns = new Display();
  Player* player = new Player();
  player->setName("chloe");
  displayTurns->displayBetweenTurns(out, player);
  EXPECT_EQ(out.str(),
    "chloe's turn\n"
    "Enter 1 to continue\n");
}



TEST(displayTest, displayWinnerTest)
{
  ostringstream out;
  Display display;

  Player* player1 = new Player("Kevin", 500, false);
  Player* player2 = new Player("Jason", 500, false);

  Card* winningCard1 = new Card(1, "Hearts", "Ace of Hearts", "♥");
  Card* winningCard2 = new Card(5, "Hearts", "Five of Hearts", "♥");

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");


  Card* card3 = new Card(11, "Diamonds", "Queen of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Six of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Three of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "King of Hearts", "♥");
  Card* card7 = new Card(10, "Hearts", "Jack of Hearts", "♥");
  
  player1->getHand()->addCard(winningCard1);
  player1->getHand()->addCard(winningCard2);

  player2->getHand()->addCard(card1);
  player2->getHand()->addCard(card2);
 
  vector<Card*> communityCards = {card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  player1->getHand()->calculateStrength(communityCards);
  player2->getHand()->calculateStrength(communityCards);


  RoundHandler* roundHandler = new RoundHandler();

  vector<Player*> *playerList = new vector<Player*>();

  playerList->push_back(player1);
  playerList->push_back(player2);

  vector<Player*> winners = roundHandler->lookForWinner(playerList);

  display.displayWinner(out, winners, pot);
  EXPECT_EQ(out.str(),
    "Kevin won 100 chips with a Flush!\n");
  EXPECT_EQ(player1->getBalance(), 500);
  EXPECT_EQ(player2->getBalance(), 500);

}

TEST(displayTest, displayTieWinnersTest)
{
  ostringstream out;
  Display display;

  Player* player1 = new Player("Kevin", 500, false);
  Player* player2 = new Player("Jason", 500, false);

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Two of Spades", "♠");
  Card* card3 = new Card(11, "Diamonds", "Three of Diamonds", "♦");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  
  player1->getHand()->addCard(card1);
  player1->getHand()->addCard(card2);
  player2->getHand()->addCard(card1);
  player2->getHand()->addCard(card2);
 
  vector<Card*> cards = {card1, card2};
  vector<Card*> communityCards = {card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  player1->getHand()->calculateStrength(communityCards);
  player2->getHand()->calculateStrength(communityCards);


  RoundHandler* roundHandler = new RoundHandler();

  vector<Player*> *playerList = new vector<Player*>();

  playerList->push_back(player1);
  playerList->push_back(player2);

  vector<Player*> winners = roundHandler->lookForWinner(playerList);


  display.displayWinner(out, winners, pot);
  EXPECT_EQ(out.str(),
    "Kevin, and Jason won a split pot of 50 each!\n");
  EXPECT_EQ(player1->getBalance(), 500);
  EXPECT_EQ(player2->getBalance(), 500);

}
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
