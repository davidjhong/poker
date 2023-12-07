#ifndef BOT_H
#define BOT_H
#include "../header/Player.h"
#include <cstdlib> 
#include <vector>
using namespace std;

class Bot : public Player
{
    private:
        vector<int> actions;
    public:
        Bot(const string&, int);
        int randomAction(bool isSetSeed);
};



#endif