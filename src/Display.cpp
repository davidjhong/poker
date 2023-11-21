#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../header/Display.h"

using namespace std;

void Display::displayMenu(std::ostream& out)
{
    out << "-------------- START MENU -----------------" << endl;
    out << "select 1 to see rules" << endl;
    out << "select 2 to see card rankings" << endl;
    out << "select 3 to see card combinations" << endl;

    out << "select 5 start game" << endl;
    out << "-------------------------------------------" << endl;
}  


void Display::displayRules(std::ostream& out)
{
    out << endl;
    out << "Overview: " << endl;
    out << "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. " << endl;
    out << "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. " << endl;
    out << "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards" << endl;
    out << endl << "Texas Hold' em - in depth: " << endl;
    out << "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will poutt " << endl << "the small blind, then the player to their left will poutt the big blind, which is double the value of the small blind. ";
    out << "2 hole cards will be dealt to each player. " << endl << "The starting player may now chooute to fold, call or raise. " << endl;
    out << "   fold: discard hand and put no more chips in the pot" << endl;
    out << "   call: add the call amount to the pot" << endl;
    out << "   raise: increase the call amount for the current round" << endl;
    out << "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player " << endl << "has folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. " << endl;
    out << "Each player will again chooute to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again chooute " << endl << "to fold, call or raise.";
    out << "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised." << endl;
    out << "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest " << endl << "ranked combination wins the pot." << endl;
    out << "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner." << endl;
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
}

void Display::displayPlayerStats(std::ostream& out, Player* player, Hand* hand, Pot* pot)
{
    out << player->getName() << ", it's your turn!" << endl;
    out << "You have " << player->getBalance() << " chips" << endl;
    out << "Pot: " << pot->getPot() << endl;
    //best combo out << "Best combo: " << 
    out << hand->getHand() << endl;
    out << "1. call \n"
    out << "2. raise \n"
    out << "3. check \n"
    out << "4. fold \n"
}

void Display::displayGameStatus(std::ostream& out, Player* player, Pot* pot)
{
    out << player->getName() << "raised to "; // << bet raised
    out << "Pot: " << pot->getPot() << endl;
}

