#include "../header/Pot.h"
#include <assert.h>

Pot::Pot() {
    this->totalPot = 0;
}

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


