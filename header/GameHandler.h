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
        void runGame(istream&, ostream&);
        void addPlayer(const string &playerName, bool);
        Settings* settings;
        RoundHandler* roundHandler;
        vector<Player*> *playerList;
        vector<vector<string>> roundHistory;
        Display* display;
        bool gameRunning;

        void gameSetup(istream&, ostream&, bool);
        void startGame(istream&, ostream&);
        bool optionToLeave(istream&, ostream&);

        void settingsMenu(istream&, ostream&);
        void rulesMenu(istream&, ostream&);
        bool menuOptions(istream&, ostream&);
        void cardRankingMenu(istream&, ostream&);
        void cardComboMenu(istream&, ostream&);
};

#endif