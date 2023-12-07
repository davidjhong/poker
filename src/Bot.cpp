#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../header/Bot.h"

Bot::Bot(const string &name, int chips, bool isRandom) : Player(name, chips, true)
{
    this->isRandom = isRandom;
    this->actions = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4};
}

int Bot::randomAction() 
{
    if (isRandom) 
    {
        srand(static_cast<unsigned int>(time(nullptr))); 
        int index = rand() % actions.size(); 
        return actions[index];
    }
    else
    {
        return actions[0];
    }
}