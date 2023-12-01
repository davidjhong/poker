#include "../header/handRank.h"
#include <vector>
#include <algorithm>

using namespace std;

// Max possible cards size : 7; (2 in hand, 5 on board). Minimum : 2 (hand value)
bool comp(Card* card1, Card* card2)
{
    return card1->getRank() < card2->getRank(); // For sorting cards in order
}

int HandRank::hasHighCard() 
{
    int highestCard = 0;
    int currRank = 0;
    for (int i = 0; i < cards.size(); i++) {
        currRank = cards[i]->getRank();
        if (currRank > highestCard) {
            highestCard = cards[i]->getRank();
        }
    }
    
    return highestCard; // All hands have a high card. Issue is to determine which high card has a higher value.
}

int HandRank::hasPair()  
{
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank()) {
            return cards[i]->getRank() + 50;
        }
    }
    return -1;
}

int HandRank::hasTwoPair() 
{
    int numPairs = 0;
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank()) {
            numPairs++;
            ++i; // Move to next i
        }

    if (numPairs == 2) {
        return cards[i]->getRank() + 100;
    }

    } 


    return -1; // No such thing as three pair, four pair, or so on... 
}

int HandRank::hasThreeOfKind() 
{
    for (int i = 0; i < cards.size()-2; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank() && cards[i+1]->getRank() == cards[i+2]->getRank()) {
            return cards[i]->getRank() + 150;
        }
    } 
    return -1;
}

bool HandRank::hasStraight() const 
{
    int count = 0;
    for (int i = 0; i < cards.size() - 1; ++i) {

        int currRank = cards[i]->getRank();
        if ((currRank + 1) == cards[i+1]->getRank()) {
            ++count;
            if (count == 5) {
                return true;
            }
        }
    }

    return false;
}

bool HandRank::hasFlush() const 
{
    return false;
}

bool HandRank::hasFullHouse() const
{
    return false;
}

bool HandRank::hasFourOfKind() const
{
    return false;
}

bool HandRank::hasStraightFlush() const
{
    return false;
}

bool HandRank::hasRoyalFlush() const 
{
    return false;
}

int HandRank::getFinalRank(vector<Card*> hand) 
{
    this->cards = hand;
    sort(cards.begin(), cards.end(), comp);

    int highCard = hasHighCard();
    int pairVal = hasPair();
    int twoPairVal = hasTwoPair();
    int threeOfKindVal = hasThreeOfKind();

    if (threeOfKindVal != -1)
    {
        return threeOfKindVal;
    }

    else if (twoPairVal != -1) 
    {
        return twoPairVal;
    }

    else if (pairVal != -1) 
    {
        return pairVal;
    }

    else 
    {
        return highCard;
    }
}