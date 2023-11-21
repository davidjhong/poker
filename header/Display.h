#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#ifndef DISPLAY_H
#define DISPLAY_H
using namespace std;

class Display
{

    public:
        void displayMenu(ostream& out);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        void displayPlayerStats(ostream& out, Player* player, Hand* hand, Pot* pot);
        void displayGameStatus(std::ostream& out, Player* player, Pot* pot)
        
};

#endif
