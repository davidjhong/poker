#include "../header/GameHandler.h"
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
    this->gameRunning = true;
    this->settings = new Settings();
}

GameHandler::~GameHandler()
{
    for (int i = 0; i < playerList.size(); i++)
    {
        delete playerList.at(i);
    }
    delete this->settings;
}


void GameHandler::addPlayer(const string &playerName)
{
    assert(playerList.size() == 7 && "Seven players maximum");
    unsigned int chips = settings->getStartingChips();

    Player* newPlayer = new Player(playerName, chips);
    playerList.push_back(newPlayer);
    
}


void GameHandler::startGame()
{

    string input;

    while (gameRunning)
    {
        menuOptions(cout);

        // if (input == "1")
        // {
        //     // unsigned int numOfRounds = settings->getRounds();

        //     // for (int currRound = 1; currRound <= numOfRounds; currRound++)
        //     // {
        //     //      roundHandler->startRound();
        //     // }
        // }
        // else if (input == "2")
        // {
        //     settingsMenu(cout);
        // }
        // else if (input == "3")
        // {
        //     rulesMenu(cout);
        //     // display->Rules(cout);
        // }
        // else if (input == "4")
        // {
        //     // display->Credits(cout);
        //     gameRunning = false;
        // }
    }

    





}

void GameHandler::menuOptions(ostream &os)
{
    // display->menuScreen(os);

    bool inMenu = true;
    string input;

    while (inMenu)
    {
        // display->menuScreen(os);

        os << "select 1 for play\n";
        os << "select 2 for settings\n";
        os << "select 3 for rules\n";
        os << "select 4 for quit\n";

        cin >> input;
    
        if (input == "1")
        {
            // unsigned int numOfRounds = settings->getRounds();

            // for (int currRound = 1; currRound <= numOfRounds; currRound++)
            // {
            //      roundHandler->startRound();
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
        // display->settingsScreen(os);
        os << "select 1 to change player count\n";
        os << "select 2 to change starting chips\n";
        os << "select 3 to change big blind amount\n";
        os << "select 4 to change small blind amount\n";
        os << "select 5 to change number of rounds\n";
        os << "enter q to save and exit\n\n";

        cin >> input;

        if (input == "1")
        {
            // display->
            int playerCount = 0;
            while (playerCount < 2 || playerCount > 7)
            {
                os << "2 to 7 players allowed\n";
                os << "Enter number of players: \n";

                if (!(cin >> playerCount))
                {
                    clearScreen();
                    os << "Please enter a valid number.\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                }
            }
            settings->setNumPlayers(playerCount);
        }
        else if (input == "2")
        {
            
        }
        else if (input == "3")
        {
            
        }
        else if (input == "4")
        {
            
        }
        else if (input == "5")
        {
            
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
    
}