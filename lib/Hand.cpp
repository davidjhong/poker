#include <vector>
#include "../include/Hand.h"

using namespace std;

Hand::Hand(vector<Card*> cards) {
    for (int i = 0; i < cards.size(); i++) {
        hand.push_back(cards[i]);
    }
}

Hand::getCurrentHand() const {
    return this->hand;
}