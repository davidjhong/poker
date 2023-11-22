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
    public:
        RoundHandler();
        void startRound(vector<Player*>);
};

#endif