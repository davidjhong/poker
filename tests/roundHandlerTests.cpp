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

// RoundHandler Test Suite

TEST(roundHandlerTests, startRoundTest)
{
    
    ifstream testInput("tests/testInputs/startRoundTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\n"
    );

    vector<Player*> expectedWinners{testPlayer1, testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");
    EXPECT_EQ(winners.at(1)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has folded!\n");

    vector<Player*> expectedWinners{testPlayer1};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startEarlyRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundEarlyFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has folded!\n");

    vector<Player*> expectedWinners{testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(roundHandlerTests, startLateRoundFoldTest)
{
    
    ifstream testInput("tests/testInputs/startRoundLateFoldTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 100.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 100.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 100. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has folded!\n");

    vector<Player*> expectedWinners{testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}

TEST(RoundHandlerTests, findStartingIndicesTest)
{
    RoundHandler* roundHandler = new RoundHandler();
    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);
    Player* testPlayer3 = new Player("David", 500, false);
    Player* testPlayer4 = new Player("Chloe", 500, false);

    vector<Player*> *playerList = new vector<Player*>{testPlayer1, testPlayer2, testPlayer3, testPlayer4};

    vector<unsigned int> expectedResult{1, 2, 3};

    EXPECT_EQ(roundHandler->findStartingIndices(playerList), expectedResult);
}

TEST(roundHandlerTests, startRoundRaiseTest)
{
    
    ifstream testInput("tests/testInputs/startRoundRaiseTest.txt");
    ostringstream out;

    ASSERT_TRUE(testInput.is_open()) << "Failed to open input file" << endl;
    
    Settings* settings = new Settings();
    RoundHandler* testHandler = new RoundHandler();

    testHandler->setSettings(settings);

    Player* testPlayer1 = new Player("Kevin", 500, false);
    Player* testPlayer2 = new Player("Jason", 500, false);

    vector<Player*>* playerList = new vector<Player*>{testPlayer1, testPlayer2};

    // playerList.push_back(testPlayer1);
    // playerList.push_back(testPlayer2);

    vector<vector<string>> roundHistory;

    vector<Player*> winners = testHandler->startRound(testInput, out, playerList, roundHistory);

    EXPECT_EQ(out.str(),
    "Jason, it's your turn!\nYou have 475 chips\nPot: 75. The current highest bet is 50!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nWhat would you like to raise your bet to?\nNew highest bet: 525\n0\nJason has raise to 525\nThe current pot amount is 550.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 450 chips\nPot: 550. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n|   |     |   |     |   |     |   |     |   |     \n| ? |     | ? |     | ? |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     |   |     |   |     \n| 2 |     | 2 |     | 2 |     | ? |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     |   |     \n| 2 |     | 2 |     | 2 |     | 2 |     | ? |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\nJason, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA3 |     | \xE2\x99\xA0 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nJason has called!\nThe current pot amount is 1000.\n\nKevin's turn!\nEnter anything to continue\nKevin, it's your turn!\nYou have 0 chips\nPot: 1000. The current highest bet is 525!\nYour hand:\n-----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     \n| A |     | A |     \n-----     -----     \nCommunity cards:\n-----     -----     -----     -----     -----     \n| \xE2\x99\xA6 |     | \xE2\x99\xA5 |     | \xE2\x99\xA3 |     | \xE2\x99\xA0 |     | \xE2\x99\xA6 |     \n| 2 |     | 2 |     | 2 |     | 2 |     | 3 |     \n-----     -----     -----     -----     -----     \n1. call\n2. raise\n3. check\n4. fold\nKevin has called!\nThe current pot amount is 1000.\n\nJason's turn!\nEnter anything to continue\n");

    vector<Player*> expectedWinners{testPlayer1, testPlayer2};

    EXPECT_EQ(winners, expectedWinners);
    EXPECT_EQ(winners.at(0)->getName(), "Kevin");
    EXPECT_EQ(winners.at(1)->getName(), "Jason");

    testHandler->resetRound(playerList);
    delete testHandler;
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
