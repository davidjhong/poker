#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Hand.h"
#include "../header/Settings.h"
#include "../header/Display.h"
#include "../header/RoundHandler.h"
#include "../header/Bot.h"



// DISPLAY TESTS


TEST(DisplayTest, displayCardsTest)
{
  
  Player* player = new Player();

  Card* card1 = new Card(1, "Spades", "Ace of Spades", "♠");
  Card* card2 = new Card(5, "Spades", "Five of Spades", "♠");
  vector<Card*> cards = {card1, card2};
  player->getHand()->addCard(card1);
  player->getHand()->addCard(card2);

  ostringstream out; 
  Display* display = new Display();
  display->displayCards(out, cards);
 

  EXPECT_EQ(out.str(),

"-----     -----     \n"     
"| ♠ |     | ♠ |     \n"    
"| A |     | 5 |     \n"     
"-----     -----     \n"); 

  }

TEST(DisplayTest, displayCommunityCardsTest)
{
  
  Player* player = new Player();
  player->setName("chloe");
  Card* card4 = new Card(6, "Diamonds", "Five of Diamonds", "♦");
  Card* card5 = new Card(3, "Hearts", "Ten of Hearts", "♥");
  Card* card6 = new Card(12, "Hearts", "Nine of Hearts", "♥");
  Card* card7 = new Card(10, "Clubs", "Eight of Clubs", "♣");
  vector<Card*> CommunityCards = {card4, card5, card6, card7};

  Pot* pot = new Pot();

  ostringstream out; 
  Display* display = new Display();
  display->displayGameStatus(out, CommunityCards, player, pot);
 

  EXPECT_EQ(out.str(),
  "chloe, it's your turn!\n"
  "You have 0 chips\n"
  "Pot: 0\n"
  "Your hand:\n\n\n\n\n"
  "Community cards:\n"
  "-----     -----     -----     -----     -----     \n"     
  "| ♦ |     | ♥ |     | ♥ |     | ♣  |    |   |     \n"     
  "| 6 |     | 3 |     | Q |     | 10 |    | ? |     \n"     
  "-----     -----     -----     -----     -----     \n" 
  "1. call\n"
  "2. raise\n"
  "3. check\n"
  "4. fold\n");   
}




TEST(displayTest, displayMenuTest)
{
  ostringstream out; 
  Display display; 
  display.displayMenu(out);
  EXPECT_EQ(out.str(),
    "-------------- START MENU -----------------\n" 
    "1) Start game\n"
    "2) Settings\n" 
    "3) Rules\n" 
    "4) Card rankings\n" 
    "5) Card combinations\n"
    "q) Quit\n"
    "Enter an option\n"
    "-------------------------------------------\n");
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


TEST(displayTest, displayRulesTest)
{
  ostringstream out;
  Display displayru;
  displayru.displayRules(out);
  EXPECT_EQ(out.str(),
    "\nOverview: \n" 
    "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. \n"
    "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. \n"
    "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards\n"
    "\nTexas Hold' em - in depth: \n"
    "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will be \nthe small blind, then the player to their left will be the big blind, which is double the value of the small blind. "
    "2 hole cards will be dealt to each player. \nThe starting player may now chooute to fold, call or raise. \n"
    "   fold: discard hand and put no more chips in the pot\n"
    "   call: add the call amount to the pot\n"
    "   raise: increase the call amount for the current round\n"
    "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player \nhas folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. \n"
    "Each player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute \nto fold, call or raise."
    "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised.\n"
    "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest \nranked combination wins the pot.\n"
    "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner.\n"
    "q) back to menu \n");

}

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

    "-----     -----     \n"
    "| ♠ |     | ♠ |     \n"
    "| A |     | 5 |     \n"
    "-----     -----     \n"
    "Community cards:\n"
    "-----     -----     -----     -----     -----     \n"
    "| ♦ |     | ♦ |     | ♥ |     | ♥ |     | ♣  |    \n"
    "| J |     | 6 |     | 3 |     | Q |     | 10 |    \n"
    "-----     -----     -----     -----     -----     \n"
    "1. call\n"
    "2. raise\n"
    "3. check\n"
    "4. fold\n");
}


TEST(displayTest, displayRoundHistory)
{
  ostringstream out;
  Display* displayRoundHist = new Display();
  vector<vector<string>> roundHistory = {
    {"chloe", "$100", "full house"},
    {"david", "$150", "straight"},
    {"kevin", "$200", "royal flush"},
    {"jason", "$300", "four of a kind"}
  };
  displayRoundHist->displayRoundHistory(out, roundHistory);

  EXPECT_EQ(out.str(),
  "ROUND      WINNER NAME      POT SIZE      COMBO NAME\n"  
  "1         chloe         $100         full house\n"
  "2         david         $150         straight\n"
  "3         kevin         $200         royal flush\n"
  "4         jason         $300         four of a kind\n");
  



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
 
  vector<Card*> communityCards{card3, card4, card5, card6, card7};
  // //set up the pot
  Pot* pot = new Pot();
  pot->addToPot(100);

  RoundHandler* roundHandler = new RoundHandler();
  roundHandler->setCards(communityCards);

  vector<Player*> *players = new vector<Player*>{player1, player2};
  vector<Player*> winners = roundHandler->lookForWinner(players);

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

TEST(displayTests, botOutputTest)
{
  Bot* testBot = new Bot("Bot Kevin", 500);

  ASSERT_TRUE(testBot->randomAction());

  delete testBot;
}

TEST(utilityTest, clearScreenTest)
{
  Utility::clearScreen();
  
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
