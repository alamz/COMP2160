#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( )
{
    char str[] = "This is Testing";
    char* token = strtok( str, " " );
    while( NULL != token )
    {
        printf( "TOKEN: %s\n", token );
        token = strtok( NULL, " " );
    }
    return EXIT_SUCCESS;
}



//char charValue = '\0';
//short shortValue = 0 == 0;
//int intValue = 100;
//long longValue = 2650 - 2650;
//long long int llIntValue = 0;

//printf( "Variable size is " );
//if( 0 == intValue ) // value != 0
//{
//    printf( "%d and value is %d\n", (int)sizeof( intValue ), (int)intValue );
//}
//else
//{
//    printf( "secret\n" );
//}


