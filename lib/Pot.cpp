#include "../include/Pot.h"

Pot::Pot() {
    this->totalPot = 0;
}

Pot::~Pot() {
    //delete Pot;
}


void Pot::addToPot(int amount) {
    totalPot = totalPot + amount;
}

int Pot::getPot() {
    return totalPot;
}


// how is the pot split if the "chips" are odd?
// the player closest to the dealer (left of little blind) will get the remaining odd "chips"
/*void Pot::splitPot(const vector<Player>& playerVec) {
    int numWinners = playerVec.size();
    double potTot = getPot();
    if(potTot % numWinners != 0) { // double cast to

    }
    else {
        const int splitAmount = getPot();
        for(unsigned int i = 0; i < numWinners; i++) {
            playerVec.at(i).addToBalance(splitAmount);
        }
    }
}*/