#include "../header/Settings.h"
#include <assert.h>



Settings::Settings()
{
    this->numPlayers = 2;
    this->startingChips = 1000;
    this->bigBlindAmt = 50;
    this->littleBlindAmt = 25;
    this->numOfRounds = 5;
}

unsigned int Settings::getNumPlayers() const
{
    return this->numPlayers;
}

unsigned int Settings::getStartingChips() const
{
    return this->startingChips;
}

unsigned int Settings::getBigBlindAmt() const
{
    return this->bigBlindAmt;
}

unsigned int Settings::getLittleBlindAmt() const
{
    return this->littleBlindAmt;
}

unsigned int Settings::getNumOfRounds() const
{
    return this->numOfRounds;
}

void Settings::setNumPlayers(unsigned int newNumPlayers)
{
    assert(newNumPlayers >= 2 && "Tried setting to less than 2 players");
    assert(newNumPlayers <= 7 && "Tried setting to more than 7 players");
    this->numPlayers = newNumPlayers;
}

void Settings::setStartingChips(unsigned int newStartingChips)
{
    assert(newStartingChips < 50000 && "Only up to 50000 starting chips");
    this->startingChips = newStartingChips;
}

void Settings::setBigBlindAmt(unsigned int newBigBlindAmt)
{
    this->bigBlindAmt = newBigBlindAmt;
}

void Settings::setLittleBlindAmt(unsigned int newLittleBlindAmt)
{
    this->littleBlindAmt = newLittleBlindAmt;
}

void Settings::setNumOfRounds(unsigned int newNumOfRounds)
{
    assert(newNumOfRounds <= 100 && "Up to 100 rounds");
    this->numOfRounds = newNumOfRounds;
}