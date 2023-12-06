#include <iostream>

#include "./header/GameHandler.h"
#include "./header/Deck.h"

using namespace std;


int main()
{
    GameHandler game;

    game.runGame(cin, cout);
    
    return 0;
}