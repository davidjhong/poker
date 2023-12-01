#ifndef ROUND_HANDLER_H
#define ROUND_HANDLER_H

#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Pot.h"
#include "Display.h"
#include "Settings.h"

class RoundHandler {
    private:
        Display* display;
        Settings* settings;
        unsigned int dealerIndex;
        Pot* pot;
        Deck* deck;
        vector<Card*> communityCards;

        bool startBettingStage(istream&, ostream&, vector<Player*>*, int);

        Player* lookForWinner(vector<Player*>*);
        void blindInput(Player*, int);
        void cardInsert(int);

        bool call(ostream&, Player*);
        bool raise(istream&, ostream&, Player*);
        bool check(ostream&, Player*);
        bool fold(Player*);
    public:
        RoundHandler();
        ~RoundHandler();
        Player* startRound(istream&, ostream&, vector<Player*>*);
        void setSettings(Settings*);
};

#endif