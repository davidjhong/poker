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

//adding save file
#include <cstdlib>

using namespace std;

GameHandler::GameHandler()
{
    this->roundHandler = new RoundHandler();
    this->gameRunning = true;
    this->settings = new Settings();
    this->playerList = new vector<Player*>;
    this->isRandom = true;
}

GameHandler::GameHandler(bool isRandom) 
{
    this->roundHandler = new RoundHandler();
    this->gameRunning = true;
    this->settings = new Settings();
    this->playerList = new vector<Player*>;
    this->isRandom = isRandom;
    this->loadingGame = false;
}

GameHandler::~GameHandler()
{
    for (int i = playerList->size() - 1; i >= 0; i--)
    {
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
        Bot* bot = new Bot("Bot Kevin", chips, isRandom);
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
    }
}

void GameHandler::gameSetup(istream &is, ostream &os, bool botGame)
{
    if(loadingGame) {
        return;
    }
    if (botGame)
    {
        string username;
        os << "Enter player username: \n";
        is >> username;

        addPlayer(username, false);

        addPlayer("Bot Kevin", true);
        return;
    }

    const unsigned int playerCount = this->settings->getNumPlayers();
    string username;

    for (unsigned int i = 1; i <= playerCount; i++)
    {
        os << "Enter player " << i << "'s username: \n";
        is >> username;

        addPlayer(username, false);
    }

}

