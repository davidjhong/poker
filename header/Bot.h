#ifndef BOT_H
#define BOT_H
#include "../header/Player.h"
#include <cstdlib> 
#include <vector>
using namespace std;

class Bot : public Player
{
    private:
        bool isRandom;
        vector<int> actions;
    public:
        Bot(const string&, int, bool);
        int randomAction();
};



#endif