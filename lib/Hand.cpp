#include "../include/Hand.h"
#include "../include/handRank.h"
#include <iostream>
#include <assert.h>


Hand::Hand()
{
    this->strength = 0;
}

int Hand::getStrength() const
{
    return this->strength;
}

void Hand::calculateStrength()
{
    HandRank* handRanker = new HandRank();
    
    this->strength = handRanker->getFinalRank(this->hand);

    delete handRanker;
}

void Hand::addCard(Card* newCard)
{
    assert(hand.size() < 7 && "Tried adding card to a hand of 7 cards, which is the max");

    this->hand.push_back(newCard);
    return;
}

void Hand::clearHand()
{
    this->hand.clear();
}

vector<Card*> Hand::getHand()
{
    return this->hand;
}

vector<string> Hand::getCardNames()
{
    vector<string> cardNames;
    for (auto card: hand)
    {
        cardNames.push_back(card->getName());
    }
    return cardNames;
}