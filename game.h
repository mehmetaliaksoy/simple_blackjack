#ifndef GAME_H
#define GAME_H

#include "dealer.h"
#include "simpleplayer.h"

class Game
{
    public:
        enum Result {
                        UNKNOWN,
                        BLACKJACK_PUSH,
                        PLAYER_WINS_BLACKJACK,
                        DEALER_WINS_BLACKJACK,
                        PLAYER_WINS_GREATER_HAND,
                        DEALER_WINS_PLAYER_BUST,
                        PLAYER_WINS_DEALER_BUST,
                        PLAYER_PUSH,
                        DEALER_WINS_GREATER_HAND
                    };

        Game(Dealer* pDealer, SimplePlayer* pPlayer, Deck* pDeck);

        void Init(int shuffleCount = 5);
        void Play();
        int DetermineWinner();

    private:
        int getPlayerChoice();

        const int BLACKJACK = 21;
        const int DEALER_BOTTOM_LIMIT = 17;
        const int INITIAL_CARD_COUNT = 2;



        Dealer* m_pDealer;
        SimplePlayer* m_pPlayer;
        Deck* m_pDeck;
};

#endif // GAME_H
