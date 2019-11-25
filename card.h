#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
    public:
        enum VALUE { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, VALUE_MAX };
        enum SUITE { SPADES, HEARTS, CLUBS, DIAMONDS, SUITE_MAX };
        static const int ACE_VALUE;// = 11;
        static const int JACK_QUEEN_KING_VALUE;// = 10;
        static const int SUITE_CARD_COUNT;// = 13;


    public:
        Card();
        Card(int value, int suit);

        void SetSuit(int suit);
        int GetSuit();

        void SetValue(int value);
        int GetValue();

        void SetRank(int value);
        int GetRank();

        std::string GetCardName();

//        void SetAceValue(int value);
//        int GetAceValue();


    private:
        int m_value;
        int m_suit;
        int m_rank;
//        int m_aceValue;

        std::string m_cardNames[VALUE::VALUE_MAX + 1] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Unknown" };
        std::string m_suitNames[SUITE::SUITE_MAX + 1] = {"Spades", "Hearts", "Clubs", "Diamonds", "Unknown" };

};

#endif // CARD_H
