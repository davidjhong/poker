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
    public:
        Card();
        Card(int, string, string);

        int getRank() const;
        string getSuit() const;
        string getName() const;

        void setRank(int);
        void setSuit(string);
};

#endif