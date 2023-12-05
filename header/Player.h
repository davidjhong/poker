
#pragma once

#include <string>
#include <iostream>
#include <ostream>
#include "Hand.h"
#include "Pot.h"
using namespace std;

class Player {
public:
   Player();
   Player(const string&, int, bool);
   // ~Player();
   virtual ~Player();
   // void placeBet(int);
  // void raise(unsigned int);
   //const void fold();
   //const void check();
   
   void setBalance(unsigned int);
   void setName(string);
   void addToBalance(unsigned int);
   int getBalance();
   Hand* getHand();
   string getName();

   int getCurrentBet();
   void setCurrentBet(int);
   void clearCurrentBet();

   void resetHand();
   
   bool getIsBot() const;
   bool getIsPlaying() const;
   void setIsPlaying(bool);

protected:
   int currentBet = 0;
   Hand* hand;
   int balance;
   bool isPlaying;
   bool isBot;
   string name;
};