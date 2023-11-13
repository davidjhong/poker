#ifndef __HANDRANK_H__
#define __HANDRANK_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HandRank {
    private:
        int rankValue = 0;
        vector<int> cards;

    public:
    
        int getRank() const;
        int getFinalRank() const;

        bool hasHighCard() const;
        bool hasPair() const;
        bool hasTwoPair() const;
};

#endif // __HANDRANK_H__