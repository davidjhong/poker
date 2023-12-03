#include "../header/Hand.h"
#include "../header/handRank.h"
#include <iostream>
#include <assert.h>


Hand::Hand()
{
    this->strength = 0;
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

void Hand::calculateStrength(vector<Card*> &communityCards)
{
    HandRank* handRanker = new HandRank();

    vector<Card*> allCards;
    
    for (Card* card: hand)
    {
        allCards.push_back(card);
    }

    for (Card* card: communityCards)
    {
        allCards.push_back(card);
    }
    
    this->strength = handRanker->getFinalRank(allCards);

    delete handRanker;
}

void Hand::addCard(Card* newCard)
{
    // cout << hand.size() << endl;
    assert(hand.size() < 2 && "Tried adding card to a hand of 2 cards, which is the max");

    this->hand.push_back(newCard);
    
}

string Hand::getComboName()
{
    if (strength <= 50)
    {
        return "High Card";
    }
    else if (strength <= 100)
    {
        return "Pair";
    }
    else if (strength <= 150)
    {
        return "Two Pair";
    }
    else if (strength <= 200)
    {
        return "Three of a Kind";
    }
    else if (strength <= 250)
    {
        return "Straight";
    }
    //else if() flush 
    //
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