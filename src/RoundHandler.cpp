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
    for (Player* currentPlayer: playerList)
    {
        Hand* currentHand = currentPlayer->getHand();

        for (int i = 0; i < 2; i++)
        {
            Card* nextCard = this->deck->nextCard();
            currentHand->addCard(nextCard);
        }
    }



    

}