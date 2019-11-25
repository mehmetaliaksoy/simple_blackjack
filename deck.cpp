#include "deck.h"
#include <iostream>

using namespace std;

Deck::Deck()
{
    createDeck();
}

Deck::~Deck()
{
    destroyDeck();
}

void Deck::destroyDeck()
{
    unsigned i;

    for(i = 0; i < m_cards.size(); ++i)
        delete m_cards[i];
}

void Deck::createDeck()
{
    int i, value;
    Card* pCard;

    for(i = 0; i < DECK_CARD_COUNT; ++i) {

        pCard = new Card();
        value = i % Card::VALUE::VALUE_MAX;
//        cout << "Deck::createDeck --> VALUE : " << value << endl;

        if(value == Card::VALUE::ACE) {
//            cout << "For " << i << " the value is ACE" << endl;
            pCard->SetValue( Card::ACE_VALUE );
        } else if ( value == Card::VALUE::JACK || value == Card::VALUE::QUEEN ||  value == Card::VALUE::KING) {
//            cout << "For " << i << " the value is JACK | QUEEN | KING" << endl;
            pCard->SetValue(Card::JACK_QUEEN_KING_VALUE);
        } else {
//            cout << "For " << i << " the value is JUST" << value << endl;
            pCard->SetValue(value + 1);
        }

        pCard->SetRank(value);
        pCard->SetSuit(i / Card::SUITE_CARD_COUNT);
        m_cards.push_back(pCard);
    }
}

void Deck::Print()
{
    unsigned i;

    cout << "******* DECK *******" << endl;
    for (i = 0; i < m_cards.size(); ++i)
        cout << m_cards[i]->GetCardName() << endl;
}

void Deck::Shuffle(int shuffleCount)
{
    int i, j;
    int randomIndex;
    Card* pTemp;


    for (i = 0; i < shuffleCount; ++i) {
        for (j = 0; j < DECK_CARD_COUNT / 2; ++j) {
            randomIndex = rand() % (DECK_CARD_COUNT / 2);
            randomIndex += j;
            pTemp = m_cards[j];
            m_cards[j] = m_cards[randomIndex];
            m_cards[randomIndex] = pTemp;
        }// j - inner for
    }// i - outer for
}

Card* Deck::GetCard()
{
    Card* pCard =  m_cards.front();
    m_cards.erase(m_cards.begin());

//    cout << "Deck::GetCard --> Deck has " << m_cards.size() << " card(s)" << endl;

    return pCard;

}

bool Deck::HasCard()
{
    return (!m_cards.empty());
}

