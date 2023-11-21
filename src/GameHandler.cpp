#include "../header/GameHandler.h"
#include "../header/Player.h"

#include <vector>
#include <iostream>
#include <ostream>
#include <assert.h>


using namespace std;



GameHandler::GameHandler()
{
    // this->display = new Display();
}

GameHandler::~GameHandler()
{
    for (int i = 0; i < playerList.size(); i++)
    {
        delete playerList.at(i);
    }
}


void GameHandler::addPlayer(const string &playerName)
{
    assert(playerList.size() == 7 && "Seven players maximum");
    // unsigned int chips = settings->getStartAmount();

    // Player* newPlayer = new Player(playerName, balance);
    // playerList.push_back(newPlayer);
    
}


void GameHandler::startGame()
{

    string input;
    bool gameRunning = true;


    while (gameRunning)
    {
        menuOptions(cout);
        cin >> input;

        if (input == "1")
        {
            // unsigned int numOfRounds = settings->getRounds();

            // for (int currRound = 1; currRound <= numOfRounds; currRound++)
            // {

            // }
        }
        else if (input == "2")
        {

        }
        else if (input == "3")
        {
            // display->Rules(cout);
        }
        else if (input == "4")
        {
            // display->Credits(cout);
            gameRunning = false;
        }
    }

    





}

void GameHandler::menuOptions(ostream &os)
{
    os << "select 1 for play\n";
    os << "select 2 for settings\n";
    os << "select 3 for rules\n";
    os << "select 4 for quit\n";
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