
#pragma once

#include <string>
#include <iostream>

#include "Hand.h"
using namespace std;

class Player {
public:
   Player(const string name, unsigned int balance);
   ~Player();
   void call(unsigned int);
   void raise(unsigned int);
   const void fold();
   const void check();

   int getBestHand();
   int getBalance();
   Hand* getHand();
   string getName();

private:
   Hand* hand;
   int bestHand;
   int balance;
   string name;
   void setBalance(unsigned int);
   void setName(string);
   void addToBalance(unsigned int);



};