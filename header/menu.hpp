#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#ifndef MENU_HPP
#define MENU_HPP
using namespace std;

class Display
{
    public:
        void displayMenu(ostream& out);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        
};

    

#endif