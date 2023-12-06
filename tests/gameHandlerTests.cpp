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
    GameHandler gameHandler;

    gameHandler.addPlayer("chloe", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "chloe");
}

TEST(GameHandlerTests, AddMultiplePlayersTest) {
    GameHandler gameHandler;

    gameHandler.addPlayer("chloe", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "chloe");

    gameHandler.addPlayer("kevin", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "kevin");

    gameHandler.addPlayer("jason", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "jason");
}

TEST(GameHandlerTests, AddPlayerOverLimitTest) {
    GameHandler gameHandler;

    gameHandler.addPlayer("chloe", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "chloe");

    gameHandler.addPlayer("kevin", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "kevin");

    gameHandler.addPlayer("jason", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "jason");

    gameHandler.addPlayer("david", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "david");

    gameHandler.addPlayer("emily", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "emily");

    gameHandler.addPlayer("nagi", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "nagi");

    gameHandler.addPlayer("gojo", false);
    ASSERT_EQ(gameHandler.playerList->back()->getName(), "gojo");

    ASSERT_DEATH(gameHandler.addPlayer("gency", false), "Seven players maximum");
}


// TEST(GameHandlerTests, BotGameTest) {
//     ifstream testInput ("tests/testInputs/BotGameTestInput.txt");
//     ostringstream out;
//     GameHandler* gameHandler = new GameHandler();
//     gameHandler->gameSetup(testInput, out, true);
//     EXPECT_EQ(gameHandler->settings->getNumPlayers(), 2);
//     EXPECT_EQ(gameHandler->playerList->back()->getName(), "Bot Kevin");
//     EXPECT_EQ(gameHandler->playerList->front()->getName(), "\x1B");
    
// }


TEST(GameHandlerTests, ChangeNumberOfPlayers) {
    ostringstream out;
    GameHandler* gameHandler = new GameHandler();
    // simulate user input for player count
    ifstream testInput("tests/testInputs/settingsNumPlayersTest.txt");
    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    // gameHandler->settingsMenu(out);
    // gameHandler->runGame(testInput, out);

    // EXPECT_EQ(str.out(),
    // "-------------- SETTINGS -----------------" 
    // "1) Change player count\n"
    // "2) Change starting chips\n"
    // "3) Change big blind amount\n"
    // "4) Change small blind amount\n"
    // "5) Change number of rounds\n"
    // "q) Save and exit\n"
    // "----------------------------------------");
    EXPECT_EQ(gameHandler->settings->getNumPlayers(), 2);
 
}

TEST(GameHandlerTests, ruleDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/settingsNumPlayersTest.txt");

  gameHandler->rulesMenu(testInput, out);
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

TEST(GameHandlerTests, cardRankingDisplayTest)
{
  GameHandler* gameHandler = new GameHandler;
  ostringstream out;
  ifstream testInput("tests/testInputs/settingsNumPlayersTest.txt");
  gameHandler->rulesMenu(testInput, out);
  EXPECT_EQ(out.str(),
  "The card rankings are displayed below, from weakest to strongest: \n"
  "2\n"
  "4\n"
  "5\n"
  "6\n"
  "7\n"
  "8\n"
  "9\n"
  "10\n"
  "J\n"
  "Q\n"
  "K\n"
  "* Note that in Texas Hold' em, all suits are equally ranked\n"
  "q) back to menu \n");
}






int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
