#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

// #include "Display.h"
#include "RoundHandler.h"
#include "Player.h"
#include "Settings.h"
#include "Display.h"
#include "Utility.h"
#include <ostream>
#include <vector>


class GameHandler
{
    private:
        
        RoundHandler* roundHandler;
        vector<Player*> *playerList;
        vector<vector<string>> roundHistory;
        Display* display;
        bool gameRunning;
        bool isRandom;

     
       
  
        void loadMenu(istream&, ostream&);

        bool loadingGame = false;
    public:
        GameHandler();
        GameHandler(bool isRandom);
        ~GameHandler();
        void runGame(istream&, ostream&);
        void addPlayer(const string &playerName, bool);
        bool optionToLeave(istream&, ostream&);
        void startGame(istream&, ostream&);
        void gameSetup(istream&, ostream&, bool);
        Settings* settings;

        void settingsMenu(istream&, ostream&);
        void rulesMenu(istream&, ostream&);
        bool menuOptions(istream&, ostream&);
        void cardRankingMenu(istream&, ostream&);
        void cardComboMenu(istream&, ostream&);

        void saveToFile(string);
        void loadFromFile(string);
        vector<Player*>& getPlayerList() { return *playerList;};       
        Settings* getSettings() { return settings;};
        RoundHandler* getRoundHandler() { return roundHandler;};
};

#endif