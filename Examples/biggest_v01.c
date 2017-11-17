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
int biggestv01( int argc, char* argv[] )
{
    char line[LINE_MAX];  // Big enough buffer to read one line at a time.
    char word1[LINE_MAX]; // Using the same size with line will prevent any overflow,
    char word2[LINE_MAX]; // for in case of one line without any delimiters.
    char * pBigWord  = word1; // Here, we use a pointer to point our word arrays.
    char * pCurrWord = word2; // By using pointers, we do not perform deep-copy of strings.
    char * pItLine = NULL; // Using indices is fine. But we use pointers in this example
    char * pItWord = NULL; // to iterate line and current word.
    unsigned int bigWeight  = 0; // Our integers in this example will not need negative numbers.
    unsigned int currWeight = 0; // By using unsigned integer, we guarantee zero and positive numbers.
    unsigned int lineNumber = 0;

    while( NULL != fgets( line, LINE_MAX, stdin ) )
    {   // Iterate until we do not have any more lines to read.
        lineNumber++;
        *pBigWord = '\0'; // Empty the biggest word variable.
        bigWeight = 0;    // The biggest word's weight has to be the smallest for now.
        pItLine = line;
        while( '\0' != *pItLine )
        {   // We iterate current line until we hit the null-terminator (i.e., end of line).
            *pCurrWord = '\0'; // Empty the current word.
            currWeight = 0;    // The word's weight has to be zero at the beginning.
            for( pItWord = pCurrWord; '\0' != *pItLine && ' ' != *pItLine && '\t' != *pItLine && '\n' != *pItLine; pItLine++, pItWord++ )
            {   // Current word continues until a tab, space, or null-terminator.
                *pItWord = *pItLine;
                currWeight += *pItLine;
            }
            *pItWord = '\0'; // Set null-terminator to complete our word.

            if( currWeight > bigWeight )
            {   // We found a word with bigger weight.
                // Swap the biggest and the current words.
                // pItWord is a temporary variable here.
                pItWord = pBigWord;
                pBigWord = pCurrWord;
                pCurrWord = pItWord;
                bigWeight = currWeight;
            }

            if( '\0' != *pItLine )
            {   // We move to next character only if it is not null-terminator.
                // This part is required to pass ' ' and '\t'.
                pItLine++;
            }
        }
        if( '\0' != *pBigWord )
        {   // We have big word. Print the result.
            printf( "line %d's word: %s\n", lineNumber, pBigWord );
        }
    }
    return EXIT_SUCCESS;
}

