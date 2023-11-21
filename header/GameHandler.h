#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

// #include "Display.h"
#include "RoundHandler.h"
#include "Player.h"
#include "Settings.h"
#include <ostream>
#include <vector>


class GameHandler
{
    private:
        Settings* settings;
        // RoundHandler* roundHandler;
        vector<Player*> playerList;
        // Display* display;
        bool gameRunning;

        void menuOptions(ostream&);
    public:
        GameHandler();
        ~GameHandler();
        void startGame();

        void settingsMenu(ostream&);
        void rulesMenu(ostream&);
        void addPlayer(const string &playerName);
};

#endif