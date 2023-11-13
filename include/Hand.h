#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Card.h"

class Hand {
    private:
        vector<Card*> hand;
    public:
        Hand(vector<Card*>);
        vector<Card*> getCurrentHand();
};

#endif