#ifndef DECK_H
#define DECK_H

#include <vector>

#include "card.h"

class Deck
{
    public:
        Deck();
        ~Deck();

        void Shuffle(int shuffleCount = 3);
        void Print();
        Card* GetCard();
        bool HasCard();

    private:
        const int DECK_CARD_COUNT = 52;
        std::vector<Card*> m_cards;

        void createDeck();
        void destroyDeck();
};

#endif // DECK_H
