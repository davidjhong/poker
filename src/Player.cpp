#include "../header/Player.h"


Player::Player(const string name, unsigned int balance) {
    setName(name);
    setBalance(balance);
    this->hand = new Hand();
    this->isPlaying = true;
}

Player::~Player() {
    delete hand;
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

bool Player::isPlayingStatus() const
{
    return this->isPlaying;
}

void Player::setPlayingStatus(bool isPlaying)
{
    this->isPlaying = isPlaying;
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
