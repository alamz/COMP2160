/*
 * Table.h
 *
 *  Created on: Nov 6, 2017
 *      Author: hp8460p
 */

#ifndef TABLE_H_
#define TABLE_H_

//-------------------------------------------------------------------------------------
// CONSTANTS and TYPES
//-------------------------------------------------------------------------------------

typedef enum BOOL { false, true } Boolean;

typedef struct NODE Node;
struct NODE{
  char *item;
  Node *next;
};

typedef struct LLIST List;
struct LLIST{
  Node *headNode;
  List *nextList;
  int numNodes;
  int numTraversals;
};

//-------------------------------------------------------------------------------------
// PROTOTYPES
//-------------------------------------------------------------------------------------

// add an element to the beginning of the linked list
Boolean insert(List * currentList, char *new_string );
// empty the list so that we clear all memory and can start a fresh list
void clearTable(List * currentList);
// tells us whether or not the given string is in the list
Boolean search(List * currentList, char *target );
// starts a list traversal by getting the data at top
char * firstItem(List * currentList);
// increment the traversal and get the data at the current traversal node
char * nextItem(List * currentList);
Boolean delete(List * currentList, char * wordToDelete);
void validateTable(List * currentList);
List * createTable();
Boolean destroyTable();

#endif /* TABLE_H_ */
