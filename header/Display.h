#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
using namespace std;

class Display
{
    public:
        void displayMenu(ostream& out);
        void displaySettings(ostream&);
        void displayCardRankings(ostream& out);
        void displayRules(ostream& out);
        void displayCardCombinations(ostream& out);
        
};

    

#endif