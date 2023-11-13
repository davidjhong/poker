#ifndef __HANDRANK_H__
#define __HANDRANK_H__

#include <iostream>
#include <vector>
#include <string>

class HandRank {
    private:
        int rankValue = 0;
        vector<int> cards;

    public:
        HandRank(const vector<int>& cards);
        int getRank() const;
        bool hasHighCard() const;
        bool hasPair() const;
        bool hasTwoPair() const;
};

#endif // __HANDRANK_H__