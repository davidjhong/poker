#ifndef HAND_H
#define HAND_H

#include <vector>
#include <ostream>
#include "Card.h"
#include "../header/handRank.h"


class Hand {
    private:
        int strength;
        vector<Card*> hand;
    public:
        Hand();
        ~Hand();
        Hand(vector<Card*> cards);
        void addCard(Card*);
        void clearHand();

        int getStrength() const;
        void calculateStrength(vector<Card*>&);

        string getComboName();
        
        vector<Card*> getHand();
        Card* getCard(int i) const;
        vector<string> getCardNames();
};

#endif