#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0;
    const int numOfStrings = 128;
    char* strArray[numOfStrings];
    char writablestring[]= "The C Programming Language";
    char *token = strtok(writablestring, " ");

    for( int j = 0; j < numOfStrings; j++ )
    {
        strArray[j] = ;
    }

    while(token != NULL)
    {
        strcpy(strArray[i], token);
        printf("[%s]\n", token);
        token = strtok(NULL, " ");
        i++;
    }
    return 0;
}