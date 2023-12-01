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

        bool hasHighCard() const;
        bool hasPair() const;
        bool hasTwoPair() const;
        bool hasThreeOfKind() const;
        bool hasStraight() const;
        bool hasFlush() const;
        bool hasFullHouse() const;
        bool hasFourOfKind() const;
        bool hasStraightFlush() const;
        bool hasRoyalFlush() const;
};

#endif // __HANDRANK_H__