#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H

// #include "Display.h"
#include "RoundHandler.h"
#include "Player.h"
#include "Settings.h"
#include "Display.h"
#include <ostream>
#include <vector>


class GameHandler
{
    private:
        Settings* settings;
        RoundHandler* roundHandler;
        vector<Player*> *playerList;
        vector<vector<string>> roundHistory;
        Display* display;
        bool gameRunning;

        void gameSetup(istream&, ostream&);
        void startGame(istream&, ostream&);
        bool optionToLeave(istream&m, ostream&);

        void settingsMenu(ostream&);
        void rulesMenu(ostream&);
        void menuOptions(istream&, ostream&);
        void cardRankingMenu(ostream&);
        void cardComboMenu(ostream&);
        void loadMenu(istream&, ostream&);

        bool loadingGame = false;
    public:
        GameHandler();
        ~GameHandler();
        void startGame();
        void addPlayer(const string &playerName);

        void saveToFile(string);
        void loadFromFile(string);
        vector<Player*>& getPlayerList() { return *playerList;};       
        Settings* getSettings() { return settings;};
        RoundHandler* getRoundHandler() { return roundHandler;};
        


};

#endif