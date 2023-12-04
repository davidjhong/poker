#ifndef BOT_H
#define BOT_H
#include "../header/Player.h"
#include <cstdlib> 
#include <vector>
using namespace std;

class Bot
{
    private:
        vector<int> actions = { 1, 1, 1, 1, 1,1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,2, 2, 3, 3, 3, 3, 4 };

    public:
        int randomAction();
}



#endif