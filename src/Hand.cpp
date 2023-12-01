#include "../header/Hand.h"
#include "../header/handRank.h"
#include <iostream>
#include <assert.h>


Hand::Hand()
{
    this->strength = 0;
}

Hand::~Hand(){
    int handSize = hand.size();
    for(int i = handSize - 1; i >= 0; i--) {
        delete hand.at(i);
    }
}

Hand::Hand(vector<Card*> cards) {
    for (int i = 0; i < cards.size(); i++) {
        hand.push_back(cards[i]);
    }
}

int Hand::getStrength() const
{
    return this->strength;
}

Card* Hand::getCard(int i) const {
    if(i >= 0 && i < hand.size()) {
        return hand.at(i);
    }
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
    for (Card* card: hand)
    {
        cardNames.push_back(card->getName());
    }
    return cardNames;
}