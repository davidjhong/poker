#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Deck.h"
#include "../header/Hand.h"
#include "../header/Settings.h"
#include "../header/GameHandler.h"

TEST(saveTests, construcTest) {

  GameHandler *testGameHandler = new GameHandler();
  testGameHandler->addPlayer("Jason");
  testGameHandler->addPlayer("Kevin");
  


  testGameHandler->saveToFile("Dec 4th");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}