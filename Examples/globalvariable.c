#include <stdio.h>

#define MAX_STRING 50


int global = 100;


int test( )
{
    return global;
}


int main( )
{
    int value = 1;
    printf( "%d %d\n", value, global );
    return 0;
}
