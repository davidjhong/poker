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

void RoundHandler::startRound(istream &is, ostream &os, vector<Player*> *playerList)
{
    // clearScreen();
    // os << "\n\n\n\n\n\n\n\n\n" << endl;
    // Deals two cards to each player

    const unsigned int playerCount = playerList->size();

    int smallBlindIndex = (dealerIndex + 1) % playerCount;
    int bigBlindIndex = (dealerIndex + 2) % playerCount;

    Player* smallBlindPlayer = playerList->at(smallBlindIndex);
    Player* bigBlindPlayer = playerList->at(bigBlindIndex);


    blindInput(smallBlindPlayer, settings->getLittleBlindAmt());
    blindInput(bigBlindPlayer, settings->getBigBlindAmt());


    // os << smallBlindPlayer->getName() << " " << bigBlindPlayer->getName() << endl;

    for (int i = 0; i < playerList->size(); i++)
    {
        Player* currPlayer = playerList->at(i);

        Hand* currHand = currPlayer->getHand();

        for (int cardCount = 0; i < 2; i++)
        {
            Card* nextCard = this->deck->nextCard();
            currHand->addCard(nextCard);
        }

    }

    int currPlayerIndex = (bigBlindIndex + 1) % playerCount;

    int foldCount = 0;

    int choice = 0;
    // betting stage
    for (int i = 0; i < playerCount; i++)
    {
        
        // os << "index: " << currPlayerIndex << endl;
        Player* currPlayer = playerList->at(currPlayerIndex);

        os << currPlayer->getName() << "'s balance: " << currPlayer->getBalance() << endl;

        if (!currPlayer->getIsPlaying())
        {
            continue;
        }

        display->displayPlayerStats(os, currPlayer, currPlayer->getHand(), pot);
        
        while (!(is >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4))
        {
            os << "Invalid input, enter a valid choice" << endl;

            is.clear();
            is.ignore(256, '\n');
        }

        if (choice == 1)
        {
            call(os, currPlayer);
        }
        else if (choice == 2)
        {
            raise(is, os, currPlayer);
        }
        else if (choice == 3)
        {
            check(os, currPlayer);
        }
        else if (choice == 4)
        {
            fold(currPlayer);
            foldCount++;
        }

        currPlayerIndex = (currPlayerIndex + 1) % playerCount;
        
    }


    dealerIndex++;
}


void RoundHandler::blindInput(Player* currPlayer, int amount)
{
    pot->addToPot(amount);
    currPlayer->setCurrentBet(amount);
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


bool RoundHandler::raise(istream& is, ostream& out, Player* currPlayer) {
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
        cout << endl;
        // cout << raiseTo - currPlayer->getCurrentBet() << endl;
        pot->addToPot(raiseTo - pot->getHighestBet());
        currPlayer->setCurrentBet(raiseTo);
        out << "New highest bet: " << pot->getHighestBet() << endl;
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

void RoundHandler::setSettings(Settings *givenSettings)
{
    this->settings = givenSettings;
}