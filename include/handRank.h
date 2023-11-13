#ifndef __HANDRANK_H__
#define __HANDRANK_H__

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class HandRank {
    private:
        int rankValue;
        vector<Card*> cards;

    public:
        HandRank();
        int getRank() const;
        int getFinalRank(vector<Card*>);

        bool hasHighCard() const;
        bool hasPair() const;
        bool hasTwoPair() const;
};

#endif // __HANDRANK_H__