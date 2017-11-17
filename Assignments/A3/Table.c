/*
 * Table.c
 *
 *  Created on: Nov 6, 2017
 *      Author: hp8460p
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Table.h"


//-------------------------------------------------------------------------------------
// VARIABLES
//-------------------------------------------------------------------------------------

List *headTable = NULL;
// used to track where we are for the list traversal methods
Node *traverseNode = NULL;

// used to track testing values
int numLists = 0;

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

// read from standard input, tokenize and insert words into a linked list
// note that we must ensure that there are no duplicates in our list
void loadFile(List * wordFromFile){
#define LINE_SIZE 256
  char input[LINE_SIZE];
  char *token = NULL;

  while ( fgets( input, LINE_SIZE, stdin ) ) {
    // parse the data into separate elements
    token = strtok( input, " \t\n" );
    while ( token ){
      if ( !search(wordFromFile, token ) )
      {
    	  insert( wordFromFile, token );
      }
      token = strtok( NULL, " \t\n" );
    }// while ( token )
  }// while( fgets...
}// loadFile

// print the contents of the linked list to standard output
void printConcordance(List * wordFromFile){
	FILE * words = fopen("./wordFromFile_ZA.txt","w");
	char *theWord = firstItem(wordFromFile);

	while ( theWord )  {
		printf( "%s\n", theWord );
		fprintf(words,"%s\n", theWord );
		theWord = nextItem(wordFromFile);
	}
	fclose(words);
}// printConcordance

int main( int argc, char *argv[] ){
	printf("\nStarted Main\n");
	List * wordFromFile = NULL;
	wordFromFile = createTable();
	printf("loading file in a list\n");

	loadFile(wordFromFile);
	printConcordance(wordFromFile);
//	clearTable(wordFromFile);

	List * subjects = NULL;
	subjects = createTable();
	insert(subjects, "CLanguage");
	insert(subjects, "Physics");
	insert(subjects, "Signals");
	insert(subjects, "Interfacing");
	insert(subjects, "HCI");
	insert(subjects, "Math1");
	insert(subjects, "Math2");
	insert(subjects, "Math3");
	insert(subjects, "Quantum");
	insert(subjects, "Java");

	List * phones = NULL;
	phones = createTable();
	insert(phones, "iPhone 7");
	insert(phones, "iPhone 1");
	insert(phones, "iPhone 3");
	insert(phones, "iPhone 5");
	insert(phones, "iPhone 3G");
	insert(phones, "iPhone 4s");
	insert(phones, "iPhone 6s");
	insert(phones, "iPhone X");
	insert(phones, "HTC m8");
	insert(phones, "HTC U11");
	insert(phones, "Samsung Galaxy S3");
	insert(phones, "Samsung Galaxy S6 Edge");
	insert(phones, "Samsung Galaxy S8");
	insert(phones, "Samsung Galaxy Note 3");
	insert(phones, "Samsung Galaxy Note 8");
//	clearTable(anotherList);

	List * currList = headTable;

	printf("PRINT TABLE \n");
	printf("list head %s \n",firstItem(headTable));
	Node * currNode = currList->headNode;
	int i = 0;

	while(currList->nextList != NULL)
	{
		printf("list: %d current node -> %s \n",i,currNode->item);
		currNode = currNode->next;

		if(currNode == NULL)
		{
			currList = currList->nextList;
			if(currList == NULL)
				printf("LIST IS EMPTY (UNINITIALIZED)\n");
			else
			{
				printf("list: %d head -> %s \n",i,currList->headNode->item);
				i++;
				currNode = currList->headNode;
			}

		}
	}

	printf("PRINT TABLE - SUCCESSFULL\n");
	clearTable(wordFromFile);
	clearTable(subjects);
	clearTable(phones);
	printf("CLEAR TABLE - SUCCESSFULL\n");

	return EXIT_SUCCESS;
}// main

//-------------------------------------------------------------------------------------
// Linked List Implementation
//-------------------------------------------------------------------------------------

/*
 * This function will make an empty linked list. this does not initialize it.
 * return: a pointer of the newList.
 */
List * createTable()
{
	List * newList = NULL;

	newList = malloc(sizeof( List )); //each list node will have a pointer to list's head and next list
	newList->headNode = NULL; 		  //initialize the head of each lists created to null

	newList->nextList = headTable;
	headTable = newList;
	newList->numNodes = 0;
	newList->numTraversals = 0;
	assert(newList != NULL);
	if( newList )
		numLists++;
	else
		free( newList );

	return newList;
}

