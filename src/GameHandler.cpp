#include "../header/GameHandler.h"
#include "../header/RoundHandler.h"
#include "../header/Player.h"
#include "../header/Settings.h"
#include "../header/Display.h"
#include "../header/Utility.h"
#include "../header/Bot.h"

#include <vector>
#include <iostream>
#include <ostream>
#include <assert.h>


#include <cstdlib>

using namespace std;

GameHandler::GameHandler()
{
    // this->display = new Display();
    this->roundHandler = new RoundHandler();
    this->gameRunning = true;
    this->settings = new Settings();
    this->playerList = new vector<Player*>;
}

GameHandler::~GameHandler()
{
    for (int i = playerList->size() - 1; i >= 0; i--)
    {
        // cout << playerList->size() << endl;
        delete playerList->at(i);
    }
    
    delete this->playerList;
    delete this->settings;
    delete this->roundHandler;
}


void GameHandler::addPlayer(const string &playerName, bool isBot)
{
    assert(playerList->size() < 7 && "Seven players maximum");
    unsigned int chips = settings->getStartingChips();

    if (isBot)
    {
        Bot* bot = new Bot("Bot Kevin", chips);
        playerList->push_back(bot);
    }
    else
    {
        Player* newPlayer = new Player(playerName, chips, false);
        playerList->push_back(newPlayer);
    }

}


void GameHandler::runGame(istream& is, ostream& os)
{

    string input;

    while (gameRunning)
    {
        bool botGame = menuOptions(is, os);

        if (!gameRunning)
        {
            return;
        }

        if (botGame)
        {
            gameSetup(is, os, true);
        }
        else
        {
            gameSetup(is, os, false);
        }


        startGame(is, os);

        


        //
        // for (int i = 0; i < settings->getNumOfRounds(); i++)
        // {
        //     this->roundHandler->startRound(this->playerList);
        // }

    }
}

void GameHandler::gameSetup(istream &is, ostream &os, bool botGame)
{
    if (botGame)
    {
        string username;
        os << "Enter player username: \n";
        cin >> username;

        addPlayer(username, false);

        addPlayer("Bot Kevin", true);
        return;
    }


    const unsigned int playerCount = this->settings->getNumPlayers();
    string username;

    for (unsigned int i = 1; i <= playerCount; i++)
    {
        os << "Enter player " << i << "'s username: \n";
        cin >> username;

        addPlayer(username, false);
    }

}

void GameHandler::startGame(istream &is, ostream &os)
{
    const unsigned int numOfRounds = this->settings->getNumOfRounds();

    this->roundHandler->setSettings(this->settings);
    
    for (int round = 1; round <= numOfRounds; round++)
    {
        Utility::clearScreen();
        // os << "Round " << round + 1 << "!" << endl;

        roundHandler->deck->shuffleDeck(true);

        vector<Player*> winners = roundHandler->startRound(is, os, this->playerList, this->roundHistory);


        display->displayWinner(os, winners, roundHandler->getPot());



        bool continuePlaying = optionToLeave(is, os);

        if (!continuePlaying)
        {
            for (int i = playerList->size() - 1; i >= 0; i--)
            {
                // cout << playerList->size() << endl;
                delete playerList->at(i);
            }
            playerList->clear();

            return;
        }
        
        Player* gameWinner = this->roundHandler->resetRound(this->playerList);

        if (gameWinner)
        {
            string exit;
            os << "THE GAME WINNER IS " << gameWinner->getName() << " WITH " << gameWinner->getBalance() << endl;
            os << "Enter anything to continue." << endl;
            is >> exit;
            break;
        }


    }

    // credits Screen

}



bool GameHandler::optionToLeave(istream &is, ostream &os)
{
    unsigned int round = this->roundHandler->getRound();

    os << "Round " << round << " complete!" << endl;
    os << "Would you like to continue playing?" << endl;
    os << "1. yes" << endl;
    os << "2. no" << endl;

    int input = 0;

    while (!(is >> input) || (input != 1 && input != 2))
    {
        Utility::clearScreen();
        os << "Round " << round << " complete!" << endl;
        os << "Would you like to continue playing?" << endl;
        os << "1. yes" << endl;
        os << "2. no" << endl;
        os << "Invalid input. Try again" << endl;

        is.clear();
        is.ignore(256, '\n');
    }

    if (input == 1)
    {
        return true;
    }
    return false;
}

