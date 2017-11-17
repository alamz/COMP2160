#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

typedef enum BOOL { false, true } Boolean;

typedef struct NODE Node;
struct NODE{
  char *item;
  Node *next;
};


//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

// add an element to the beginning of the linked list
Boolean insert( char *new_string );
// empty the list so that we clear all memory and can start a fresh list
void clearList();
// tells us whether or not the given string is in the list
Boolean search( char *target );
// starts a list traversal by getting the data at top
char * firstItem();
// increment the traversal and gets the data at the current traversal node
char * nextItem();

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

// read from standard input, tokenize and insert words into a linked list
// note that we must ensure that there are no duplicates in our list
void loadFile()
{
#define LINE_SIZE 256
  char input[LINE_SIZE];
  char *token = NULL;
  
  while ( fgets( input, LINE_SIZE, stdin ) )
  {
    // parse the data into separate elements
    token = strtok( input, " \t\n" );
    while ( token )
    {
      if ( !search( token ) )
        insert( token );
      
      token = strtok( NULL, " \t\n" );
    }
  }
}

// print the contents of the linked list to standard output
void printConcordance()
{
  char *theWord = firstItem();
  
  while ( theWord )
  {
    printf( "%s\n", theWord );
    theWord = nextItem();
  }
}

int main( int argc, char *argv[] )
{
  loadFile();
  printConcordance();
  clearList();
  
  return EXIT_SUCCESS;
}
