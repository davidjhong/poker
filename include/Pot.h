#pragma once
// #include <Player.h>
#include <vector>


class Pot {
 public: 
    Pot();
    ~Pot();
    const unsigned int getPot();

 private:
    void addToPot(const unsigned int);
   //  void splitPot(const vector<Player>&);
    int totalPot = 0;
};