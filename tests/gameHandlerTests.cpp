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
#include "../header/GameHandler.h"

TEST(GameHandlerTests, AddPlayerIndividualTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "chloe");
    delete gameHandler;
}

TEST(GameHandlerTests, AddMultiplePlayersTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "chloe");

    gameHandler->addPlayer("kevin", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "kevin");

    gameHandler->addPlayer("jason", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "jason");
    delete gameHandler;
}

TEST(GameHandlerTests, AddPlayerOverLimitTest) {
    GameHandler* gameHandler = new GameHandler();

    gameHandler->addPlayer("chloe", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "chloe");

    gameHandler->addPlayer("kevin", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "kevin");

    gameHandler->addPlayer("jason", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "jason");

    gameHandler->addPlayer("david", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "david");

    gameHandler->addPlayer("emily", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "emily");

    gameHandler->addPlayer("nagi", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "nagi");

    gameHandler->addPlayer("gojo", false);
    ASSERT_EQ(gameHandler->playerList->back()->getName(), "gojo");

    ASSERT_DEATH(gameHandler->addPlayer("gency", false), "Seven players maximum");
    delete gameHandler;
}
TEST(GameHandlerTests, BotGameTest) {
    ifstream testInput ("tests/testInputs/BotGameTestInput.txt");
    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    ostringstream out;
    GameHandler* gameHandler = new GameHandler();

    // gameHandler->addPlayer("chloe", false);
    // gameHandler->addPlayer("Kevin Bot", true);

    // EXPECT_EQ(gameHandler->settings->getNumPlayers(), 2);
    // EXPECT_EQ(gameHandler->playerList->back()->getName(), "Bot Kevin");
    // EXPECT_EQ(gameHandler->playerList->front()->getName(), "chloe");

    gameHandler->runGame(testInput, out);
    // gameHandler->gameSetup(testInput, out, true);
    // cout << out.str() << endl;
    EXPECT_EQ(out.str(), "-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\nEnter player username: \nBot Kevin has called!\nThe current pot amount is 100.\n\nkevin's turn!\nEnter anything to continue\nkevin, it's your turn!\nYou have 950 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA5 |     \n| 7 |     | J |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nkevin has folded!\nBot Kevin won 100 chips with a High Card!\nRound 1 complete!\nWould you like to continue playing?\n1. yes\n2. no\n-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\n");

    delete gameHandler;
    // EXPECT_EQ(out.str(),
    // "-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\nEnter player username: \nBot Kevin has called!\nThe current pot amount is 100.\n\nkevin's turn!\nEnter anything to continue\nkevin, it's your turn!\nYou have 950 chips\nPot: 100\nYour hand:\n-----     -----     \n| \xE2\x99\xA5 |     | \xE2\x99\xA6 |     \n| 8 |     | 7 |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nkevin has folded!\nBot Kevin won 100 chips with a High Card!\nRound 1 complete!\nWould you like to continue playing?\n1. yes\n2. no\n-------------- START MENU -----------------\n1) Start game\n2) Start bot game\n3) Settings\n4) Rules\n5) Card rankings\n6) Card combinations\nq) Quit\nEnter an option\n-------------------------------------------\n");
 
}

TEST(GameHandlerTests, ChangeNumberOfPlayers) {
    ostringstream out;
    GameHandler* gameHandler = new GameHandler();
    // simulate user input 
    ifstream testInput("tests/testInputs/settingsNumPlayersTest.txt");
    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

    gameHandler->settingsMenu(testInput, out);
    // gameHandler->runGame(testInput, out);
    
    EXPECT_EQ(out.str(),
    "-------------- SETTINGS -----------------\n"
    "1) Change player count\n"
    "2) Change starting chips\n"
    "3) Change big blind amount\n"
    "4) Change small blind amount\n"
    "5) Change number of rounds\n"
    "q) Save and exit\n"
    "----------------------------------------\n"
    "2 to 7 players allowed\n"
    "Enter number of players: \n"
    "-------------- SETTINGS -----------------\n"
    "1) Change player count\n"
    "2) Change starting chips\n"
    "3) Change big blind amount\n"
    "4) Change small blind amount\n"
    "5) Change number of rounds\n"
    "q) Save and exit\n"
    "----------------------------------------\n");
    EXPECT_EQ(gameHandler->settings->getNumPlayers(), 3);

    delete gameHandler;
}

TEST(GameHandlerTests, ruleDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/ruleDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

  gameHandler->rulesMenu(testInput, out);
  EXPECT_EQ(out.str(),
  "\nOverview: \nEach player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. \n*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. \nThe objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards\n\nTexas Hold' em - in depth: \nAt the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will be \nthe small blind, then the player to their left will be the big blind, which is double the value of the small blind. 2 hole cards will be dealt to each player. \nThe starting player may now chooute to fold, call or raise. \n   fold: discard hand and put no more chips in the pot\n   call: add the call amount to the pot\n   raise: increase the call amount for the current round\nFollowing this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player \nhas folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. \nEach player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute \nto fold, call or raise.Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised.\nAt this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest \nranked combination wins the pot.\nIf players tie, the highest hole card that isn't a part of their best hand is used to decide the winner.\nq) back to menu \n");
  
  delete gameHandler;
}

TEST(GameHandlerTests, cardRankingDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/cardRankDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;

  
  gameHandler->cardRankingMenu(testInput, out);
  EXPECT_EQ(out.str(),
  "The card rankings are displayed below, from weakest to strongest: \n2\n3\n4\n5\n6\n7\n8\n9\n10\nJ (jack)\nQ (queen)\nK (king)\nA (ace)\n* Note that in Texas Hold' em, all suits are equally ranked\nq) back to menu \n");

  delete gameHandler;
}

TEST(GameHandlerTests, cardComboDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/cardComboDisplayTestInput.txt");
  ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
  gameHandler->cardComboMenu(testInput, out);
  EXPECT_EQ(out.str(),
  " ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | royal flush: straight flush from 10 to Ace.\n| 10 ||  J ||  Q ||  K ||  A |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | straight flush: straight, but all cards are the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | four of a kind: four of the same card, highest value wins in a tie.\n|  A ||  A ||  A ||  A ||  2 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA7  || \xE2\x99\xA2  | full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie.\n|  A ||  A ||  A ||  K ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  || \xE2\x99\xA1  | flush: 5 cards of the same suit, highest card wins in a tie.\n|  2 ||  4 ||  6 ||  8 ||  K |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | straight: 5 cards in order but not of the same suit.\n|  5 ||  6 ||  7 ||  8 ||  9 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | three of a kind: 3 of a kind, highest card wins in a tie.\n|  A ||  A ||  A ||  2 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | two pair: 2 sets of pairs.\n|  K ||  K ||  Q ||  Q ||  J |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | pair: 2 of a kind, highest card wins in a tie.\n|  A ||  A ||  9 ||  8 ||  7 |\n ----  ----  ----  ----  ----\n\n ----  ----  ----  ----  ----\n| \xE2\x99\xA2  || \xE2\x99\xA1  || \xE2\x99\xA4  || \xE2\x99\xA1  || \xE2\x99\xA4  | high card: no combination, only a single high ranked card\n|  A ||  8 ||  6 ||  4 ||  2 |\n ----  ----  ----  ----  ----\nq) back to menu \n");

  delete gameHandler;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
