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

TEST(gameHandlerTest, startGameTest)
{
    GameHandler* gameHandler = new GameHandler();
    gameHandler->startGame()
    EXPECT_EQ(out.str(),
    "Enter player 1's username:\n")
}