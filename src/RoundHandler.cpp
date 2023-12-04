#include "../header/RoundHandler.h"
#include <vector>
#include <unordered_map>


using namespace std;

//https://stackoverflow.com/questions/17335816/clear-screen-using-c 
void RoundHandler::clearScreen() {
    cout << "\033[2J\033[1;1H";
}

RoundHandler::RoundHandler()
{
    this->dealerIndex = 0;
    this->deck = new Deck();
    this->pot = new Pot();
    this->roundNumber = 1;
}

RoundHandler::~RoundHandler()
{
    // this->dealerIndex = 0;
    delete this->deck;
    delete this->pot;
}

vector<Player*> RoundHandler::startRound(istream &is, ostream &os, vector<Player*> *playerList, vector<vector<string>> &roundHistory)
{
    this->deck->shuffleDeck(true);

    // os << "Round " << round << "!" << endl;
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

    for (int i = 0; i < playerList->size(); i++)
    {
        Player* currPlayer = playerList->at(i);

        Hand* currHand = currPlayer->getHand();

        for (int cardCount = 0; cardCount < 2; cardCount++)
        {
            Card* nextCard = this->deck->nextCard();
            playerList->at(i)->getHand()->addCard(nextCard);
        }
    }

    int currPlayerIndex = (bigBlindIndex + 1) % playerCount;
    if (startBettingStage(is, os, playerList, currPlayerIndex))
    {
        return lookForWinner(playerList);
    }

    cardInsert(3);

    int afterDealerIndex = (dealerIndex + 1) % playerCount;
    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        return lookForWinner(playerList);
    }


    cardInsert(1);

    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        return lookForWinner(playerList);
    }

    cardInsert(1);
    cout << "looking for winner" << endl;

    startBettingStage(is, os, playerList, afterDealerIndex)


    vector<Player*> winners = lookForWinner(playerList);

    string winnerNames = "";

    for (int i = 0; i < winners.size() - 1; i++)
    {
        winnerNames += (winners[i]->getName()) + ", ";
    }

    winnerNames += winners[winners.size() - 1]->getName();

    string potSize = to_string(pot->getPot());

    string comboName = winners.at(0)->getHand()->getComboName(); // Since a tie would only happen in the same hand rank, simply get one player's hand rank. 

    vector<string> historyValue = {winnerNames, potSize, comboName};

    roundHistory.push_back(historyValue);
    return winners;
}

vector<Player*> RoundHandler::lookForWinner(vector<Player*> *playerList)
{
    unsigned int playersInCounter = 0;
    Player* lastPlayer = nullptr;

    for (Player* player: *playerList)
    {
        if (player->getIsPlaying())
        {
            lastPlayer = player;
            // player->addToBalance(pot->getPot());
            playersInCounter++;
            // return player;
        }
    }

    if (playersInCounter == 1)
    {
        lastPlayer->addToBalance(pot->getPot());
        return {lastPlayer};
    }

    unordered_map<int, vector<Player*> > mp;

    int maxHandStrength = -1;
    Player* strongestPlayer = nullptr;

    for (Player* player: *playerList)
    {
        if (player->getIsPlaying() == false)
        {
            continue;
        }

        mp[player->getHand()->getStrength()].push_back(player);

        if (maxHandStrength < player->getHand()->getStrength())
        {
            maxHandStrength = player->getHand()->getStrength();
            strongestPlayer = player;
        }
    }

    if (mp[maxHandStrength].size() > 1)
    {
        int splitChips = pot->getPot();

        for (Player* winners: mp[maxHandStrength])
        {
            winners->addToBalance(splitChips);
        }
        return mp[maxHandStrength];
    }

    strongestPlayer->addToBalance(pot->getPot());
    cout << strongestPlayer->getName() << endl;

    return {strongestPlayer};

}

void RoundHandler::resetRound(vector<Player*> *playerList)
{
    this->communityCards.clear();
    this->pot->resetPot();
    this->dealerIndex = (dealerIndex + 1) % playerList->size();
    this->deck->shuffleDeck(true);
    this->roundNumber++;

    for (Player* player: *playerList)
    {
        player->clearCurrentBet();
        player->resetHand();
        player->setIsPlaying(true);
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
    int currPlayerIndex = startingIndex % playerCount;

    int foldCount = 0;
    int choice = 0;
    // betting stage
    for (int i = 0; i < playerCount; i++)
    {

        clearScreen();
        
        Player* currPlayer = playerList->at(currPlayerIndex);

        if (!currPlayer->getIsPlaying())
        {
            continue;
        }

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
                clearScreen();
                display->displayGameStatus(os, communityCards, currPlayer, pot);
                os << "Your previous decision was invalid. Try again." << endl;
                is.clear();
                is.ignore(256, '\n');
                is >> choice;
            }
        }

        currPlayerIndex = (currPlayerIndex + 1) % playerCount;

        int value = 0;

        // do {
        //     clearScreen();
        //     display->displayBetweenTurns(os, playerList->at(currPlayerIndex));
        //     is.clear();
        //     is.ignore(256, '\n');
        // }
        // while (!(is >> value));

        
    }

    if (communityCards.size() == 5)
    {
        return true;
    }
    return false;

}









bool RoundHandler::call(ostream& out, Player* currPlayer) {

    if (!currPlayer)
    {
        cout << "SFGONSFOGMSFKLGMF NO PLYAER" << endl;
    }
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
    out << "What would you like to raise your bet to?" << endl;
    // is >> raiseTo;
    // raise has to be bigger than highestBet
    while(!(is >> raiseTo) || raiseTo < pot->getHighestBet()) {
        is.clear();
        is.ignore(256, '\n');
        out << "Please enter a valid number above the highest bet: " << pot->getHighestBet() << endl;
    }

    if (raiseTo - currPlayer->getCurrentBet() > currPlayer->getBalance())
    {
        string toContinue;
        out << "Can't raise. You don't have enough chips." << endl;
        out << "Enter anything to continue." << endl;
        is >> toContinue;
        return false;
    }
    if (raiseTo > pot->getHighestBet()) {
        // cout << endl;
        // cout << raiseTo - currPlayer->getCurrentBet() << endl;
        pot->addToPot(raiseTo - currPlayer->getCurrentBet());
        pot->setHighestBet(raiseTo + currPlayer->getCurrentBet());
        currPlayer->setCurrentBet(raiseTo);


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

unsigned int RoundHandler::getRound() const
{
    return this->roundNumber;
}

Pot* RoundHandler::getPot() const
{
    return this->pot;
}

unsigned int RoundHandler::getDealerIndex() const
{
    return this->dealerIndex;
}