#include <iostream>
#include "../header/Bot.h"

int Bot::randomAction() 
{
    srand(static_cast<unsigned int>(time(nullptr))); 
    int index = rand() % actions.size(); 
    return actions[index];
}