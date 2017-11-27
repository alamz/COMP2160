//-----------------------------------------
// NAME: ZAFAR ALAM
// STUDENT NUMBER: 7738894
// COURSE: COMP 2160, SECTION: A01
// INSTRUCTOR: Stela Seo
// ASSIGNMENT: assignment 3, QUESTION: question 1
//
// REMARKS: Make a Table using a Linked List to store multiple linked lists.
//
//-----------------------------------------

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
Node *traverseNode= NULL;

// used to track testing values
int numLists = 0;

//-------------------------------------------------------------------------------------
// FUNCTIONS
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
// Linked List Implementation
//-------------------------------------------------------------------------------------

/*
 * This function will make an empty linked list. this does not initialize it.
 * return: a pointer to the newList.
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

Boolean destroyTable(List * toDestroy)
{
	Boolean isDestroyed = false;
	List * curList = headTable;

	//if an empty is to be destroyed
	if(toDestroy == NULL)
	{
		assert(toDestroy != NULL);
		return isDestroyed;
	}

	//empties the list (frees memory for nodes in this list)
	clearTable(toDestroy);
	//list still exists, but no nodes

	if(headTable == toDestroy)		//if Table to destroy is headTable
		headTable = curList->nextList;
	free ( toDestroy );
	isDestroyed = true;

	numLists--; //decrease number of lists in the table

	return isDestroyed;

}

Boolean destroyEveryTable()
{
	Boolean destroyed = false;

	List * listTraverser = headTable;
	while(headTable != NULL)	//headTable will move its pointer to nextList
	{
		headTable = listTraverser->nextList;	//head of Table will skip this list
		clearTable(listTraverser);	//frees memory for all nodes and their items
		free( listTraverser );	//now free this list object
		listTraverser = headTable;	//move to next list.
		numLists--;
	}
	if(headTable == NULL)
		destroyed = true;
	else
		assert(headTable == NULL);
	return destroyed;
}

Boolean delete(List * currentList,char * wordToDelete)
{
	Boolean deleted = false;

	if(currentList == NULL) {
		assert(currentList != NULL);
		printf("This list is not created\n");
		return deleted;
	}
	char * listItem = firstItem(currentList);
	Node * current = currentList->headNode;
	Node * previous = NULL;


	if (wordToDelete == NULL)
	{
		assert(wordToDelete != NULL);
		return deleted;
	}
	else
	{

		while(currentList->numTraversals <= currentList->numNodes)
		{
			if(strcmp(listItem,wordToDelete) == 0)
			{
				if(currentList->numTraversals == 1 ) //head points to wordToDelete NODE
				{
					currentList->headNode = current->next;
					free(listItem);
					free(current);
					deleted = true;
					currentList->numNodes--;
					//current = currentList->headNode;
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
				listItem = nextItem(currentList);
			}
		}//while
	}//if-else
	printf("This item is not in this list\n");
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

  assert( currentList != NULL );
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
	if(currentList == NULL)
	{
		assert(currentList != NULL);
		printf("This list is not created");
		return the_item;
	}
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

