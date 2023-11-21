#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#ifndef MENU_HPP
#define MENU_HPP
using namespace std;

class Display
{
    private:
    string playerName;
    int balance;

    public:
        void displayMenu(ostream& out);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        void displayPlayerStats(ostream& out, Player* player, Hand* hand, Pot* pot);
        void displayGameStatus(std::ostream& out, Player* player, Pot* pot)
        
};

#endif