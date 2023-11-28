#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>

#include "Player.h"
#include "Hand.h"
#include "Pot.h"

using namespace std;

class Display
{


    public:
        void displayMenu(ostream& out);
        void displaySettings(ostream&);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        void displayPlayerStats(ostream& out, Player* player, Hand* hand, Pot* pot);
        void displayGameStatus(std::ostream& out, Player* player, Pot* pot);
        
};

#endif

