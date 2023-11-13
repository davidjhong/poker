#include "../include/handRank.h"
#include <vector>

using namespace std;

bool HandRank::hasHighCard() const {
    return true; // All hands have a high card. Issue is to determine which high card has a higher value.
}

bool HandRank::hasPair() const {
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i].getRank() == cards[i+1].getRank()) {
            return true;
        }
    }
    return false;
}

bool HandRank::hasTwoPair() const {
    int numPairs = 0;
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i].getRank() == cards[i+1].getRank()) {
            numPairs++;
            ++i; // Move to next i
        }
    } 
    return numPairs >= 2; // No such thing as three pair, four pair, or so on... 
}

int HandRank::getFinalRank() const {
    if (hasTwoPair()) {
        return 150;
    }
    else if (hasPair()) {
        return 100;
    }
    else if (hasHighCard()) {
        return 50;
    }
}