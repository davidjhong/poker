#include "../include/handRank.h"
#include <vector>
#include <algorithm>

using namespace std;

// Max possible cards size : 7; (2 in hand, 5 on board). Minimum : 2 (hand value)
bool comp(Card* card1, Card* card2)
{
    return card1->getRank() < card2->getRank(); // For sorting cards in order
}

bool HandRank::hasHighCard() const 
{
    return true; // All hands have a high card. Issue is to determine which high card has a higher value.
}

bool HandRank::hasPair() const 
{
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank()) {
            return true;
        }
    }
    return false;
}

bool HandRank::hasTwoPair() const 
{
    int numPairs = 0;
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank()) {
            numPairs++;
            ++i; // Move to next i
        }
    } 
    return numPairs >= 2; // No such thing as three pair, four pair, or so on... 
}

bool HandRank::hasThreeOfKind() const {
    if (cards.size() < 3) {
        return false; // If card size is less than 3 three of a kind is not possible
    }
}

bool HandRank::hasFlush() const {

}

bool HandRank::hasFullHouse() const
{

}

bool HandRank::hasFourOfKind() const
{

}

bool HandRank::hasStraightFlush() const
{

}

bool HandRank::hasRoyalFlush() const 
{

}

int HandRank::getFinalRank(vector<Card*> hand) 
{
    this->cards = hand;
    sort(cards.begin(), cards.end(), comp);

    else if (hasStraight()) {
        return 250;
    }
    else if (hasThreeOfKind()) {
        return 200;
    }
    else if (hasTwoPair()) {
        return 150;
    }
    else if (hasPair()) {
        return 100;
    }
    else if (hasHighCard()) {
        return 50;
    }
}