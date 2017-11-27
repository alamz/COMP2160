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


//------------------------------------------------------------------------------
// CONSTANTS AND TYPES
// REMARKS: preprocessor macro
//          type definitions
//          enumerations
//          structures
//------------------------------------------------------------------------------
#define DEBUG


//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------
int IsSortedASC( const int * array, int size );
int IsSortedDSC( const int * array, int size );


//------------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
int main( void )
{
    int data_asc_sorted[] = { -20, -10, 0, 10, 20, 30, 40 };
    int data_dsc_sorted[] = { 40, 30, 20, 10, 0, -10 };
    int data_not_sorted[] = { 1, 63, 6, 34, 71, 46, 6, 57, 9, 2, 459, 24 };
    printf( "%s\n", IsSortedASC( data_asc_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    printf( "%s\n", IsSortedASC( data_dsc_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    printf( "%s\n", IsSortedASC( data_not_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    printf( "%s\n", IsSortedDSC( data_asc_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    printf( "%s\n", IsSortedDSC( data_dsc_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    printf( "%s\n", IsSortedDSC( data_not_sorted, sizeof( data_asc_sorted ) / sizeof( int ) ) ? "True" : "False" );
    return EXIT_SUCCESS;
}


int IsSortedASC( const int * array, int size )
{
    int i = 1;
    int sorted = 1;
    while( sorted && i < size )
    {
        sorted = array[i - 1] <= array[i];
        i++;
    }
    return sorted;
}


int IsSortedDSC( const int * array, int size )
{
    int sorted = 1;
    while( sorted && --size > 0 )
    {
        sorted = *array >= *(array + 1);
        array++;
    }
    return sorted;
}

