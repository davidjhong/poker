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
    public:
        GameHandler();
        ~GameHandler();
        void startGame();
        void addPlayer(const string &playerName, bool);
        Settings* settings;
        RoundHandler* roundHandler;
        vector<Player*> *playerList;
        vector<vector<string>> roundHistory;
        Display* display;
        bool gameRunning;

        void gameSetup(istream&, ostream&, bool);
        void startGame(istream&, ostream&);
        bool optionToLeave(istream&m, ostream&);

        void settingsMenu(ostream&);
        void rulesMenu(ostream&);
        bool menuOptions(ostream&);
        void cardRankingMenu(ostream&);
        void cardComboMenu(ostream&);
};

#endif