#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    FALSE,
    TRUE,
} bool;
// Above typedef is very similar to below three lines
//#define bool int
//#define FALSE 0
//#define TRUE 1
// However, I recommend to use typedef because you are defining a boolean type.
// Your choice should be not based on how easy to type.
// Choose appropriate technique.

int main( )
{
    bool a = 0; // this works!
    bool b = FALSE;
    printf( "%d %d\n", a, b );
    return 0;
}
