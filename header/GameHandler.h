#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

// #include "Display.h"
#include "RoundHandler.h"
#include "Player.h"
#include <ostream>
#include <vector>


class GameHandler
{
    private:
        // settings
        // RoundHandler* roundHandler;
        vector<Player*> playerList;
        // Display* display;

        void menuOptions(ostream&);
    public:
        GameHandler();
        ~GameHandler();
        void startGame();

        void setSettings();
        void addPlayer(const string &playerName);


        void getPlayers() const;
};

#endif