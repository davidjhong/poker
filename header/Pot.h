#pragma once
// #include <Player.h>
#include <vector>


class Pot {
 public: 
    Pot();
    ~Pot();
   int getPot();
    void addToPot(int);

 private:
    
   //  void splitPot(const vector<Player>&);
   int totalPot;
};