#ifndef __HANDRANK_H__
#define __HANDRANK_H__

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class HandRank {
    private:
        int rankValue = 0;
        vector<Card*> cards;

    public:
        int getFinalRank(vector<Card*>);

        int hasHighCard();
        int hasPair();
        int hasTwoPair();
        int hasThreeOfKind();
        int hasStraight();
        bool hasFlush() const;
        bool hasFullHouse() const;
        int hasFourOfKind();
        bool hasStraightFlush() const;
        bool hasRoyalFlush() const;
};

#endif // __HANDRANK_H__