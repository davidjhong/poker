#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../header/Pot.h"
#include "../header/Player.h"
#include "../header/Settings.h"


using namespace std;

class Display
{

    public:
        void displayMenu(ostream&);
        void displayCardRankings(ostream&);
        void displayRules(ostream&);
        void displayCardCombinations(ostream&);
        void displayPlayerStats(ostream&, Player*, Hand*, Pot*);
        void displayGameStatus(std::ostream&, Player*, Pot*);
        void displayGameOver(std::ostream&);
        void displaySettings(std::ostream&);
        void displayBetweenTurns(std::ostream&);
        // void displayCommunityCards(std::ostream&);
        // void displayWinner(std:: ostream&);

};

#endif

