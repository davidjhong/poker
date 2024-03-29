#include <string>
#include "../include/Card.h"

using namespace std;

Card::Card()
{
    this->rank = 0;
    this->suit = "";
    this->name = "";
}

Card::Card(int rank, string suit, string name)
{
    this->rank = rank;
    this->suit = suit;
    this->name = name;
}

int Card::getRank() const
{
    return this->rank;
}

string Card::getSuit() const
{
    return this->suit;
}

string Card::getName() const
{
    return this->name;
}

void Card::setRank(int rank)
{
    this->rank = rank;
}

void Card::setSuit(string suit)
{
    this->suit = suit;
}