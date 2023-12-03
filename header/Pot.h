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
   int getHighestBet() const;
   void setHighestBet(int);


private:
    
   //  void splitPot(const vector<Player>&);
   int highestBet = 0;
   int totalPot = 0;
};