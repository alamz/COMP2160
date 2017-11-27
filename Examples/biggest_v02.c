//------------------------------------------------
// COURSE    : COMP 2160, SECTION: A01
// INSTRUCTOR: Stela H. Seo
// ASSIGNMENT: 01, QUESTION: 2
// PURPOSE   : Determine the longest word on an input line and display that word.
// REMARKS   : Let's rewrite Biggest.java in C
//------------------------------------------------

//------------------------------------------------------------------------------
// INCLUDE HEADERS
//------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//------------------------------------------------------------------------------
// CONSTANTS AND TYPES
//------------------------------------------------------------------------------
#define LINE_MAX 2048 // we will use a big enough space to keep one line


//------------------------------------------------------------------------------
// PROTOTYPES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// VARIABLES
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    char line[LINE_MAX];     // Big enough buffer to read one line at a time.
    char * pBigWord  = NULL; // Here, we use a pointer to point a word on the line.
    char * pCurrWord = NULL; // By using pointers, we do not perform deep-copy of strings.
    char * pItLine = NULL;   // We use pointers in this example to iterate the line.
    unsigned int bigWeight  = 0; // Our integers in this example will not need negative numbers.
    unsigned int currWeight = 0; // By using unsigned integer, we guarantee zero and positive numbers.
    unsigned int lineNumber = 0;

    while( NULL != fgets( line, LINE_MAX, stdin ) )
    {   // Iterate until we do not have any more lines to read.
        lineNumber++;
        pBigWord = NULL; // The biggest word will be NULL if not exist.
        bigWeight = 0;   // The biggest word's weight has to be the smallest for now.
        pItLine = line;
        while( '\0' != *pItLine )
        {   // We iterate current line until we hit the null-terminator (i.e., end of line).
            pCurrWord = pItLine; // Set the current word.
            currWeight = 0;      // The word's weight has to be zero at the beginning.
            for( ; '\0' != *pItLine && ' ' != *pItLine && '\t' != *pItLine && '\n' != *pItLine; pItLine++ )
            {   // Current word continues until a space, tab, new line, or null-terminator.
                currWeight += *pItLine;
            }
            if( '\0' != *pItLine )
            {   // We move to next character only if it is not null-terminator.
                // This part is required to pass delimiters other than the null-terminator.
                *pItLine = '\0'; // Set the end of word, null-terminator.
                pItLine++;
            }
            if( currWeight > bigWeight )
            {   // We found a word with bigger weight.
                // Swap the biggest and the current words.
                pBigWord = pCurrWord;
                bigWeight = currWeight;
            }
        }
        if( NULL != pBigWord )
        {   // We have big word. Print the result.
            printf( "line %u's word: %s\n", lineNumber, pBigWord );
        }
    }
    return EXIT_SUCCESS;
}

