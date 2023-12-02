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

Player* RoundHandler::startRound(istream &is, ostream &os, vector<Player*> *playerList)
{
    // clearScreen();
    // os << "\n\n\n\n\n\n\n\n\n" << endl;
    // Deals two cards to each player

    const unsigned int playerCount = playerList->size();

    int smallBlindIndex = (dealerIndex + 1) % playerCount;
    int bigBlindIndex = (dealerIndex + 2) % playerCount;

    Player* smallBlindPlayer = playerList->at(smallBlindIndex);
    Player* bigBlindPlayer = playerList->at(bigBlindIndex);


    // os << smallBlindPlayer->getName() << " balance: " << smallBlindPlayer->getBalance() << endl;
    // os << bigBlindPlayer->getName() << " balance: " << bigBlindPlayer->getBalance() << endl;

    blindInput(smallBlindPlayer, settings->getLittleBlindAmt());
    blindInput(bigBlindPlayer, settings->getBigBlindAmt());


    // os << smallBlindPlayer->getName() << " balance: " << smallBlindPlayer->getBalance() << endl;
    // os << bigBlindPlayer->getName() << " balance: " << bigBlindPlayer->getBalance() << endl;

    for (auto &player: *playerList)
    {
        os << player->getName() << " balance: " << player->getBalance() << endl;
    }

    for (int i = 0; i < playerList->size(); i++)
    {
        Player* currPlayer = playerList->at(i);

        // Hand* currHand = currPlayer->getHand();

        for (int cardCount = 0; cardCount < 2; cardCount++)
        {
            Card* nextCard = this->deck->nextCard();
            playerList->at(i)->getHand()->addCard(nextCard);
        }

        // for (int cardCount = 0; i < 2; i++)
        // {
        //     Card* nextCard = this->deck->nextCard();
        //     currHand->addCard(nextCard);
        // }
    }

    cardInsert(3);

    int currPlayerIndex = (bigBlindIndex + 1) % playerCount;

    if (startBettingStage(is, os, playerList, currPlayerIndex))
    {
        return lookForWinner(playerList);
    }

    for (Card* card: communityCards)
    {
        cout << card->getName() << " ";
    }
    cout << endl;

    int afterDealerIndex = (dealerIndex + 1) % playerCount;

    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        return lookForWinner(playerList);
    }

    // Card* nextCard = this->deck->nextCard();
    // communityCards.push_back(nextCard);
    cardInsert(1);

    for (Card* card: communityCards)
    {
        cout << card->getName() << " ";
    }
    cout << endl;

    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        return lookForWinner(playerList);
    }
    // nextCard = this->deck->nextCard();
    // communityCards.push_back(nextCard);
    cardInsert(1);

    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        return lookForWinner(playerList);
    }



    pot->resetPot();
    dealerIndex++;
}

Player* RoundHandler::lookForWinner(vector<Player*> *playerList)
{
    for (Player* player: *playerList)
    {
        if (player->getIsPlaying())
        {
            return player;
        }
    }
}

void RoundHandler::blindInput(Player* currPlayer, int amount)
{
    pot->addToPot(amount);
    currPlayer->setCurrentBet(amount);
}

void RoundHandler::cardInsert(int size)
{
    for (int i = 0; i < size; i++)
    {
        Card* nextCard = this->deck->nextCard();
        communityCards.push_back(nextCard);
    }
}

bool RoundHandler::startBettingStage(istream &is, ostream &os, vector<Player*> *playerList, int startingIndex)
{
    const unsigned int playerCount = playerList->size();
    int currPlayerIndex = startingIndex;
    // int currPlayerIndex = (bigBlindIndex + 1) % playerCount;

    // for (Card* card: communityCards)
    // {
    //     cout << card->getName() << " ";
    // }
    // cout << endl;

    int foldCount = 0;
    int choice = 0;
    // betting stage
    for (int i = 0; i < playerCount; i++)
    {
        
        // os << "index: " << currPlayerIndex << endl;
        Player* currPlayer = playerList->at(currPlayerIndex);

        if (!currPlayer->getIsPlaying())
        {
            continue;
        }

        // os << currPlayer->getName() << "'s balance: " << currPlayer->getBalance() << endl;


        // display->displayPlayerStats(os, currPlayer, currPlayer->getHand(), pot);
        display->displayGameStatus(os, communityCards, currPlayer, pot);

        while (!(is >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4))
        {
            os << "Invalid input, enter a valid choice" << endl;

            is.clear();
            is.ignore(256, '\n');
        }

        bool valid = false;

        while (!valid)
        {
            if (choice == 1)
            {
                valid = call(os, currPlayer);
            }
            else if (choice == 2)
            {
                valid = raise(is, os, currPlayer);

                if (valid)
                {
                    i = 0;
                }
            }
            else if (choice == 3)
            {
                valid = check(os, currPlayer);
            }
            else if (choice == 4)
            {
                valid = fold(currPlayer);
                foldCount++;

                if (foldCount == playerCount - 1)
                {
                    return true;
                }
            }

            if (!valid)
            {
                os << "Invalid decision. Try again." << endl;
                // display->displayGameStatus(os, currPlayer, currPlayer->getHand(), pot);
                is >> choice;
            }
        }

        currPlayerIndex = (currPlayerIndex + 1) % playerCount;
        
    }
    return false;

}









bool RoundHandler::call(ostream& out, Player* currPlayer) {

    // if player has no chips
    if (currPlayer->getBalance() <= 0)
    {
        return true;
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
    return true;
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
        // cout << endl;
        // cout << raiseTo - currPlayer->getCurrentBet() << endl;
        pot->addToPot(raiseTo - currPlayer->getCurrentBet());
        pot->setHighestBet(raiseTo + currPlayer->getCurrentBet());
        currPlayer->setCurrentBet(raiseTo + currPlayer->getCurrentBet());




        out << "New highest bet: " << pot->getHighestBet() << endl;
        out << currPlayer->getBalance() << endl;
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