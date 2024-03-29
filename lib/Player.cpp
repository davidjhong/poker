#include "../include/Player.h"


Player::Player(const string name, unsigned int balance) {
    setName(name);
    setBalance(balance);
}

Player::~Player() {
 //   delete hand;
}

void Player::call(unsigned int num) {
    // in a vector of players, "raise" current bet
    // to previous player's bet. add to pot accordingly
}

void Player::raise(unsigned int num) {
    // add to Pot of num
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

void Player::setBalance(unsigned int bal) {
    this->balance = bal;
} 
void Player::setName(string name) {
    this->name = name;
}
void Player::addToBalance(unsigned int amount) {
    this->balance += amount;
}
