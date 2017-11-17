#include <stdlib.h>
#include <stdio.h>

#define MAX( a, b ) ((a)>(b)?(a):(b))
#define ODD( a ) ((a) % 2 != 0)

#define DEBUG

int main( )
{
    int oldValue = 100;
    int newValue = 10;
#ifdef DEBUG
    // As DEBUG is defined above, statements inside of this #ifdef remains as they are.
    printf( "OLD: %d\n", oldValue );
    printf( "NEW: %d\n", newValue );
    // If DEBUG is not defined, statements inside of this #ifdef becomes empty lines in compiler's perspective.
    // Note: you can use -DDEBUG flag instead of #define DEBUG
#endif
    printf( "%d\n", ODD( oldValue + newValue ) );
    // Preprocessor goes through once before compiling the code, then the line above becomes
    //printf( "%d\n", ((oldValue + newValue) % 2 != 0) );
    return EXIT_SUCCESS;
}
