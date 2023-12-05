#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../header/Pot.h"
#include "../header/Player.h"
#include "../header/Settings.h"
#include "../header/Hand.h"

using namespace std;

class Display
{
    public:
        void displayMenu(ostream&);
        void displayCardRankings(ostream&);
        void displayRules(ostream&);
        void displayCardCombinations(ostream&);
        void displayCards(ostream&, vector<Card*>);
        void displayGameStatus(ostream&, vector<Card*> communityCards, Player*, Pot*);
        void displayBalanceChanges(std::ostream&, Player*, Pot*);
        void displayGameOver(std::ostream&);
        void displaySettings(std::ostream&);
        void displayBetweenTurns(std::ostream&, Player*);
        void displayRoundHistory(std::ostream&, const vector<vector<string>> &roundHistory);
        void displayWinner(std:: ostream&, vector<Player*>, Pot*);


};

#endif

