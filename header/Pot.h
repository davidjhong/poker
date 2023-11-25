#pragma once
#include "Player.h"
#include <vector>

using namespace std;

class Player;

class Pot {
public: 
   Pot();
   Pot(vector<Player*> pVec);
   ~Pot();
   int getPot();

   void resetPot();
   void addToPot(int);

   int highestBet = 0;

private:
    
   //  void splitPot(const vector<Player>&);
   int totalPot = 0;
};