bool GameHandler::menuOptions(istream &is, ostream &os)
{
    bool inMenu = true;
    string input;

    while (inMenu)
    {
        Utility::clearScreen();
        display->displayMenu(os);


        is >> input;
    
        if (input == "1")
        {
            // game should start
            inMenu = false;

            return false;

            // gameSetup(os);
            // unsigned int numOfRounds = settings->getNumOfRounds();

            // for (int currRound = 1; currRound <= numOfRounds; currRound++)
            // {
            //     roundHandler->startRound(playerList);
            // }
        }
        else if (input == "2")
        {
            return true;
            // inMenu = false;
        }
        else if (input == "3")
        {
            settingsMenu(is, os);
        }
        else if (input == "4")
        {
            rulesMenu(is, os);
            // display->Rules(cout);
        }
        else if (input == "5")
        {
            cardRankingMenu(is, os);
        }
        else if (input == "6")
        {
            cardComboMenu(is, os);
        }
        else if (input == "q")
        {
            // display->Credits(cout);
            inMenu = false;
            gameRunning = false;
        }
    }

    
    // os << "select 1 for play\n";
    // os << "select 2 for settings\n";
    // os << "select 3 for rules\n";
    // os << "select 4 for quit\n";
    // while (input != "1" && input != "2" && input != "3" && input != "4")
    // {
    //     // display->mainMenu(os);
    //     os << menu 
    //     cin >> input;

    //     if (input != "1" && input != "2" && input != "3" && input != "4")
    //     {
    //         os << "Invalid Input. Please enter 1, 2, 3, or 4.\n";
    //     }

    // }


}

void GameHandler::settingsMenu(istream &is, ostream &os)
{
    bool inSettings = true;
    string input;

    while (inSettings)
    {
        Utility::clearScreen();
        display->displaySettings(os);
        // os << "select 1 to change player count\n";
        // os << "select 2 to change starting chips\n";
        // os << "select 3 to change big blind amount\n";
        // os << "select 4 to change small blind amount\n";
        // os << "select 5 to change number of rounds\n";
        // os << "enter q to save and exit\n\n";

        is >> input;

        if (input == "1")
        {
            // display->
            unsigned int playerCount = 0;
            bool failedOnce = false;

            while (playerCount < 2 || playerCount > 7)
            {
                Utility::clearScreen();

                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "2 to 7 players allowed\n";
                os << "Enter number of players: \n";

                if (!(is >> playerCount))
                {
                    Utility::clearScreen();
                    os << "Please enter a valid number.\n";
                    is.clear();
                    is.ignore(10000,'\n');
                }
                failedOnce = true;
            }
            settings->setNumPlayers(playerCount);
        }
        else if (input == "2")
        {
            unsigned int startingChips = 0;
            bool failedOnce = false;

            while (startingChips <= 0 || startingChips > 50000)
            {
                Utility::clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to 50000\n";

                if (!(is >> startingChips))
                {
                    Utility::clearScreen();
                    os << "Please enter a valid number.\n";
                    is.clear();
                    is.ignore(10000,'\n');
                }

                failedOnce = true;
            }

            settings->setStartingChips(startingChips);
            
        }
        else if (input == "3")
        {

            unsigned int bigBlindAmt = 0;
            bool failedOnce = false;

            while (bigBlindAmt <= 0 || bigBlindAmt > settings->getStartingChips() / 2)
            {
                Utility::clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to " << settings->getStartingChips() / 2 << "\n";

                if (!(is >> bigBlindAmt))
                {
                    Utility::clearScreen();
                    os << "Please enter a valid number.\n";
                    is.clear();
                    is.ignore(10000,'\n');
                }

                failedOnce = true;

            }
            settings->setBigBlindAmt(bigBlindAmt);
            
        }
        else if (input == "4")
        {
            unsigned int littleBlindAmt = 0;
            bool failedOnce = false;

            while (littleBlindAmt <= 0 || littleBlindAmt > settings->getBigBlindAmt() / 2)
            {
                Utility::clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to " << settings->getBigBlindAmt() / 2 << "\n";

                if (!(is >> littleBlindAmt))
                {
                    Utility::clearScreen();
                    os << "Please enter a valid number.\n";
                    is.clear();
                    is.ignore(10000,'\n');
                }

                failedOnce = true;

            }
            settings->setLittleBlindAmt(littleBlindAmt);
            
        }
        else if (input == "5")
        {

            unsigned int numOfRounds = 0;
            bool failedOnce = false;

            while (numOfRounds <= 0 || numOfRounds > 100)
            {
                Utility::clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to 100\n";

                if (!(is >> numOfRounds))
                {
                    Utility::clearScreen();
                    os << "Please enter a valid number.\n";
                    is.clear();
                    is.ignore(10000,'\n');
                }

                failedOnce = true;

            }

            settings->setNumOfRounds(numOfRounds);
            
        }
        else if (input == "q")
        {
            inSettings = false;
        }
        else
        {
            os << "Invalid input. Try again.\n";
        }
    }
    
}

void GameHandler::rulesMenu(istream& is, ostream &os)
{
    string input;

    while (input != "q")
    {
        display->displayRules(os);

        is >> input;

        // if (input != "q)")

    }
    
}

void GameHandler::cardComboMenu(istream &is, ostream &os)
{
    string input;
    while (input != "q")
    {
        display->displayCardCombinations(os);

        is >> input;

    }
}

void GameHandler::cardRankingMenu(istream &is, ostream &os)
{
    string input;
    while (input != "q")
    {
        display->displayCardRankings(os);

        is >> input;

    }
}
