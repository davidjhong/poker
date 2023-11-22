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

void Player::placeBet(int bet) {
    assert(bet > balance && "Can't bet more than your balance");
    assert(bet <= 0 && "Can't bet zero chips");
    currentBet = bet;
}


void Player::call(unsigned int num) {
    
    // in a vector of players, "raise" current bet
    // to previous player's bet. add to pot accordingly
}

void Player::raise(unsigned int num) {
    
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

