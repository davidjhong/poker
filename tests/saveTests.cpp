#include "gtest/gtest.h"
#include "../header/Player.h"
#include "../header/Card.h"
#include "../header/handRank.h"
#include "../header/Pot.h"
#include "../header/Deck.h"
#include "../header/Hand.h"
#include "../header/Settings.h"
#include "../header/GameHandler.h"


// add Jason and Kevin as players. 
// change big blind, little blind, and number of rounds
TEST(saveTests, hardCodedTest) {

  GameHandler *testGameHandler = new GameHandler();
  testGameHandler->addPlayer("Jason", false);
  testGameHandler->addPlayer("Kevin", false);

  // default big blind is 50, and little blind is 25

  testGameHandler->getSettings()->setBigBlindAmt(100);
  testGameHandler->getSettings()->setLittleBlindAmt(55);
  testGameHandler->getSettings()->setNumOfRounds(50);
  testGameHandler->saveToFile(cin, cout, "HardCodedSave");

  ifstream file("savefiles/HardCodedSave");
  string str;
  int bigBlind, littleBlind, numRounds;
  if(file >> str) {
    file >> bigBlind;
  }
  if(file >> str) {
    file >> littleBlind;
  }
  if(file >> str) {
    file >> numRounds;
  }
  EXPECT_EQ(bigBlind, 100);
  EXPECT_EQ(littleBlind, 55);
  EXPECT_EQ(numRounds, 50);
}

TEST(saveTests, loadHardCodedSaveTest) {
  GameHandler *testGameHandler = new GameHandler();
  testGameHandler->loadFromFile(cin, cout, "HardCodedSave");
  EXPECT_EQ(testGameHandler->getRoundHandler()->getRound(), 2);
  EXPECT_EQ(testGameHandler->getRoundHandler()->getDealerIndex(), 1);
  EXPECT_EQ(testGameHandler->getSettings()->getBigBlindAmt(), 100);
  EXPECT_EQ(testGameHandler->getSettings()->getLittleBlindAmt(), 55);
  EXPECT_EQ(testGameHandler->getSettings()->getNumOfRounds(), 50);
  EXPECT_EQ(testGameHandler->getSettings()->getNumPlayers(), 2);

}


TEST(saveTests, thirdRoundTest) {
  GameHandler *testGameHandler = new GameHandler();
  testGameHandler->addPlayer("Jason", false);
  testGameHandler->addPlayer("Maya", false);
  testGameHandler->addPlayer("Jacky", false);
  
  testGameHandler->getSettings()->setStartingChips(20000);
  testGameHandler->getRoundHandler()->setRound(3);
  testGameHandler->getSettings()->setNumOfRounds(20);
  testGameHandler->saveToFile(cin, cout, "thirdRoundTest");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}