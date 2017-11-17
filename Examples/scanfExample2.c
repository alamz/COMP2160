#include <stdio.h>

#define MAX_STRING 50

int main( )
{
    char str[MAX_STRING] = { 0 };
    int result = 0;
    scanf( "%d%s", &result, str );
    printf( "%s\n%d\n", str, result );
    return 0;
}
