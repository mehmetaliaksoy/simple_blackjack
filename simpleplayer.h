#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "abstractplayer.h"


/*
 * Extendible SimplePlayer
 *
 * It can be extended by inheritance and overriding of
 * ExecuteGameLogic and WantsToPlay functions.
*/

class SimplePlayer : public AbstractPlayer
{
    public:
        SimplePlayer();
        SimplePlayer(int chips);
        virtual ~SimplePlayer();

        /* Accessor methods */
        void SetChips(int chips);
        int GetChips();
        void IncreaseChips(int won);
        void DecreaseChips(int lost);
        bool HasChips() { return ((m_chips > 0) ? true : false ); }
        void SetBet(int bet);
        int GetBet();

        /* Overridable Game Logic functions and Enumeration */
        enum CHOICE { UNDEFINED, HIT, STAND };
        virtual int ExecuteGameLogic();
        virtual bool WantsToPlay();

        /* One of two basic Player options. The other one (i.e Hit) comes from AbstractPlayer via inheritance */
        void Stand();

    private:
        std::vector<Card*> m_hand;
        int m_chips;
        int m_initialChips;
        int m_bet;
};

#endif // PLAYER_H
