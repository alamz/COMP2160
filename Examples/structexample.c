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
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//------------------------------------------------------------------------------
// CONSTANTS AND TYPES
//------------------------------------------------------------------------------
typedef struct TEST
{
    int value;
} TEST;


//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
int writeValue( struct TEST * t )
{
    t->value = 10;
    return 0;
}

TEST readValue( )
{
    TEST t;
    t.value = 1000;
    return t;
}

int main( )
{
    TEST test = readValue( );
    test.value = 100;
    printf( "%d\n", test.value );
    writeValue( &test );
    printf( "%d\n", test.value );
    test = readValue( );
    printf( "%d\n", test.value );
}

