#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../header/Display.h"

using namespace std;

void Display::displayMenu(std::ostream& out)
{
    out << "-------------- START MENU -----------------" << endl;
    out << "1) Start game" << endl;
    out << "2) Settings" << endl;
    out << "3) Rules" << endl;
    out << "4) Card rankings" << endl;
    out << "5) Card combinations" << endl;
    out << "q) Quit" << endl;
    out << "Enter an option" << endl;
    out << "-------------------------------------------" << endl;
}  

void Display::displaySettings(ostream &out)
{
    out << "-------------- SETTINGS -----------------" << endl;
    out << "1) Change player count\n";
    out << "2) Change starting chips\n";
    out << "3) Change big blind amount\n";
    out << "4) Change small blind amount\n";
    out << "5) Change number of rounds\n";
    out << "q) Save and exit\n";
    out << "----------------------------------------" << endl;
}


void Display::displayRules(std::ostream& out)
{
    out << "\nOverview: \n";
    out << "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. \n";
    out << "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. \n";
    out << "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards\n"; 
    out << "\nTexas Hold' em - in depth: \n";
    out << "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will be \nthe small blind, then the player to their left will be the big blind, which is double the value of the small blind. ";
    out << "2 hole cards will be dealt to each player. \nThe starting player may now chooute to fold, call or raise. \n";
    out << "   fold: discard hand and put no more chips in the pot\n";
    out << "   call: add the call amount to the pot\n";
    out << "   raise: increase the call amount for the current round\n";
    out << "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player \nhas folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. \n";
    out << "Each player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute \nto fold, call or raise.";
    out << "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised.\n";
    out << "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest \nranked combination wins the pot.\n";
    out << "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner.\n";
    out << "q) back to menu \n";
}

void Display::displayCardCombinations(std::ostream& out)
{
    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " royal flush: straight flush from 10 to Ace." << endl;
    out << "| 10 |"  << "|  J |" << "|  Q |" << "|  K |" << "|  A |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " straight flush: straight, but all cards are the same suit." << endl;
    out << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " four of a kind: four of the same card, highest value wins in a tie." << endl;
    out << "|  A |"  << "|  A |" << "|  A |" << "|  A |" << "|  2 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie." << endl;
    out << "|  A |"  << "|  A |" << "|  A |" << "|  K |" << "|  K |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " flush: 5 cards of the same suit, highest card wins in a tie." << endl;
    out << "|  2 |"  << "|  4 |" << "|  6 |" << "|  8 |" << "|  K |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " straight: 5 cards in order but not of the same suit." << endl;
    out << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " three of a kind: 3 of a kind, highest card wins in a tie." << endl;
    out << "|  A |"  << "|  A |" << "|  A |" << "|  2 |" << "|  7 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " two pair: 2 sets of pairs." << endl;
    out << "|  K |"  << "|  K |" << "|  Q |" << "|  Q |" << "|  J |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " pair: 2 of a kind, highest card wins in a tie." << endl;
    out << "|  A |"  << "|  A |" << "|  9 |" << "|  8 |" << "|  7 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    out << endl;

    out <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    out << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " high card: no combination, only a single high ranked card" << endl;
    out << "|  A |"  << "|  8 |" << "|  6 |" << "|  4 |" << "|  2 |" << endl;
    out <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----" << endl;
    out << "q) back to menu \n";

}
    
void Display::displayCardRankings(std::ostream& out)
{
    out << "The card rankings are displayed below, from weakest to strongest: " << endl;
    out << "2" << endl;
    out << "3" << endl;
    out << "4" << endl;
    out << "5" << endl;
    out << "6" << endl;
    out << "7" << endl;
    out << "8" << endl;
    out << "9" << endl;
    out << "10" << endl;
    out << "J (jack)" << endl;
    out << "Q (queen)" << endl;
    out << "K (king)" << endl;
    out << "A (ace)" << endl;
    out << "* Note that in Texas Hold' em, all suits are equally ranked" << endl;
    out << "q) back to menu \n";
}


