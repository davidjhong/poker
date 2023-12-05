#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../header/Bot.h"

Bot::Bot(const string &name, int chips) : Player(name, chips, true)
{
    this->actions = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4};
}

int Bot::randomAction() 
{
    srand(static_cast<unsigned int>(time(nullptr))); 
    int index = rand() % actions.size(); 
    return actions[index];
}