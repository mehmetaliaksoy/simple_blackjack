#include "simpleplayer.h"

#include <iostream>

using namespace std;

SimplePlayer::SimplePlayer()
{
    m_chips = 0;
}

SimplePlayer::SimplePlayer(int chips)
{
    m_chips = chips;
}

SimplePlayer::~SimplePlayer()
{
    ResetHand();
}

void SimplePlayer::SetChips(int chips)
{
    m_chips = chips;
}

int SimplePlayer::GetChips()
{
    return m_chips;
}

void SimplePlayer::Stand()
{
}

void SimplePlayer::IncreaseChips(int won)
{
    m_chips += won;
}

void SimplePlayer::DecreaseChips(int lost)
{
    m_chips -= lost;
}

void SimplePlayer::SetBet(int bet)
{
    m_bet = bet;
}

int SimplePlayer::GetBet()
{
    return m_bet;
}

/*
 * Overridable action/game logic for SimplePlayer
 *
 * Current simple logic : Just user selection!
 * It could be evaluation of the hand and selection of an action
 * according to the cards at hand.
*/
int SimplePlayer::ExecuteGameLogic()
{
    int option;

    cout << "Current sum is " << CalculateHandSum() << endl;
    cout << "OPTIONS:" << endl;
    cout << "\t1-) HIT" << endl;
    cout << "\t2-) STAND" << endl;
    cout << "Enter your choice : " << endl;
    cin >> option;
    return option;

}

/*
 * Overridable logic to decide to keep playing
 *
 * Current simple logic : Play until you lose half of the chips!
*/
bool SimplePlayer::WantsToPlay()
{
    return (m_chips > (m_initialChips / 2));
}
