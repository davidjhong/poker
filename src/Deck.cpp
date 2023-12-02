#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
#include "../header/Deck.h"

using namespace std;

Deck::Deck()
{
    currentCardIndex = 0;
    vector<string> ranks {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    vector<string> suits {"Diamonds", "Hearts", "Clubs", "Spades"}; 
    vector<string> suitSymbols {"♦","♥","♣","♠"};

    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card* newCard = new Card(i + 1, suits.at(j), ranks.at(i) + " of " + suits.at(j), suitSymbols.at(j));
            allCards.push_back(newCard);
        }
    }

}

Deck::~Deck()
{
    for (int i = 0; i < allCards.size(); i++)
    {
        delete allCards.at(i);
    }
}

void Deck::shuffleDeck(bool random) // bool random is whether a random seed is created
{                                   // bool random false is for testing
    if (random)
    {
        srand(unsigned(time(0)));
    }
    else
    {
        srand(0);
    }

    random_shuffle(allCards.begin(), allCards.end());
}

Card* Deck::nextCard()
{
    Card* nextCard = allCards[currentCardIndex];
    currentCardIndex++;
    return nextCard;
}