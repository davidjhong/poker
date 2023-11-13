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
    
        int getRank() const;
        int getFinalRank(vector<Card*>);

        bool hasHighCard() const;
        bool hasPair() const;
        bool hasTwoPair() const;
};

#endif // __HANDRANK_H__