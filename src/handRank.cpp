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

// The cards are sorted in ascending order before calling the functions
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
    for (int i = 0; i < cards.size()-1; i++) 
    {
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
        if (cards[i]->getRank() == cards[i+1]->getRank() && cards[i+1]->getRank() == cards[i+2]->getRank()) 
        {
            return cards[i]->getRank() + 150; // Return true if there are three of the same rank in the board and hand
        }
    } 
    return -1;
}

int HandRank::hasStraight() 
{
    if (cards.size() < 5) {
        return -1;
    }

    for (int i = 0; i < cards.size() - 4; ++i) { // Check if the ranks are in a straight order... ex. 1,2,3,4,5
        if (
            cards[i]->getRank() + 1 == cards[i+1]->getRank() &&
            cards[i]->getRank() + 2 == cards[i+2]->getRank() &&
            cards[i]->getRank() + 3 == cards[i+3]->getRank() &&
            cards[i]->getRank() + 4 == cards[i+4]->getRank() 
           ) 
        {
            return (cards[i]->getRank() + 4) + 200; // Get the value of the strongest card in the straight draw.
        }
    }

    return -1;
}

bool HandRank::hasFlush() const 
{
    return false;
}

bool HandRank::hasFullHouse() const
{
    return false;
}

int HandRank::hasFourOfKind() 
{
    for (int i = 0; i < cards.size()-3; i++) {
        if (cards[i]->getRank() == cards[i+1]->getRank() && cards[i+1]->getRank() == cards[i+2]->getRank() && cards[i+2]->getRank() == cards[i+3]->getRank()) 
        {
            return cards[i]->getRank() + 350; // Return true if there are three of the same rank in the board and hand
        }
    } 

    return -1;
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
    sort(cards.begin(), cards.end(), comp); // sort the cards in ascending order

    // highcard - lowest ranking, royal flush - highest ranking
    int highCard = hasHighCard();
    int pairVal = hasPair();
    int twoPairVal = hasTwoPair();
    int threeOfKindVal = hasThreeOfKind();
    int straightVal = hasStraight();

    int fourOfKindVal = hasFourOfKind();

    if (fourOfKindVal != -1)
    {
        return fourOfKindVal;
    }

    else if (straightVal != -1) 
    {
        return straightVal;
    }

    else if (threeOfKindVal != -1)
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