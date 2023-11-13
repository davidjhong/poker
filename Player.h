
#pragma once

#include <string>
#include <iostream>
using namespace std;

class Player {
 public:
    Player(const string name, unsigned int balance);
    ~Player();
    void call(unsigned int);
    void raise(unsigned int);
    const void fold();
    const void check();

    Hand hand; // !
    
    int getBestHand();
    const int getBalance();
    const string getName();





 private:
    int bestHand;
    int balance;
    string name;
    void setBalance(const unsigned int);
    void setName(const string);
    friend void addToBalance(const unsigned int);



};