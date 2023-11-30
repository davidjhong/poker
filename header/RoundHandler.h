#ifndef ROUND_HANDLER_H
#define ROUND_HANDLER_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Pot.h"
#include "Display.h"

class RoundHandler {
    private:
        unsigned int dealerIndex;
        Pot* pot;
        Deck* deck;
        vector<Card*> communityCards;

        void call(ostream&, Player*);
  
        bool raise(istream&, ostream&, Player*);
        bool check(ostream&, Player*);

        bool fold(Player*);
    public:
        RoundHandler();
        ~RoundHandler();
        void startRound(istream&, ostream&, vector<Player*>*, Display*);
};

#endif