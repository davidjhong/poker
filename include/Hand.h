#ifndef HAND_H
#define HAND_H

#include <vector>
#include <ostream>
#include "Card.h"


class Hand {
    private:
        int strength;
        vector<Card*> hand;
    public:
        Hand();
        void addCard(Card*);
        void clearHand();

        vector<Card*> getHand();
        vector<string> getCardNames();
};

#endif