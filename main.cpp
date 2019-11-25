#include <iostream>
#include <ctime>
#include <cstdlib>

#include "deck.h"
#include "simpleplayer.h"
#include "game.h"

using namespace std;


int main()
{
    int player_chips = 100;
    int bet_for_player = 1;

    // Initialize pseudo random number generator
    srand(time(NULL));

    int result;
    SimplePlayer* pPlayer = new SimplePlayer(player_chips);// Player has 100 chips
    pPlayer->SetBet(bet_for_player);// Player bets 1 chip at a time

    while(pPlayer->HasChips() && pPlayer->WantsToPlay()) {
        Deck* pDeck = new Deck(); // Prepare new Deck for the game
        Dealer* pDealer = new Dealer(); // Prepare a new Dealer for the game
        Game* pGame = new Game(pDealer, pPlayer, pDeck); // Prepare a new game for the current configuration (i.e with Player, Dealer, and Deck)
        pGame->Init();
        pGame->Play();
        result = pGame->DetermineWinner();

        if (result != Game::DEALER_WINS_BLACKJACK &&
                result != Game::DEALER_WINS_GREATER_HAND &&
                result != Game::DEALER_WINS_PLAYER_BUST
            )
            pPlayer->IncreaseChips(pPlayer->GetBet());
//        else if (result == Game::PLAYER_PUSH)
//            ;
        else
            pPlayer->DecreaseChips(pPlayer->GetBet());

        delete pDeck;
        delete pDealer;
        delete pGame;
        pPlayer->ResetHand();
        cout << "Player's chips : " << pPlayer->GetChips() << endl;
    }

    return 0;
}
