#include "../header/Pot.h"
#include <assert.h>

Pot::Pot() {
    this->totalPot = 0;
}

/*Pot::Pot(vector<Player*> pVec) {
    potPlayerVec = pVec;
}*/

Pot::~Pot() {
    //delete Pot;
}


void Pot::addToPot(int amount) {
    
    totalPot = totalPot + amount;
    if(amount > highestBet) {
        highestBet = amount;
    }
}

void Pot::setHighestBet(int amount)
{
    this->highestBet = amount;
}

int Pot::getHighestBet() const
{
    return this->highestBet;
}

int Pot::getPot() {
    return this->totalPot;
}

void Pot::resetPot() {
    this->totalPot = 0;
    this->highestBet = 0;
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