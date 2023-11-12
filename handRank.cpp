#include "handRank.h"

HandRank::HandRank(const vector<int>& cards) {
    // Fill in the cards. However, need to implement a function to use the combination of Hands (2 Cards) and the Board (3, 4, or 5 cards).
}

bool HandRank::hasHighCard() const {
    return true; // All hands have a high card. Issue is to determine which high card has a higher value.
}

bool HandRank::hasPair() const {
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i] == cards[i+1]) {
            return true;
        }
    }
    return false;
}

bool HandRank::hasTwoPair() const {
    int numPairs = 0;
    for (int i = 0; i < cards.size()-1; i++) {
        if (cards[i] == cards[i+1]) {
            numPairs++;
            ++i; // Move to next i
        }
    } 
    return numPairs >= 2; // No such thing as three pair, four pair, or so on... 
}

int HandRank::getRank() const {
    if (hasHighCard()) {
        return 50;
    }
    else if (hasPair()) {
        return 100;
    }
    else if (hasTwoPair()) {
        return 150;
    }
}