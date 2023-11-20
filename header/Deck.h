#ifndef DECK_H
#define DECK_H
#include <vector>
#include <queue>
#include "Card.h"

class Deck {
    private:
        vector<Card*> allCards;
        int currentCardIndex;
    public:
        Deck();
        ~Deck();
        void shuffleDeck(bool);
        Card* nextCard();
};

#endif