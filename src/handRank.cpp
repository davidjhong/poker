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
    for (int i = 0; i < cards.size(); i++) 
    {
        currRank = cards[i]->getRank();
        if (currRank > highestCard) 
        {
            highestCard = cards[i]->getRank();
        }
    }
    
    return highestCard; // All hands have a high card. Issue is to determine which high card has a higher value.
}

// The cards are sorted in ascending order before calling the functions
int HandRank::hasPair()  
{
    for (int i = 0; i < cards.size()-1; i++) 
    {
        if (cards[i]->getRank() == cards[i+1]->getRank()) 
        {
            return cards[i]->getRank() + 50;
        }
    }
    return -1;
}

int HandRank::hasTwoPair() 
{
    if (cards.size() < 4) // Two pair needs at least four total cards.
    {
        return -1;
    }

    int numPairs = 0;
    for (int i = 0; i < cards.size()-1; i++) 
    {
        if (cards[i]->getRank() == cards[i+1]->getRank()) 
        {
            numPairs++;
            ++i; // Move to next i
        }

        if (numPairs == 2) 
        {
            return cards[i]->getRank() + 100;
        }

    } 


    return -1; // No such thing as three pair, four pair, or so on... 
}

int HandRank::hasThreeOfKind() 
{
    if (cards.size() < 3) // Three of kind at least needs 3 cards in total
    {
        return -1;
    }

    for (int i = 0; i < cards.size()-2; i++) 
    {
        if (cards[i]->getRank() == cards[i+1]->getRank() && cards[i+1]->getRank() == cards[i+2]->getRank()) 
        {
            return cards[i]->getRank() + 150; // Return true if there are three of the same rank in the board and hand
        }
    } 
    return -1;
}

int HandRank::hasStraight() 
{
    if (cards.size() < 5) // Straight cannot happen if theres less than five total cards
    {
        return -1;
    }

    for (int i = 0; i < cards.size() - 4; ++i) 
    { // Check if the ranks are in a straight order... ex. 1,2,3,4,5
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

int HandRank::hasFlush() 
{
    int diamondsCounter = 0;
    int clubsCounter = 0;
    int heartsCounter = 0;
    int spadesCounter = 0;

    if (cards.size() < 5) // Flush cannot happen if theres less than five total cards
    {
        return -1;
    }

    for (int i = 0; i < cards.size(); ++i)
    {
        if (cards[i]->getSuit() == "Diamonds")
        {
            diamondsCounter++;
        }

        if (cards[i]->getSuit() == "Clubs")
        {
            clubsCounter++;
        }

        if (cards[i]->getSuit() == "Hearts")
        {
            heartsCounter++;
        }

        if (cards[i]->getSuit() == "Spades")
        {
            spadesCounter++;
        }

        if (diamondsCounter >= 5 || clubsCounter >= 5 || heartsCounter >= 5 || spadesCounter >= 5)
        {
            return cards[i]->getRank() + 250;
        }
    }

    return -1;
}

int HandRank::hasFullHouse()
{
    if (cards.size() < 5) // FullHouse cannot happen if theres less than five total cards
    {
        return -1;
    }

    int threeOfKindVal = hasThreeOfKind();

    if (threeOfKindVal != -1) // we have a three of kind
    {
        // Check remaining cards for a pair. If there is a pair, there is a full house.
        for (int i = 0; i < cards.size(); i++)
        {
            if ((cards[i]->getRank() + 150) == threeOfKindVal)
            {
                continue; // Skip three of kind value
            }

            for (int j = i+1; j < cards.size(); j++)
            {
                if ((cards[i]->getRank() + 150) == threeOfKindVal)
                {
                    continue; // Skip three of kind value
                }
                
                if (cards[i]->getRank() == cards[j]->getRank()) // Find a pair explicitly
                {
                    return cards[i]->getRank() + (threeOfKindVal - 150) + 300; // Return the rank value of the three of kind card + pair + 300
                }
            }
        }
    }

    return -1;
}

int HandRank::hasFourOfKind() 
{
    if (cards.size() < 4)
    {
        return -1;
    }
    for (int i = 0; i < cards.size()-3; i++) 
    {
        if (cards[i]->getRank() == cards[i+1]->getRank() && cards[i+1]->getRank() == cards[i+2]->getRank() && cards[i+2]->getRank() == cards[i+3]->getRank()) 
        {
            return cards[i]->getRank() + 350; // Return true if there are three of the same rank in the board and hand
        }
    } 

    return -1;
}

int HandRank::hasStraightFlush()
{
    if (cards.size() < 5) // straight flush cannot happen if theres less than five total cards
    {
        return -1;
    }

    string flushSuit = "";
    int diamondsCounter = 0;
    int clubsCounter = 0;
    int heartsCounter = 0;
    int spadesCounter = 0;

    for (int i = 0; i < cards.size(); ++i) // Check for flush
    {
        if (cards[i]->getSuit() == "Diamonds")
        {
            diamondsCounter++;
        }

        if (cards[i]->getSuit() == "Clubs")
        {
            clubsCounter++;
        }

        if (cards[i]->getSuit() == "Hearts")
        {
            heartsCounter++;
        }

        if (cards[i]->getSuit() == "Spades")
        {
            spadesCounter++;
        }
    }

    if (diamondsCounter >= 5) // Assign flush suit accordingly
    {
        flushSuit = "Diamonds";
    }

    if (clubsCounter >= 5)
    {
        flushSuit = "Clubs";
    }

    if (heartsCounter >= 5)
    {
        flushSuit = "Hearts";
    }

    if (spadesCounter >= 5)
    {
        flushSuit = "Spades";
    }

    for (int i = 0; i < cards.size() - 4; ++i) // Check for straight now
    { 

        if (cards[i]->getSuit() != flushSuit) 
        {
            continue; // Skip the card if it doesn't match the flush suit.
        }

        if (
            cards[i]->getRank() + 1 == cards[i+1]->getRank() &&
            cards[i]->getRank() + 2 == cards[i+2]->getRank() &&
            cards[i]->getRank() + 3 == cards[i+3]->getRank() &&
            cards[i]->getRank() + 4 == cards[i+4]->getRank() 
            ) 
            {
                return (cards[i]->getRank() + 4) + 400; // Get the value of the strongest card in the straight draw, and since it a straight and a flush add a higher value than before functions.
            }
    }

    return -1;
}

int HandRank::hasRoyalFlush() 
{
    if (cards.size() < 5) // Royal Flush cannot happen if theres less than five total cards
    {
        return -1;
    }

    int straightFlushVal = hasStraightFlush();
    
    if (straightFlushVal > 0) // Straight flush exists (first requirement)
    {
        int highCard = straightFlushVal % 100; // Get the high card rank of the straightFlush.

        if (highCard == 14)
        {
            return 464; // Last card (high card) must be ace. If it exists, return 450 + 14 (Value of Ace)
        }
    }

    return -1;
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
    int flushVal = hasFlush();
    int fullHouseVal = hasFullHouse();
    int fourOfKindVal = hasFourOfKind();
    int straightFlushVal = hasStraightFlush();
    int royalFlushVal = hasRoyalFlush();

    if (royalFlushVal != -1)
    {
        return royalFlushVal;
    }

    else if (straightFlushVal != -1)
    {
        return straightFlushVal;
    }

    else if (fourOfKindVal != -1)
    {
        return fourOfKindVal;
    }

    else if (fullHouseVal != -1)
    {
        return fullHouseVal;
    }

    else if (flushVal != -1)
    {
        return flushVal;
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