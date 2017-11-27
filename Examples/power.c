//------------------------------------------------
// COURSE    : COMP 2160, SECTION: A01
// INSTRUCTOR: Stela H. Seo
// ASSIGNMENT: 01, QUESTION: 1
// PURPOSE   : Compute powers using two different algorithms.
// REMARKS   : Let's rewrite Power.java in C
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
#define BASE_LENGTH 4


//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------
double power1( double base, int index );
double power2( double base, int index );


//------------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------------
static int count = 0;


//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
int power( int argc, char* argv[] )
{
    double base[BASE_LENGTH] = { 1.4, 1.3, 1.2, 1.1 };
    int index[BASE_LENGTH] = { 5, 20, 63, 73 };
    double value;
    int i;
    printf( "\nTest two algorithms for powering\n\n" );
    for( i = 0; i < BASE_LENGTH; i++ )
    {
        count = 0;
        value = power1( base[i], index[i] );
        printf( "1: %lf^%d = %lf, used %d multiplies\n", base[i], index[i], value, count );

        count = 0;
        value = power2( base[i], index[i] );
        printf( "2: %lf^%d = %lf, used %d multiplies\n", base[i], index[i], value, count );

        printf( "\n" );
    }
    printf( "\nEnd of processing\n" );
    return EXIT_SUCCESS;
}


double power1( double base, int index )
{
    double retValue;
    if( index == 0 )
    {
        retValue = 1;
    }
    else
    {
        retValue = base * power1( base, index - 1 );
        count++;
    }
    return retValue;
}


double power2( double base, int index )
{
    double retValue;
    double temp;
    if( index == 0 )
    {
        retValue = 1;
    }
    else if( index % 2 == 1 )
    {
        retValue = base * power2( base, index - 1 );
        count++;
    }
    else
    {
        temp = power2( base, index / 2 );
        retValue = temp * temp;
        count++;
    }
    return retValue;
}

