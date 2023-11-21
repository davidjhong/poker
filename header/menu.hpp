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
    Player* player;

    public:
        void displayMenu(ostream& out);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        void displayPlayerBets(ostream& out, Player* player);
        string getName()
        {
            return playerName;
        }
        int getBalance()
        {
            return balance;
        }
};

#endif