#include "abstractplayer.h"

#include <iostream>

AbstractPlayer::AbstractPlayer()
{
}

AbstractPlayer::~AbstractPlayer()
{
    ResetHand();
}

void AbstractPlayer::Hit(Card *pCard)
{
    m_hand.push_back(pCard);
}

void AbstractPlayer::ResetHand()
{
    unsigned i;

    if (m_hand.size() > 0) {
        for(i = 0; i < m_hand.size(); ++i)
            delete m_hand[i];
        m_hand.clear();
    }
}

int AbstractPlayer::CalculateHandSum()
{
    int sum = 0;
    int value;
    Card* card;
    unsigned i;

    for (i = 0; i < m_hand.size(); ++i ) {
        card = m_hand[i];

        if (Card::VALUE::ACE == card->GetValue() && sum + 11 <= BLACKJACK)
            value = 11;
        else
            value = card->GetValue();
//        std::cout << "Card : " << card->GetCardName() << " and its value is " << value << std::endl;
        sum += value;
    }
//    std::cout << "Player's sum is " << sum << std::endl;
    return sum;
}
