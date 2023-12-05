#include "../header/Player.h"
#include <assert.h>


Player::Player() {
    name = "";
    balance = 0;
    this->hand = new Hand();
    this->isPlaying = true;
    this->isBot = false;
}

Player::Player(const string &name, int balance, bool isBot) {
    this->name = name;
    this->balance = balance;
    this->hand = new Hand();
    this->isPlaying = true;
    this->isBot = isBot;
}

Player::~Player() {
    delete hand;
}

void Player::resetHand() {
    this->hand->clearHand();
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

bool Player::getIsBot() const
{
    return this->isBot;
}