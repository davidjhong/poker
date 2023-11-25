
#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include "Hand.h"
#include "Pot.h"
using namespace std;

class Player {
public:
   Player(const string name, unsigned int balance);
   ~Player();
   void placeBet(int);
   void call(ostream& out);
   void raise(unsigned int);
   const void fold();
   const void check();


   
   int getBestHand();
   int getBalance();
   Hand* getHand();
   string getName();

   void clearBetStatus();
   int getCurrentBet();
   void setCurrentBet(int);
   void clearCurrentBet();

   int currentBet = 0;

   bool betPlaced = false;


private:
   Hand* hand;
   int bestHand;
   int balance;
   string name;
   void setBalance(unsigned int);
   void setName(string);
   void addToBalance(unsigned int);

   


};