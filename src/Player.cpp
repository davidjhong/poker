#include "../header/Player.h"
#include <assert.h>


Player::Player() {
    name = "";
    balance = 0;
}

Player::Player(string name, int balance) {
    this->name = name;
    this->balance = balance;
    this->hand = new Hand();
    this->isPlaying = true;
}

Player::~Player() {
    delete hand;
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


void Player::setCurrentBet(int newBet) {
    this->balance -= newBet - currentBet;
    this->currentBet = newBet;
}

int Player::getCurrentBet() {
    return currentBet;
}

void Player::clearCurrentBet() {
    currentBet = 0;
}

bool Player::getIsPlaying() const
{
    return this->isPlaying;
}

void Player::setIsPlaying(bool status)
{
    this->isPlaying = status;
}