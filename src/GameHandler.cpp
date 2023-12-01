#include "../header/GameHandler.h"
#include "../header/RoundHandler.h"
#include "../header/Player.h"
#include "../header/Settings.h"

#include <vector>
#include <iostream>
#include <ostream>
#include <assert.h>


#include <cstdlib>

using namespace std;

//https://stackoverflow.com/questions/17335816/clear-screen-using-c 
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

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


void GameHandler::addPlayer(const string &playerName)
{
    assert(playerList->size() < 7 && "Seven players maximum");
    unsigned int chips = settings->getStartingChips();

    Player* newPlayer = new Player(playerName, chips);
    playerList->push_back(newPlayer);

}


void GameHandler::startGame()
{

    string input;

    while (gameRunning)
    {
        menuOptions(cout);

        if (!gameRunning)
        {
            return;
        }

        gameSetup(cin, cout);

        startGame(cin, cout);


        //
        // for (int i = 0; i < settings->getNumOfRounds(); i++)
        // {
        //     this->roundHandler->startRound(this->playerList);
        // }

    }
}

void GameHandler::gameSetup(istream &is, ostream &os)
{
    const unsigned int playerCount = this->settings->getNumPlayers();
    string username;

    for (unsigned int i = 1; i <= playerCount; i++)
    {
        os << "Enter player " << i << "'s username: \n";
        cin >> username;

        addPlayer(username);
    }

}

void GameHandler::startGame(istream &is, ostream &os)
{
    const unsigned int numOfRounds = this->settings->getNumOfRounds();

    this->roundHandler->setSettings(this->settings);
    
    for (int i = 0; i < numOfRounds; i++)
    {
        clearScreen();
        os << "Round " << i + 1 << "!" << endl;
        this->roundHandler->startRound(is, os, this->playerList);

        // resetPlayers();

    }

}

void GameHandler::resetPlayers()
{
    for (Player* player: *playerList)
    {
        player->resetHand();
    }
}



void GameHandler::menuOptions(ostream &os)
{
    bool inMenu = true;
    string input;

    while (inMenu)
    {
        clearScreen();
        display->displayMenu(os);


        cin >> input;
    
        if (input == "1")
        {
            // game should start
            inMenu = false;

            // gameSetup(os);
            // unsigned int numOfRounds = settings->getNumOfRounds();

            // for (int currRound = 1; currRound <= numOfRounds; currRound++)
            // {
            //     roundHandler->startRound(playerList);
            // }
        }
        else if (input == "2")
        {
            settingsMenu(cout);
        }
        else if (input == "3")
        {
            rulesMenu(cout);
            // display->Rules(cout);
        }
        else if (input == "4")
        {
            cardRankingMenu(cout);
        }
        else if (input == "5")
        {
            cardComboMenu(cout);
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

void GameHandler::settingsMenu(ostream &os)
{
    bool inSettings = true;
    string input;

    while (inSettings)
    {
        clearScreen();
        display->displaySettings(os);
        // os << "select 1 to change player count\n";
        // os << "select 2 to change starting chips\n";
        // os << "select 3 to change big blind amount\n";
        // os << "select 4 to change small blind amount\n";
        // os << "select 5 to change number of rounds\n";
        // os << "enter q to save and exit\n\n";

        cin >> input;

        if (input == "1")
        {
            // display->
            unsigned int playerCount = 0;
            bool failedOnce = false;

            while (playerCount < 2 || playerCount > 7)
            {
                clearScreen();

                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "2 to 7 players allowed\n";
                os << "Enter number of players: \n";

                if (!(cin >> playerCount))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
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
                clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to 50000\n";

                if (!(cin >> startingChips))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
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
                clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to " << settings->getStartingChips() / 2 << "\n";

                if (!(cin >> bigBlindAmt))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
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
                clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to " << settings->getBigBlindAmt() / 2 << "\n";

                if (!(cin >> littleBlindAmt))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
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
                clearScreen();
                if (failedOnce)
                {
                    os << "Invalid input.\n";
                }
                os << "Enter a number from 1 to 100\n";

                if (!(cin >> numOfRounds))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
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

void GameHandler::rulesMenu(ostream &os)
{
    string input;

    while (input != "q")
    {
        display->displayRules(os);

        cin >> input;

        // if (input != "q)")

    }
    
}

void GameHandler::cardComboMenu(ostream &os)
{
    string input;
    while (input != "q")
    {
        display->displayCardCombinations(os);

        cin >> input;

    }
}

void GameHandler::cardRankingMenu(ostream &os)
{
    string input;
    while (input != "q")
    {
        display->displayCardRankings(os);

        cin >> input;

    }
}

