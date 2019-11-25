#include "card.h"

using namespace std;

const int Card::ACE_VALUE = 11;
const int Card::JACK_QUEEN_KING_VALUE = 10;
const int Card::SUITE_CARD_COUNT = 13;

Card::Card()
{
    m_suit = SUITE::SUITE_MAX;
    m_value = VALUE::VALUE_MAX;
}

Card::Card(int value, int suit)
{
    m_suit = suit;
    m_value = value;
}

void Card::SetSuit(int suit)
{
    m_suit = suit;
}

int Card::GetSuit()
{
    return m_suit;
}

void Card::SetValue(int value)
{
    m_value = value;
}

int Card::GetValue()
{
    return m_value;
}

void Card::SetRank(int rank)
{
    m_rank = rank;
}

int Card::GetRank()
{
    return m_rank;
}


std::string Card::GetCardName()
{
    string str = m_cardNames[m_rank];
    return (str + " of " + m_suitNames[m_suit]);
}

//void Card::SetAceValue(int value)
//{
//    m_aceValue = value;
//}

//int Card::GetAceValue()
//{
//    return m_aceValue;
//}


