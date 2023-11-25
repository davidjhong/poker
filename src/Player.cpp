#include "../header/Player.h"
#include <assert.h>


Player::Player(const string name, unsigned int balance) {
    setName(name);
    setBalance(balance);
    this->hand = new Hand();
}

Player::~Player() {
    delete hand;
}

// when player places bet, calls, or raises
// make sure to change currentBet, as well as betPlaced
// when betting with betPlaced, this can't be possible, they have to call
// when betting with noBetPlaced, make sure that prev Player hasn't already bet,
// and if so, make sure they can either call or raise
// when calling with betPlaced, balance = (num - currBet), currBet = num
// when calling with no betPlaced, balance -= num, currBet = num
// when raising with betPlaced, balance = (num - currBet), currBet = num
// when raising with no betPlaced, balance -= num, currBet = num

void Player::placeBet(int bet) {
    assert(bet > balance && "Can't bet more than your balance");
    assert(bet <= 0 && "Can't bet zero chips");
    currentBet = bet;
    betPlaced = true;
}


void Player::call(ostream& out) {
    assert(highestBet != 0 && "Can't call when there has been no bet");
    assert(getCurrentBet() + balance < highestBet)
    if(highestBet > balance ) {
        string response;
        out << "Are you sure you'd like to all in? Y/N (Balance is less than call.)" << endl;
        cin >> response;
        while(response == "Y" || response == "y" || response == "N" || response == "n") {
            if(response == "Y" || response == "y") {
                out << "ALL IN." << endl;
                if(betPlaced) {
                    currentBet = balance + currentBet;
                    placeBet(balance);
                }
                else {
                    currentBet = balance;
                    placeBet(balance);
                }
                betPlaced = true;
            }
            // how to make sure it goes back to regular options?
            else if(response == "N" || response == "n") {
                out << "Choose another option." << endl;
                break;
            }
            else {
                out << "Invalid option. Type Y/N." << endl;
            }
        }
        
    }
    else {
        placeBet(highestBet - currentBet);
        betPlaced = true;
    }

    betPlaced = true;
    // in a vector of players, "raise" current bet
    // to previous player's bet. add to pot accordingly
}

void Player::raise(unsigned int num) {
    assert((getCurrentBet() + balance) < num && "Can't raise more than your balance.");
    if(betPlaced) {
        currentBet = num;
        placeBet(num - currentBet);
    }
    else{
        currentBet = num;
        placeBet(num);
    }
    betPlaced = true;
}

int Player::getBestHand() {
    return bestHand;
}

int Player::getBalance() {
    return balance;
}

string Player::getName() {
    return name;
}

Hand* Player::getHand()
{
    return this->hand;
}

void Player::setBalance(unsigned int bal) {
    this->balance = bal;
} 
void Player::setName(string name) {
    this->name = name;
}
void Player::addToBalance(unsigned int amount) {
    this->balance += amount;
}


void Player::setCurrentBet(int b) {
    currentBet = b;
}

int Player::getCurrentBet() {
    return currentBet;
}

void Player::clearBetStatus() {
    betPlaced = false;
}

void Player::clearCurrentBet() {
    currentBet = 0;
}