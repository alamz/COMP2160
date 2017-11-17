/*
 * ConcordLL.c
 * COMP 2160 Programming Practices
 * 
 * Assignment 2 sample solution
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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

Node *head = NULL;

// used to track where we are for the list traversal methods
Node *traverseNode = NULL;

// used to track testing values
int numNodes = 0;
int numTraversals = 0;

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
// increment the traversal and get the data at the current traversal node
char * nextItem();

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

// read from standard input, tokenize and insert words into a linked list
// note that we must ensure that there are no duplicates in our list
void loadFile(){
#define LINE_SIZE 256
  char input[LINE_SIZE];
  char *token = NULL;
  
  while ( fgets( input, LINE_SIZE, stdin ) ) {
    // parse the data into separate elements
    token = strtok( input, " \t\n" );
    while ( token ){
      if ( !search( token ) )
        insert( token );
      
      token = strtok( NULL, " \t\n" );
    }// while ( token )
  }// while( fgets...
}// loadFile

// print the contents of the linked list to standard output
void printConcordance(){
  char *theWord = firstItem();
  
  while ( theWord )  {
    printf( "%s\n", theWord );
    theWord = nextItem();
  }
}// printConcordance

int main( int argc, char *argv[] ){
  loadFile();
  printConcordance();
  clearList();
  
  return EXIT_SUCCESS;
}// main

//-------------------------------------------------------------------------------------
// Linked List Implementation
//-------------------------------------------------------------------------------------

void validateList(){
  if ( numNodes == 0 )
    assert( head == NULL );
  else if ( numNodes == 1 )
    assert( head->next == NULL );
  else // numNodes > 1
    assert( head != NULL && head->next != NULL );
  // how far should we really go???
}// validateList

// add an element to the beginning of the linked list
Boolean insert( char *new_string ){
  Boolean rc = false;
  Node *newNode = NULL;
  
  assert( new_string != NULL );
  if ( new_string ){
    newNode = (Node *)malloc( sizeof( Node ) );
    assert( newNode != NULL );
    
    if ( newNode ){
      // note that we need to have space for the string as well!
      newNode->item = strdup(new_string);
      assert( newNode->item != NULL );
      
      if ( newNode->item ){        
        newNode->next = head;
        head = newNode;        
        numNodes++;
        
        rc = true;
        
        // make sure the list is stable
        validateList();
      } else {
        free( newNode );
      }// if ( newNode->item )
    }// if ( newNode )
  }// if( new_string )
  
  return rc;
}// insert


// empty the list so that we clear all memory and can start a fresh list
void clearList(){
  Node *curr = head;
  
  while ( head != NULL ){
    head = head->next;
    free( curr->item );
    free( curr );
    curr = head;
    
    numNodes--;
  }// while
  
  validateList();
}// clearList


// tells us whether or not the given string is in the list
Boolean search( char *target ){
  Boolean found = false;
  char *curr = firstItem();
  int search_count = 0;     // how far in the list do we go?
  
  assert( target != NULL );
  if ( target != NULL ) {
    while ( curr != NULL && !found ){
      if ( strcmp( target, curr ) == 0 ){
        found = true;
        
        // make sure we're still in our list...
        assert( search_count <= numNodes );
      } else {
        curr = nextItem();
        search_count++;
      }// else
    }// while
  }// if( target != NULL )
  
  // if it's not found then we should be at the end of the list
  assert( found || (search_count == numNodes) );
  
  return found;
}// search


// starts a list traversal by getting the data at head
char * firstItem(){
  char *the_item = NULL;
  
  traverseNode = head;
  if ( traverseNode != NULL ) {
    the_item = traverseNode->item;
    assert( the_item != NULL );
    
    numTraversals = 1;
    // make sure we're still in our list...
    assert( numTraversals <= numNodes );
  }// if
  
  // this isn't the safest (caller can modify the string),
  // but we don't have to worry about extra memory mgmt...
  return the_item;
}// firstItem


// increment the traversal and get the item at the current traversal node
char * nextItem(){
  char *the_item = NULL;
  
  // try to advance the traversal first
  if ( traverseNode != NULL ) {
    traverseNode = traverseNode->next;
    numTraversals++;
  }
  // if we are still in the list, get the item
  if ( traverseNode != NULL ) {
    the_item = traverseNode->item;
    assert( the_item != NULL );
		// make sure we're still in our list...
		assert( numTraversals <= numNodes );
  }
    
  // this isn't the safest (caller can modify the string), 
  // but we don't have to worry about extra memory mgmt...
  return the_item;
}// nextItem