void Display::displayGameStatus(std::ostream& out, vector<Card*> communityCards, Player* player, Pot* pot)
{
    out << player->getName() << ", it's your turn!" << endl;
    out << "You have " << player->getBalance() << " chips\n";
    out << "Pot: " << pot->getPot() << endl;
    out << "Your hand:\n";
    
    
    vector<Card*> cards = player->getHand()->getHand();

    displayCards(out, cards);
    
    // out << "Best combo: " << 
    out << "Community cards:\n"; 

    for (int i = 0; i < 5; i++) 
    { 
        out << "-----" << "     " ; 
    
    } 
    out << "\n";
    for (size_t i = 0; i < 5; i++) 
    { 
        if (i < communityCards.size()) 
        { 
            if(communityCards[i]->getRank() == 10 ) 
            { 
                out << "| " <<communityCards[i]->getSuitSymbol() << "  | " << "   "; 
            } 
            else 
            { 
                out << "| " << communityCards[i]->getSuitSymbol() << " |" << "     "; 
            }  
        } 
        else 
        { 
            out << "|   |" << "     ";
        } 
    } 
    
    
    out << "\n";
    for (size_t i = 0; i < 5; i++) 
    { 
        if (i < communityCards.size()) 
        { 
            if(communityCards[i]->getRank() == 10 ) 
            { 
            out << "| " << communityCards[i]->getRank() << " |" << "    "; 
            } 
            else if (communityCards[i] ->getRank() == 1)
            {
                out << "| " << "A" << " |" << "     ";
            }
            else if (communityCards[i] ->getRank() == 11)
            {
                out << "| " << "J" << " |" << "     ";
            }
            else if (communityCards[i] ->getRank() == 12)
            {
                out << "| " << "Q" << " |" << "     ";
            }
            else if (communityCards[i] ->getRank() == 13)
            {
            out << "| " << "K" << " |" << "     ";
            }
            else 
            { 
            out << "| " << communityCards[i]->getRank() << " |" << "     "; 
            } 
        
        } 
        else { 
            out << "| ? |" << "     ";
        } 
    }       
    
    out << "\n";
    for (int i = 0; i < 5; i++)
    { 
        out << "-----" << "     "; 
        
    } 
    out << "\n";

    
    out << "1. call" << endl;
    out << "2. raise" << endl;
    out << "3. check" << endl;
    out << "4. fold" << endl;

}

void Display::displayCards(ostream& out, vector<Card*> cards)
{
    for (int i = 0; i < cards.size(); i++) 
    { 
        out << "-----" << "     " ; 
        
    } 
    out << "\n"; 

    for(const Card* card: cards) { 
        if(card->getRank() == 10 ) { 
            out << "| " << card->getSuitSymbol() << "  |" << "    ";  
        } 
 
        else { 
            out << "| " << card->getSuitSymbol() << " |" << "     "; 
        } 
    }
    out << "\n"; 
   
    for (const Card* card: cards) 
    { 
        if(card->getRank() == 10 ) 
        { 
          out << "| " << card->getRank() << " |" << "    "; 
        } 
        else if (card ->getRank() == 1)
        {
            out << "| " << "A" << " |" << "     ";
        }
        else if (card ->getRank() == 11)
        {
            out << "| " << "J" << " |" << "     ";
        }
        else if (card ->getRank() == 12)
        {
            out << "| " << "Q" << " |" << "     ";
        }
        else if (card ->getRank() == 13)
        {
            out << "| " << "K" << " |" << "     ";
        }
        else 
        { 
          out << "| " << card->getRank() << " |" << "     "; 
        } 
    } 
    out << "\n"; 
    for (int i = 0; i < cards.size(); i++) 
    { 
        out << "-----" << "     "; 
    } 
    out << "\n"; 
}



void Display::displayBalanceChanges(std::ostream& out, Player* player, Pot* pot)
{
    out << player->getName() << "raised to "; // << bet raised
    out << "Pot: " << pot->getPot() << endl;
}

void Display::displayGameOver(std::ostream& out)
{
    // clearScreen();
    out << "POKER++ \n";
    out << "Thanks for playing! \n :3";
}


void Display::displayWinner(std::ostream& out, vector<Player*> winnerList, Pot* pot)
{
    if (winnerList.empty())
    {
        out << "game bugged, no winner" << endl;
        return;
    }
    // cout << winnerList.size() << endl;

    if (winnerList.size() == 1)
    {
        
        Player* player = winnerList.at(0);

        if (!player)
        {
            out << "UHOPHSFDG" << endl;
        }
        else
        {
            
        out << player->getName() << " won " << pot->getPot(); 
        if (player->getHand() == nullptr)
        {
            out <<" DSFSD" << endl;
        }
        else
        {
        out << " chips with a " << player->getHand()->getComboName() << "!" << endl;

        }

        }
    }
    else
    {
        int splitPot = pot->getPot() / winnerList.size();
        // for (Player* tiePlayer: winnerList)
        // {
        //     out << tiePlayer->getName() << ", ";
        // }

        for (int i = 0; i < winnerList.size() - 1; i++)
        {
            out << winnerList.at(i)->getName() << ", ";
        }
        out << "and " << winnerList.at(winnerList.size() - 1)->getName();

        out << " won a split pot of " << splitPot << " each!" << endl;
    }
    // clearScreen();
    
}


void Display::displayBetweenTurns(std::ostream& out, Player* player)
{
    out << player->getName() << "'s turn\n";
    out << "Enter 1 to continue\n";
}