#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#ifndef MENU_HPP
#define MENU_HPP
using namespace std;

void displayRules(std::ostream&)
{
    os << endl;
    os << "Overview: " << endl;
    os << "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. " << endl;
    os << "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. " << endl;
    os << "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards" << endl;
    os << endl << "Texas Hold' em - in depth: " << endl;
    os << "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will post " << endl << "the small blind, then the player to their left will post the big blind, which is double the value of the small blind. ";
    os << "2 hole cards will be dealt to each player. " << endl << "The starting player may now choose to fold, call or raise. " << endl;
    os << "   fold: discard hand and put no more chips in the pot" << endl;
    os << "   call: add the call amount to the pot" << endl;
    os << "   raise: increase the call amount for the current round" << endl;
    os << "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player " << endl << "has folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. " << endl;
    os << "Each player will again choose to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again choose " << endl << "to fold, call or raise.";
    os << "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised." << endl;
    os << "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest " << endl << "ranked combination wins the pot." << endl;
    os << "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner." << endl;
}

void displayCardCombinations(std::ostream& )
{
    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " royal flush: straight flush from 10 to Ace." << endl;
    os << "| 10 |"  << "|  J |" << "|  Q |" << "|  K |" << "|  A |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " straight flush: straight, but all cards are the same suit." << endl;
    os << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " four of a kind: four of the same card, highest value wins in a tie." << endl;
    os << "|  A |"  << "|  A |" << "|  A |" << "|  A |" << "|  2 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie." << endl;
    os << "|  A |"  << "|  A |" << "|  A |" << "|  K |" << "|  K |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " flush: 5 cards of the same suit, highest card wins in a tie." << endl;
    os << "|  2 |"  << "|  4 |" << "|  6 |" << "|  8 |" << "|  K |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " straight: 5 cards in order but not of the same suit." << endl;
    os << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " three of a kind: 3 of a kind, highest card wins in a tie." << endl;
    os << "|  A |"  << "|  A |" << "|  A |" << "|  2 |" << "|  7 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " two pair: 2 sets of pairs." << endl;
    os << "|  K |"  << "|  K |" << "|  Q |" << "|  Q |" << "|  J |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " pair: 2 of a kind, highest card wins in a tie." << endl;
    os << "|  A |"  << "|  A |" << "|  9 |" << "|  8 |" << "|  7 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

    os << endl;

    os <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
    os << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " high card: no combination, only a single high ranked card" << endl;
    os << "|  A |"  << "|  8 |" << "|  6 |" << "|  4 |" << "|  2 |" << endl;
    os <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;


}

#endif