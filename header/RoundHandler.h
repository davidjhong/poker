#ifndef ROUND_HANDLER_H
#define ROUND_HANDLER_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Pot.h"
#include "GameHandler.h"

class RoundHandler {
    private:
        unsigned int dealer;
        Pot* pot;
        Deck* deck;
        vector<Card*> communityCards;
    public:
        RoundHandler();
        void startRound();
};



#endif