void GameHandler::startGame(istream &is, ostream &os)
{
    const unsigned int numOfRounds = this->settings->getNumOfRounds();


    this->roundHandler->setSettings(this->settings);

    // int startRound = this->roundHandler->getRound();
    int startRound = 0;
    if(startRound > numOfRounds) {
        os << "All rounds have finished." << endl;
        return;
    }
    for (int round = startRound; round <= numOfRounds; round++)
    {
        Utility::clearScreen();



        // os << "Round " << round + 1 << "!" << endl;
        if(isRandom)
        {
            roundHandler->deck->shuffleDeck(true);
        }
        // else
        // {
        //     roundHandler->deck->shuffleDeck(false);
        // }


        vector<Player*> winners = roundHandler->startRound(is, os, this->playerList, this->roundHistory);


        display->displayWinner(os, winners, roundHandler->getPot());



        bool continuePlaying = optionToLeave(is, os);

        if (!continuePlaying)
        {
            for (int i = playerList->size() - 1; i >= 0; i--)
            {
                delete playerList->at(i);
            }
            playerList->clear();
            gameRunning = false;
            return;
        }
        
        Player* gameWinner = this->roundHandler->resetRound(this->playerList, isRandom);

        if (gameWinner)
        {
            string exit;
            Utility::clearScreen();
            os << "THE GAME WINNER IS " << gameWinner->getName() << " WITH " << gameWinner->getBalance() << endl;
            os << "Enter anything to continue." << endl;
            is >> exit;

            for (unsigned int i = 0; i < playerList->size(); i++)
            {
                delete playerList->at(i);
            }
            this->playerList->clear();
            this->roundHandler->setRound(0);
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
    os << "3. save" << endl;

    int input = 0;

    while (!(is >> input) || (input != 1 && input != 2 && input != 3))
    {
        Utility::clearScreen();
        os << "Round " << round << " complete!" << endl;
        os << "Would you like to continue playing?" << endl;
        os << "1. yes" << endl;
        os << "2. no" << endl;
        os << "3. save" << endl;
        os << "Invalid input. Try again" << endl;

        is.clear();
        is.ignore(256, '\n');
    }

    if (input == 1)
    {
        return true;
    }
    if(input == 3) {
        is.ignore();
        os << "enter a name for the save file (no spaces) :" << endl;
        string fileName;
        getline(is, fileName);
        while(fileName.find(' ') != std::string::npos) {
            os << "Contains spaces. Try again." << endl;
            getline(is, fileName);
        }
        saveToFile(is, os, fileName);
    
    }
    this->roundHandler->setRound(0);
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
        }
        else if (input == "5")
        {
            cardRankingMenu(is, os);
        }
        else if (input == "6")
        {
            cardComboMenu(is, os);
        }
        else if (input == "7")
        {
            loadMenu(is, os);
            inMenu = false;
        }
        else if (input == "q")
        {
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

void GameHandler::loadMenu(istream &is, ostream &os) {
    string fileName;
    os << "Enter the name of the save file." << endl;
    is.ignore();

    getline(is, fileName);
    while(fileName.find(' ') != std::string::npos) {
        os << "Contains spaces. Try again." << endl;
        getline(is, fileName);
    }
    loadFromFile(is, os, fileName);

    loadingGame = true;
}


void GameHandler::saveToFile(istream& is, ostream& os, string fileName) {
    string filePath = "savefiles/" + fileName;
    ofstream saveFile(filePath);
    while(!saveFile.is_open()) {
        os << "FILE COULD NOT BE SAVED." << endl;
        os << "TRY AGAIN." << endl;
        is >> fileName;
        filePath = "savefiles/" + fileName;
        saveFile.open(filePath);
    }
    
    saveFile << "Big_Blind: " << settings->getBigBlindAmt() << endl;
    saveFile << "Little_Blind: " << settings->getLittleBlindAmt() << endl;
    saveFile << "Num_Of_Rounds: " <<  settings->getNumOfRounds() << endl;
    saveFile << "Num_Players: " << settings->getNumPlayers() << endl;
    saveFile << "Starting_Chips: " << settings->getStartingChips() << endl;

    saveFile << "Players: ";
    for(unsigned int i = 0; i < playerList->size(); i++) {
        saveFile << getPlayerList().at(i)->getName() << " " << getPlayerList().at(i)->getBalance() << endl;
    }

    saveFile << "Current_Round: ";
    saveFile << getRoundHandler()->getRound() << endl;
    saveFile << "Dealer_Index: ";
    saveFile << getRoundHandler()->getDealerIndex() << endl;
    saveFile.close();
}

void GameHandler::loadFromFile(istream& is, ostream& os, string fileName) {
    string filePath = "savefiles/" + fileName;
    ifstream loadFile(filePath);
    while(!loadFile.is_open()) {
        os << "LOAD FILE CANNOT BE FOUND." << endl;
        os << "TRY AGAIN." << endl;
        is >> fileName;
        filePath = "savefiles/" + fileName;
        loadFile.open(filePath);
    }

    string str;
    string name;
    int bigBlind, littleBlind, numRounds, numPlayers,
    startingChips, balance, currentRound, dealerIndex;
    if(loadFile >> str) {
        loadFile >> bigBlind;
        settings->setBigBlindAmt(bigBlind);
    }
    if(loadFile >> str) {
        loadFile >> littleBlind;
        settings->setLittleBlindAmt(littleBlind);
    }
    if(loadFile >> str) {
        loadFile >> numRounds;
        settings->setNumOfRounds(numRounds);
    }
    if(loadFile >> str) {
        loadFile >> numPlayers;
        settings->setNumPlayers(numPlayers);
    }
    if(loadFile >> str) {
        loadFile >> startingChips;
        settings->setStartingChips(startingChips);
    }
    if(loadFile >> str) {
        for(unsigned int i = 0; i < numPlayers; i++) {
            if(loadFile >> name >> balance) {
                Player* newPlayer = new Player(name, balance, false);
                playerList->push_back(newPlayer);
                
            }
        }
    }
    if(loadFile >> str) {
        loadFile >> currentRound;
        roundHandler->setRound(currentRound + 1);
    }
    if(loadFile >> str) {
        loadFile >> dealerIndex;
        roundHandler->setDealerIndex((dealerIndex + 1) % playerList->size());
    }
    

    
}
