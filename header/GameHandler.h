#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

// #include "Display.h"
#include "RoundHandler.h"
#include "Player.h"
#include "Settings.h"
#include "Display.h"
#include <ostream>
#include <vector>
#include <fstream>

class GameHandler
{
    private:
        Settings* settings;
        RoundHandler* roundHandler;
        vector<Player*> *playerList;
        // Player*[] playerList;
        Display* display;
        bool gameRunning;

        void gameSetup(istream&, ostream&);
        void settingsMenu(ostream&);
        void rulesMenu(ostream&);
        void menuOptions(ostream&);
        void cardRankingMenu(ostream&);
        void cardComboMenu(ostream&);
    public:
        GameHandler();
        ~GameHandler();
        void startGame();
        void addPlayer(const string &playerName);

        void saveToFile(string);
        void loadFromFile(string);
        vector<Player*> getPlayerList();
};

#endif