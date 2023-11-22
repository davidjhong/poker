#pragma once
#include "Player.h"
#include <vector>


class Pot {
public: 
   Pot();
   Pot(vector<Player*> pVec);
   ~Pot();
   int getPot();

   void resetPot();
   void addToPot(int);

   vector<Player*> potPlayerVec;

   int highestBet = 0;

private:
    
   //  void splitPot(const vector<Player>&);
   int totalPot = 0;
};