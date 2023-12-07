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

// Settings Test Suite

TEST(settingsTest, defaultSettingsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_EQ(testSettings->getNumPlayers(), 2);
  EXPECT_EQ(testSettings->getStartingChips(), 1000);
  EXPECT_EQ(testSettings->getBigBlindAmt(), 50);
  EXPECT_EQ(testSettings->getLittleBlindAmt(), 25);
  EXPECT_EQ(testSettings->getNumOfRounds(), 5);
  delete testSettings;
}


TEST(settingsTest, setGetNumOfRoundsTest)
{
  Settings* testSettings = new Settings();

  testSettings->setNumOfRounds(35);

  ASSERT_EQ(testSettings->getNumOfRounds(), 35);

  delete testSettings;
}


TEST(settingsTest, setGetLittleBigBlindTest)
{
  Settings* testSettings = new Settings();

  testSettings->setLittleBlindAmt(750);
  testSettings->setBigBlindAmt(1500);

  ASSERT_EQ(testSettings->getLittleBlindAmt(), 750);
  ASSERT_EQ(testSettings->getBigBlindAmt(), 1500);

  delete testSettings;
}

TEST(settingsTest, setGetPlayersTest)
{
  Settings* testSettings = new Settings();

  testSettings->setNumPlayers(4);
  EXPECT_EQ(testSettings->getNumPlayers(), 4);
  delete testSettings;
}

TEST(settingsTest, tooLittlePlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 1;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to less than 2 players");
  delete testSettings;
}

TEST(settingsTest, tooManyPlayersTest)
{
  Settings* testSettings = new Settings();

  unsigned int playerOverflow = 8;
  EXPECT_DEATH(testSettings->setNumPlayers(playerOverflow), "Tried setting to more than 7 players");
  delete testSettings;
}

TEST(settingsTest, setGetStartingChipsTest)
{
  Settings* testSettings = new Settings();

  testSettings->setStartingChips(40000);
  EXPECT_EQ(testSettings->getStartingChips(), 40000);
  delete testSettings;
}

TEST(settingsTest, tooManyStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(50001), "Only up to 50000 starting chips");
  delete testSettings;
}

TEST(settingsTest, tooLittleStartingChipsTest)
{
  Settings* testSettings = new Settings();

  EXPECT_DEATH(testSettings->setStartingChips(0), "Must have at least 100 starting chips");
  delete testSettings;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
