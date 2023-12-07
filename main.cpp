#include <iostream>

#include "./header/GameHandler.h"

using namespace std;


int main()
{
    GameHandler* game = new GameHandler(true);

    game->runGame(cin, cout);

    delete game;
    
    return 0;
}