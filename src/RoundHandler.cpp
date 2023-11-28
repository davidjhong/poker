#include "../header/RoundHandler.h"


using namespace std;


RoundHandler::RoundHandler()
{
    this->dealerIndex = 0;
    this->deck = new Deck();
    this->pot = new Pot();
}

void RoundHandler::startRound(vector<Player*> playerList)
{

    // for (int i = 0; i < playerList.size(); i++)
    // {
    //     // playerList[i]->
    //     Player* currentPlayer;
    // }

    // Deals two cards to each player
    for (Player* currentPlayer: playerList)
    {
        Hand* currentHand = currentPlayer->getHand();

        for (int i = 0; i < 2; i++)
        {
            Card* nextCard = this->deck->nextCard();
            currentHand->addCard(nextCard);
        }
    }

    // Deals the first three cards to the communityCards
}

void RoundHandler::call(ostream& out, Player* currPlayer) {

    // if player has no chips
    if (currPlayer->getBalance() <= 0)
    {
        return;
    }

    // If the current highest bet is too much for the player to afford
    if (pot->getHighestBet() - currPlayer->getCurrentBet() > currPlayer->getBalance()) {
        out << "ALL IN." << endl;
        
        // add to pot
        pot->addToPot(currPlayer->getBalance());

        // subtract from player balance
        currPlayer->setCurrentBet(currPlayer->getBalance() + currPlayer->getCurrentBet());

        out << "Current balance: " << currPlayer->getBalance() << endl; // should be 0
    }
    else {  // typical bet
        
        // add to pot
        pot->addToPot(pot->getHighestBet() - currPlayer->getCurrentBet());
        
        // subtract from player balance
        currPlayer->setCurrentBet(pot->getHighestBet());

        out << "Current balance: " << currPlayer->getBalance() << endl;
    }
}

bool RoundHandler::check(ostream &out, Player* currPlayer)
{
    if (currPlayer->getCurrentBet() < pot->getHighestBet())
    {
        out << "You must raise, call, or fold" << endl;
        return false;
    }

    return true;
}