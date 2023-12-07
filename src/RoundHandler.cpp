#include "../header/RoundHandler.h"
#include "../header/Utility.h"
#include "../header/Bot.h"
#include <vector>
#include <unordered_map>


using namespace std;

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
    const unsigned int playerCount = playerList->size();

    vector<unsigned int> startingIndices = findStartingIndices(playerList);

    unsigned int littleBlindIndex = startingIndices[0];
    unsigned int bigBlindIndex = startingIndices[1];
    unsigned int startingPlayerIndex = startingIndices[2];

    Player* smallBlindPlayer = playerList->at(littleBlindIndex);
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

    if (startBettingStage(is, os, playerList, startingPlayerIndex))
    {
        vector<Player*> winner = lookForWinner(playerList);
        saveRoundHistory(winner, roundHistory);
        return winner;
    }

    cardInsert(3);

    int afterDealerIndex = (dealerIndex + 1) % playerCount;
    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        vector<Player*> winner = lookForWinner(playerList);
        saveRoundHistory(winner, roundHistory);
        return winner;
    }


    cardInsert(1);

    if (startBettingStage(is, os, playerList, afterDealerIndex))
    {
        vector<Player*> winner = lookForWinner(playerList);
        saveRoundHistory(winner, roundHistory);
        return winner;
    }

    cardInsert(1);

    startBettingStage(is, os, playerList, afterDealerIndex);

    vector<Player*> winners = lookForWinner(playerList);
    saveRoundHistory(winners, roundHistory);
    return winners;

}

vector<unsigned int> RoundHandler::findStartingIndices(vector<Player*>* playerList) const
{
    const int playerCount = playerList->size();
    unsigned int smallBlindIndex = (dealerIndex + 1) % playerCount;

    while (playerList->at(smallBlindIndex)->getIsPlaying() == false)
    {
        smallBlindIndex = (smallBlindIndex + 1) % playerCount;
    }

    unsigned int bigBlindIndex = (smallBlindIndex + 1) % playerCount;
    while (playerList->at(bigBlindIndex)->getIsPlaying() == false)
    {
        bigBlindIndex = (bigBlindIndex + 1) % playerCount;
    }

    unsigned int startingPlayerIndex = (bigBlindIndex + 1) % playerCount;
    while(playerList->at(startingPlayerIndex)->getIsPlaying() == false)
    {
        startingPlayerIndex = (startingPlayerIndex + 1) % playerCount;
    }

    return {smallBlindIndex, bigBlindIndex, startingPlayerIndex};
}

void RoundHandler::saveRoundHistory(vector<Player*> &winners, vector<vector<string>> &roundHistory)
{
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
            playersInCounter++;
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
        // display->displayCards(player->getHand()->getHand());
        player->getHand()->calculateStrength(this->communityCards);
        mp[player->getHand()->getStrength()].push_back(player);

        if (maxHandStrength < player->getHand()->getStrength())
        {
            maxHandStrength = player->getHand()->getStrength();
            strongestPlayer = player;
        }
    }

    if (mp[maxHandStrength].size() > 1)
    {
        int splitChips = pot->getPot() / mp[maxHandStrength].size();

        for (Player* winners: mp[maxHandStrength])
        {
            winners->addToBalance(splitChips);
        }
        return mp[maxHandStrength];
    }

    strongestPlayer->addToBalance(pot->getPot());

    return {strongestPlayer};

}

Player* RoundHandler::resetRound(vector<Player*> *playerList, bool isRandom)
{
    this->communityCards.clear();
    this->pot->resetPot();
    this->dealerIndex = (dealerIndex + 1) % playerList->size();
    this->deck->shuffleDeck(isRandom);
    this->roundNumber++;

    unsigned int playerCount = 0;
    Player* gameWinner = nullptr;

    for (Player* player: *playerList)
    {
        player->clearCurrentBet();
        player->resetHand();

        if (player->getBalance() > 0)
        {
            playerCount++;
            gameWinner = player;
            player->setIsPlaying(true);
        }
    }
    if (playerCount == 1)
    {
        return gameWinner;
    }
    return nullptr;
}

void RoundHandler::setRound(unsigned int roundNumber)
{
    this->roundNumber = roundNumber;
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

void RoundHandler::setCards(const vector<Card*> cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        communityCards.push_back(cards.at(i));
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
        Utility::clearScreen();
        
        Player* currPlayer = playerList->at(currPlayerIndex);

        if (!currPlayer->getIsPlaying())
        {
            continue;
        }


        if (currPlayer->getIsBot())
        {
            Bot* bot = dynamic_cast<Bot*>(currPlayer);
            choice = bot->randomAction();
        }
        else
        {
            display->displayGameStatus(os, communityCards, currPlayer, pot);
            while (!(is >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4))
            {
                os << "Invalid input, enter a valid choice" << endl;

                is.clear();
                is.ignore(256, '\n');
            }

        }


        bool validChoice = false;

        while (!validChoice)
        {
            if (choice == 1)
            {
                validChoice = call(os, currPlayer);
                os << currPlayer->getName() << " has called!" << endl;
                os << "The current pot amount is " << pot->getPot() << "." << endl << endl;
            }
            else if (choice == 2)
            {
                validChoice = raise(is, os, currPlayer);

                if (validChoice)
                {
                    i = 0;
                    os << currPlayer->getName() << " has raise to " << pot->getHighestBet() << endl;
                    os << "The current pot amount is " << pot->getPot() << "." << endl << endl;
                }
            }
            else if (choice == 3)
            {
                validChoice = check(os, currPlayer);
                os << currPlayer->getName() << " has checked!" << endl;
                os << "The current pot amount is " << pot->getPot() << "." << endl << endl;
            }
            else if (choice == 4)
            {
                validChoice = fold(currPlayer);
                foldCount++;

                os << currPlayer->getName() << " has folded!" << endl;

                if (foldCount == playerCount - 1)
                {
                    return true;
                }
            }

            if (!validChoice)
            {
                Utility::clearScreen();
                display->displayGameStatus(os, communityCards, currPlayer, pot);
                os << "Your previous decision was invalid. Try again." << endl;
                is.clear();
                is.ignore(256, '\n');
                is >> choice;
            }
        }

        currPlayerIndex = (currPlayerIndex + 1) % playerCount;
        string continueFlag;

        do {
            display->displayBetweenTurns(os, playerList->at(currPlayerIndex));
            is.clear();
            is.ignore(256, '\n');
        }
        while (!(is >> continueFlag));

        
    }

    if (communityCards.size() == 5)
    {
        return true;
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
        
        // add to pot
        pot->addToPot(currPlayer->getBalance());

        // subtract from player balance
        currPlayer->setCurrentBet(currPlayer->getBalance() + currPlayer->getCurrentBet());
    }
    else {  // typical bet
        
        // add to pot
        pot->addToPot(pot->getHighestBet() - currPlayer->getCurrentBet());
        
        // subtract from player balance
        currPlayer->setCurrentBet(pot->getHighestBet());

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

void RoundHandler::setDealerIndex(int i) {
    dealerIndex = i;
}

void RoundHandler::setRound(int r) {
    roundNumber = r;
}