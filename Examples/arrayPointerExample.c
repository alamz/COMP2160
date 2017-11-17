#include <stdio.h>

int main( int argc, char* argv[] )
{
    int array[4];
    int * ptr1 = &(array[1]);
    int * ptr2 = array + 1;
    int * ptr3 = (int*)(((char*)array) + sizeof( int ));
    printf( "%p\n", ptr1 );
    printf( "%p\n", ptr2 );
    printf( "%p\n", ptr3 );
    return 0;
}
