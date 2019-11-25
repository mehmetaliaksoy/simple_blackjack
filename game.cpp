#include "game.h"

#include <iostream>

using namespace std;

Game::Game(Dealer *pDealer, SimplePlayer *pPlayer, Deck* pDeck)
    :m_pDealer(pDealer),
      m_pPlayer(pPlayer),
      m_pDeck(pDeck)
{
}

void Game::Init(int shuffleCount)
{
    int i;
    cout << "******* Game Starts *******"<<endl;

    m_pDeck->Shuffle(shuffleCount);

    for (i = 0; i < INITIAL_CARD_COUNT; ++i) {
        m_pDealer->Hit(m_pDeck->GetCard());
        m_pPlayer->Hit(m_pDeck->GetCard());
    }
}

int Game::getPlayerChoice()
{
    return m_pPlayer->ExecuteGameLogic();
}

void Game::Play()
{
    int choice;

    while(m_pPlayer->CalculateHandSum() < BLACKJACK) {
        choice = getPlayerChoice();
        if(SimplePlayer::CHOICE::HIT == choice)
            m_pPlayer->Hit(m_pDeck->GetCard());
        else
            break;
    }

    cout << "******* Game over *******" << endl;
    while (m_pDealer->CalculateHandSum() < DEALER_BOTTOM_LIMIT)
        m_pDealer->Hit(m_pDeck->GetCard());
}


int Game::DetermineWinner()
{
    cout << "******* Check Hands & Determine Winner *******" << endl;
    int dealerHand = m_pDealer->CalculateHandSum();
    int playerHand = m_pPlayer->CalculateHandSum();
    int result = UNKNOWN;

    cout << "Dealer's hand is " << dealerHand << endl;
    cout << "Player's hand is " << playerHand << endl;

    string resultString = "";
    if (playerHand == BLACKJACK && dealerHand == BLACKJACK) {
        resultString += "Player Blackjack Push!\n";
        result = BLACKJACK_PUSH;
    } else if (playerHand == BLACKJACK && dealerHand != BLACKJACK) {
        resultString += "Player Wins, Blackjack!\n";
        result = PLAYER_WINS_BLACKJACK;
    } else if(playerHand != BLACKJACK && dealerHand == BLACKJACK) {
        resultString+= "Dealer Wins, Blackjack!\n";
        result = DEALER_WINS_BLACKJACK;
    } else if (playerHand <BLACKJACK && playerHand > dealerHand) {
        resultString+= "Player Wins!\n";
        result = PLAYER_WINS_GREATER_HAND;
    } else if (playerHand > BLACKJACK) {
        resultString+= "Player Bust, lose!\n";
        result = DEALER_WINS_PLAYER_BUST;
    } else if (dealerHand > BLACKJACK) {
        resultString+= "Dealer Bust, Player Wins!\n";
        result = PLAYER_WINS_DEALER_BUST;
    } else if (playerHand == dealerHand) {
        resultString += "Player Push!\n";
        result = PLAYER_PUSH;
    } else if (playerHand < dealerHand) {
        resultString += "Player loses!\n";
        result = DEALER_WINS_GREATER_HAND;
    }
    cout << resultString << endl;
    return result;
}
