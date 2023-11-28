#ifndef ROUND_HANDLER_H
#define ROUND_HANDLER_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Pot.h"

class RoundHandler {
    private:
        unsigned int dealerIndex;
        Pot* pot;
        Deck* deck;
        vector<Card*> communityCards;

        void call(ostream&, Player*);
  
        bool raise(istream&, ostream&, Player*);
        bool check(ostream&, Player*);
    public:
        RoundHandler();
        void startRound(vector<Player*>);
};

#endif