#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include <vector>

#include "deck.h"

/*
 * Base class for Player and Dealer
 *
 * Because Player and Dealer have common operations : Hit and CalculateHandSum
*/
class AbstractPlayer
{
    public:
        AbstractPlayer();
        virtual ~AbstractPlayer();

        virtual void Hit(Card* pCard);
        virtual int CalculateHandSum();

        virtual void ResetHand();

    protected:
        std::vector<Card*> m_hand;
        const int BLACKJACK = 21;

};

#endif // ABSTRACTPLAYER_H