Boolean destroyTable()
{
	Boolean destroyed = false;

	List * listTraverser = headTable;
	while(headTable != NULL)
	{
		headTable = listTraverser->nextList;
		clearTable(listTraverser);
		free( listTraverser );
		listTraverser = headTable;
		numLists--;
	}
	if(headTable == NULL)
		destroyed = true;
	return destroyed;
}


Boolean delete(List * currentList,char * wordToDelete)
{
	Node * current = currentList->headNode;
	Node * previous = NULL;
	Boolean deleted = false;
	if (currentList->headNode == NULL)
	{
		assert(currentList->headNode == NULL);
	}
	else if (wordToDelete == NULL)
	{
		assert(wordToDelete != NULL);
	}
	else
	{
		while(current != NULL)
		{
			if(strcmp(current->item,wordToDelete) == 0)
			{
				if(current == currentList->headNode ) //head points to wordToDelete
				{
					currentList->headNode =current->next; //head/current -> wordToDelete -> next (before op) => (after op) head -> next and current -> wordToDelete
					free(current->item);
					free(current);
					deleted = true;
					currentList->numNodes--;
					current = currentList->headNode;
				}
				else //wordToDelete is in middle or end, it is not head
				{
					previous->next = current->next;
					free( current->item );
					free( current );
					deleted = true;
					currentList->numNodes--;
				}
				validateTable(currentList);
				return deleted;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
		assert(deleted);
	}
	return deleted;
}

void validateTable(List * currentList){
  if ( currentList->numNodes == 0 )
    assert( currentList->headNode == NULL );
  else if ( currentList->numNodes == 1 )
    assert( currentList->headNode->next == NULL );
  else // currentList->numNodes > 1
    assert( currentList->headNode != NULL && currentList->headNode->next != NULL );
  // how far should we really go???
}// validateList

// add an element to the beginning of the linked list
Boolean insert(List * currentList, char *new_string ){
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
        newNode->next = currentList->headNode; //point to this list's head
        currentList->headNode = newNode;	   //this list's head points to newNode that was just created.
        currentList->numNodes++;

        rc = true;

        // make sure the list is stable
        validateTable(currentList);
      } else {
        free( newNode );
      }// if ( newNode->item )
    }// if ( newNode )
  }// if( new_string )

  return rc;
}// insert


// empty the list so that we clear all memory and can start a fresh list
void clearTable(List * currentList){
  Node *curr = currentList->headNode ;

  while ( currentList->headNode  != NULL ){
	  currentList->headNode  = currentList->headNode->next;
    free( curr->item );
    free( curr );
    curr = currentList->headNode;

    currentList->numNodes--;
  }// while
  numLists--;
  validateTable(currentList);
}// clearList


// tells us whether or not the given string is in the list
Boolean search(List * currentList, char *target ){
  Boolean found = false;
  char *curr = firstItem(currentList);

  int search_count = 0;     // how far in the list do we go?

  assert( target != NULL );
  if ( target != NULL ) {

    while ( curr != NULL && !found ){
      if ( strcmp( target, curr ) == 0 ){
        found = true;

        // make sure we're still in our list...
        assert( search_count <= currentList->numNodes );
      } else {
        curr = nextItem(currentList);
        search_count++;
      }// else
    }// while
  }// if( target != NULL )

  // if it's not found then we should be at the end of the list
  assert( found || (search_count == currentList->numNodes) );

  return found;
}// search


// starts a list traversal by getting the data at head
char * firstItem(List * currentList){

	char *the_item = NULL;

	traverseNode = currentList->headNode;

	if ( traverseNode != NULL ) {
		the_item = traverseNode->item;
		assert( the_item != NULL );

		currentList->numTraversals = 1;
		// make sure we're still in our list...
		assert( currentList->numTraversals  <= currentList->numNodes );
	}// if

	// this isn't the safest (caller can modify the string),
	// but we don't have to worry about extra memory mgmt...
	return the_item;
}// firstItem


// increment the traversal and get the item at the current traversal node
char * nextItem(List * currentList){
  char *the_item = NULL;

  // try to advance the traversal first
  if ( traverseNode != NULL ) {
    traverseNode = traverseNode->next;
    currentList->numTraversals++;
  }
  // if we are still in the list, get the item
  if ( traverseNode != NULL ) {
    the_item = traverseNode->item;
    assert( the_item != NULL );
		// make sure we're still in our list...
		assert( currentList->numTraversals  <= currentList->numNodes );
  }

  // this isn't the safest (caller can modify the string),
  // but we don't have to worry about extra memory mgmt...
  return the_item;
}// nextItem

