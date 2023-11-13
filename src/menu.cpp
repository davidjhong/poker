#include <iostream>
#include "../header/menu.hpp"

using namespace std;

void displayRules ();
void displayCardCombinations();

int main()
{
    string userInput;
    cout << "-------------- START MENU -----------------" << endl;
    cout << "rules" << endl;
    cout << "card rankings" << endl;
    cout << "card combinations" << endl;
    cout << "set starting amount" << endl;
    cout << "start game" << endl;
    cout << "-------------------------------------------" << endl;
    
    while (true)
    {
        getline(cin, userInput);

        if (userInput == "rules")
        {
            displayRules();
            break;
        }
        else if (userInput == "card rankings" || userInput == "cr")
        {
            cout << "todo" << endl;
            break;
        }
        else if (userInput == "card combinations" || userInput == "cc")
        {
            displayCardCombinations();
            break;
        }
        else if (userInput == "set starting amount" || userInput == "starting amount")
        {
            cout << "todo" << endl;
            break;
        }
        else if (userInput == "start game" || userInput == "start")
        {
            cout << "todo" << endl;
            break;
        }
        else
        {
            cout << "re-enter start menu option" << endl;
        }
    }
}

// void displayRules()
// {
//     cout << endl;
//     cout << "Overview: " << endl;
//     cout << "Each player will be dealt two hole cards, followed by five community cards which will be dealt face up in intervals. " << endl;
//     cout << "*Note that hole cards are cards that are kept face down throughtout the entire game, and can only be seen by the player that holds them. " << endl;
//     cout << "The objective of the game is to make the best five-card poker hand using any combination of the player's hole cards and community cards" << endl;
//     cout << endl << "Texas Hold' em - in depth: " << endl;
//     cout << "At the start of the round, before any cards are dealt, players will place their initial bets. The player to the dealer's left will post " << endl << "the small blind, then the player to their left will post the big blind, which is double the value of the small blind. ";
//     cout << "2 hole cards will be dealt to each player. " << endl << "The starting player may now choose to fold, call or raise. " << endl;
//     cout << "   fold: discard hand and put no more chips in the pot" << endl;
//     cout << "   call: add the call amount to the pot" << endl;
//     cout << "   raise: increase the call amount for the current round" << endl;
//     cout << "Following this player's first move, each player will take their turn to call, raise or fold until every player has gone. After every player " << endl << "has folded, called or raised, the dealer will deal the first 3 community cards face up. The players may now use these three cards to decide upon their next move. " << endl;
//     cout << "Each player will again choose to fold, call or raise. Then, the dealer will show the fourth community card, and each player will again choose " << endl << "to fold, call or raise.";
//     cout << "Finally, the dealer will reveal the last community card. This fourth round of betting will continue until all players have folded, called or raised." << endl;
//     cout << "At this point, all remaining players will show their best hand from their two hole cards and 5 community cards. The player with the highest " << endl << "ranked combination wins the pot." << endl;
//     cout << "If players tie, the highest hole card that isn't a part of their best hand is used to decide the winner." << endl;
// }

// void displayCardCombinations()
// {
//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " royal flush: straight flush from 10 to Ace." << endl;
//     cout << "| 10 |"  << "|  J |" << "|  Q |" << "|  K |" << "|  A |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " straight flush: straight, but all cards are the same suit." << endl;
//     cout << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " four of a kind: four of the same card, highest value wins in a tie." << endl;
//     cout << "|  A |"  << "|  A |" << "|  A |" << "|  A |" << "|  2 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♧  |" << "| ♢  |" << " full house: 3 of a kind + 2 of a kind, highest 3 of a kind wins in a tie." << endl;
//     cout << "|  A |"  << "|  A |" << "|  A |" << "|  K |" << "|  K |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♡  |"  << "| ♡  |" << "| ♡  |" << "| ♡  |" << "| ♡  |" << " flush: 5 cards of the same suit, highest card wins in a tie." << endl;
//     cout << "|  2 |"  << "|  4 |" << "|  6 |" << "|  8 |" << "|  K |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " straight: 5 cards in order but not of the same suit." << endl;
//     cout << "|  5 |"  << "|  6 |" << "|  7 |" << "|  8 |" << "|  9 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " three of a kind: 3 of a kind, highest card wins in a tie." << endl;
//     cout << "|  A |"  << "|  A |" << "|  A |" << "|  2 |" << "|  7 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " two pair: 2 sets of pairs." << endl;
//     cout << "|  K |"  << "|  K |" << "|  Q |" << "|  Q |" << "|  J |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " pair: 2 of a kind, highest card wins in a tie." << endl;
//     cout << "|  A |"  << "|  A |" << "|  9 |" << "|  8 |" << "|  7 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;

//     cout << endl;

//     cout <<  " ----"   <<  "  ----" << "  ----" << "  ----" << "  ----" << endl;
//     cout << "| ♢  |"  << "| ♡  |" << "| ♤  |" << "| ♡  |" << "| ♤  |" << " high card: no combination, only a single high ranked card" << endl;
//     cout << "|  A |"  << "|  8 |" << "|  6 |" << "|  4 |" << "|  2 |" << endl;
//     cout <<  " ----"  << "  ----" << "  ----" << "  ----"<< "  ----"<<endl;


// }

