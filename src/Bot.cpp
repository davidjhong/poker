#include <iostream>
#include "../header/Bot.h"

int Bot::randomAction() {
    int index = rand() % actions.size(); /
    int action = actions[index]; 

    if (action >= 1 && action <= 4) {
        unsigned int amount = 0;
        if (action == 1) {
            //todo
        } else if (action == 2) {
            //todo
        } else if (action == 3) {
            //todo
        } else if (action == 4) {
            //todo
        }
    }

    return action;
}