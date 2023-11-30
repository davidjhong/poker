#include "../header/RoundHandler.h"


using namespace std;


RoundHandler::RoundHandler()
{
    this->dealerIndex = 0;
    this->deck = new Deck();
    this->pot = new Pot();
}

RoundHandler::~RoundHandler()
{
    // this->dealerIndex = 0;
    delete this->deck;
    delete this->pot;
}

void RoundHandler::startRound(istream &is, ostream &os, vector<Player*> *playerList, Display* display)
{

    // for (int i = 0; i < playerList.size(); i++)
    // {
    //     // playerList[i]->
    //     Player* currentPlayer;
    // }

    // Deals two cards to each player

    for (Player* currentPlayer: *playerList)
    {
        Hand* currentHand = currentPlayer->getHand();

        for (int i = 0; i < 2; i++)
        {
            Card* nextCard = this->deck->nextCard();
            currentHand->addCard(nextCard);
        }
    }

    /*
    void Display::displayPlayerStats(std::ostream& out, Player* player, Hand* hand, Pot* pot)
    {
        out << player->getName() << ", it's your turn!" << endl;
        out << "You have " << player->getBalance() << " chips" << endl;
    //  out << "Pot: " << pot->getPot() << endl;
    //  out << hand->getHand() << endl;
        out << "1. call" << endl;
        out << "2. raise" << endl;
        out << "3. check" << endl;
        out << "4. fold" << endl;
    }
*/
    int choice = 0;
    for (Player* currentPlayer: *playerList)
    {
        // cout << currentPlayer->getName() << "'s turn" << endl;
        display->displayPlayerStats(os, currentPlayer, currentPlayer->getHand(), pot);
        is >> choice;
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


bool RoundHandler::raise(istream& is, ostream& out, Player* p) {
    int raiseTo;
    out << "How much would you like to raise?" << endl;
    // is >> raiseTo;
    // raise has to be bigger than highestBet
    while(!(is >> raiseTo)) {
        is.clear();
        is.ignore(256, '\n');
        out << "Please enter a valid number." << endl;
    } 

    if(raiseTo > pot->getHighestBet()) {
        p->setCurrentBet(raiseTo);
        pot->addToPot(raiseTo - p->getCurrentBet());
    }
    else {
        out << "Can't raise. " << raiseTo << " isn't the highest bet." << endl;
        return false;
    }
    return true;
}

// If the player's current bet is lower than the pot's highest bet, check failed
// Otherwise, check succeeds
bool RoundHandler::check(ostream &out, Player* currPlayer)
{
    if (currPlayer->getCurrentBet() < pot->getHighestBet())
    {
        out << "You must raise, call, or fold" << endl;
        return false;
    }

    return true;
}

// Sets the player's isPlaying status to false
bool RoundHandler::fold(Player* currPlayer) {
    currPlayer->setIsPlaying(false);
    return true;
}