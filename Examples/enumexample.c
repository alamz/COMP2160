#include <stdlib.h>

//const int CLUBS = 0;
//const int DIAMONDS = 1;
//const int HEARTS = 2;
//const int SPADES = 3;

// Above is essentially the same with below
//enum CARDS
//{
//    CLUBS,
//    DIAMONDS,
//    HEARTS,
//    SPADES,
//};

// But I recommend to use enum over const in this case, 
// because it tells you the 'type' and nicely assigns values that you need.

// In class, I have mentioned about having length at the end.
// I will give you an small example which shows how this can be used below.
typedef enum
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    DECK_LENGTH
}DECKS;

typedef enum
{
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,
    C9,
    JACK,
    QUEEN,
    KING,
    CARDS_LENGTH
}CARDS;

#define YANG 0
#define STELA 1

int main( )
{
    CARDS howOwns[DECK_LENGTH][CARDS_LENGTH] = { 0 };
    howOwns[DIAMONDS][KING] = STELA; // Stela stole King of Diamond!
    return EXIT_SUCCESS;
}
