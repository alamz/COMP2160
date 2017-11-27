#include <stdio.h>

#define NUMBER_OF_INTEGERS 2

int main( )
{
    int x = 0;
    int y = 0;
    int result = 0;
    printf( "BEFORE: %d, %d\n", x, y );
    result = scanf( "%d, %d", &x, &y );
    if( result == NUMBER_OF_INTEGERS )
    {
        printf( "AFTER: %d, %d\n", x, y );
    }
    else
    {
        printf( "ERROR\n" );
    }
    return 0;
}
