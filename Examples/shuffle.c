//------------------------------------------------
// NAME      : YOUR NAME
// STUDENT#  : #######
// 
// COURSE    : COMP 2160, SECTION: A01
// INSTRUCTOR: Stela H. Seo
// ASSIGNMENT: ##, QUESTION: ##
// 
// REMARKS   : 
//------------------------------------------------

//------------------------------------------------------------------------------
// INCLUDE HEADERS
// REMARKS: include standard library header files
//          include external library header files
//          include your own header files
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>


//------------------------------------------------------------------------------
// CONSTANTS AND TYPES
// REMARKS: preprocessor macro
//          type definitions
//          enumerations
//          structures
//------------------------------------------------------------------------------
#define DEBUG

typedef enum
{
    CARD_ACE = 0x0000,
    CARD_2,
    CARD_3,
    CARD_4,
    CARD_5,
    CARD_6,
    CARD_7,
    CARD_8,
    CARD_9,
    CARD_10,
    CARD_JACK,
    CARD_QUEEN,
    CARD_KING,
    CARD__NUM_CARDS,
    CARD__NUM_SUIT = 4,
    CARD_SPADE = 0x0000,
    CARD_HEART = 0x0100,
    CARD_CLUB = 0x0200,
    CARD_DIAMOND = 0x0300,
} CARD;


//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------
CARD * createDeck( int * count );
void printDeck( const CARD * deck, int count );
void shuffleDeck( CARD * deck, int count );
static const char * SuitToString( CARD suit );
static const char * CardToString( CARD card );


//------------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
int main( void )
{
    int deckSize = 0;
    CARD * deck = createDeck( &deckSize );
    printDeck( deck, deckSize );
    fgetc( stdin );
    shuffleDeck( deck, deckSize );
    printDeck( deck, deckSize );
    fgetc( stdin );
	shuffleDeck( deck, deckSize );
    printDeck( deck, deckSize );
    return EXIT_SUCCESS;
}

CARD * createDeck( int * count )
{
    CARD * deck = NULL;
    int i, suit, card;

    assert( count );
    if( count )
    {
        deck = (CARD *)malloc( sizeof( CARD ) * CARD__NUM_SUIT * CARD__NUM_CARDS );
        assert( deck );
        if( deck )
        {
            *count = CARD__NUM_SUIT * CARD__NUM_CARDS;
            for( i = 0, suit = 0; suit < CARD__NUM_SUIT; suit++ )
            {
                for( card = 0; card < CARD__NUM_CARDS; card++ )
                {
                    deck[i++] = (suit << 8) | card;
                }
            }
        }
    }
    return deck;
}


void printDeck( const CARD * deck, int count )
{
    CARD suit, card;
    int i;

    assert( deck && count >= 0 );
    if( deck && count >= 0 )
    {
        for( i = 0; i < count; i++ )
        {
            suit = deck[i] & 0xFF00;
            card = deck[i] & 0x00FF;
            printf( "%d: %s %s\n", i, SuitToString( suit ), CardToString( card ) );
        }
    }
}


void shuffleDeck( CARD * deck, int count )
{
    CARD tmp;
    int i, j;

    assert( deck && count >= 0 );
    if( deck && count >= 0 )
    {
        srand( (unsigned int)time( NULL ) );
        for( i = 0; i < count; i++ )
        {
            j = rand( ) % count;
            tmp = deck[i];
            deck[i] = deck[j];
            deck[j] = tmp;
        }
    }
}


static const char * SuitToString( CARD suit )
{
    switch( suit )
    {
    case CARD_SPADE:
        return "Spade";
    case CARD_HEART:
        return "Heart";
    case CARD_CLUB:
        return "Club";
    case CARD_DIAMOND:
        return "Diamond";
    }
    return "Unknown";
}


static const char * CardToString( CARD card )
{
    switch( card )
    {
    case CARD_ACE:
        return "Ace";
    case CARD_2:
        return "2";
    case CARD_3:
        return "3";
    case CARD_4:
        return "4";
    case CARD_5:
        return "5";
    case CARD_6:
        return "6";
    case CARD_7:
        return "7";
    case CARD_8:
        return "8";
    case CARD_9:
        return "9";
    case CARD_10:
        return "10";
    case CARD_JACK:
        return "Jack";
    case CARD_QUEEN:
        return "Queen";
    case CARD_KING:
        return "King";
    }
    return "Unknown";
}

