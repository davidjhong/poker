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

TEST(GameHandlerTests, AddPlayerTest) {
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
}

TEST(GameHandlerTests, BotGameTest)
{
    istringstream is;
    ostringstream os;
    GameHandler* gameHandler = new GameHandler();
    gameHandler->addPlayer("chloe", true);
    gameHandler->gameSetup(is, os, true);
    EXPECT_EQ(gameHandler->settings->getNumPlayers(), 2);
    EXPECT_EQ(gameHandler->playerList->front()->getName(), "Bot Kevin");
    EXPECT_EQ(gameHandler->playerList->back()->getName(), "chloe");
}

TEST(SettingsMenuTest, ChangeNumberOfPlayers) {

    ostringstream os;

    Settings* settings = new Settings();
    GameHandler* gameHandler = new GameHandler(); 
    settings->setNumPlayers(2);
    gameHandler->settingsMenu(os);
    EXPECT_EQ(settings->getNumPlayers(), 1);
}










int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
