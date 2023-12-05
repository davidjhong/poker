#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
    private:
        int rank;
        string suit;
        string name;
        string suitSymbol;
    public:
        Card(int, const string&, const string&, const string&);

        int getRank() const;
        string getSuit() const;
        string getSuitSymbol() const;
        string getName() const;
};

#endif