#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( )
{
    char str[] = "This is Testing (100, 200)";
    char* token;
    token = strtok( str, "(), " );
    while( NULL != token )
    {
        printf( "TOKEN: (%s)\n", token );
        token = strtok( NULL, "(), " );
    }
    return EXIT_SUCCESS;
}
