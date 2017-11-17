//-----------------------------------------
// NAME: ZAFAR ALAM
// STUDENT NUMBER: 7738894
// COURSE: COMP 2160, SECTION: A01
// INSTRUCTOR: Stela Seo
// ASSIGNMENT: assignment 2, QUESTION: question 1
//
// REMARKS: Implemented a Linked List to store words without any duplicates.
//
//-----------------------------------------

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

//declare a head pointer, which will point to first node of the list
Node *head = NULL;	
Node *CURR = NULL;


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

//insert a new word in to the linked list
//the new word is added to the beginning of list
Boolean insert( char *new_string )
{
	assert(new_string != NULL);
	Node *newNode;
	newNode = malloc(sizeof(Node));
	assert(newNode != NULL); //check if created properly
	
	//assign value and new node's next will point to head (previous head node)
	(*newNode).item = strdup(new_string);	
	newNode->next = head;
	
	head = newNode;	//head now points to newNode
	assert(head != NULL);
	return true;
}

void clearList()
{
	Node * temp = NULL; 	//temporary ptr
	Node * current = head;	//current is the traveller in the list
	if(head != NULL){
		// traverse list
		while(current != NULL)
		{
			temp = current;

			current = current->next;
			free(temp);
		}
	}
	head = NULL;

}

Boolean search(char *target)
{
	Boolean found = false;
	assert(target != NULL);
	if(head != NULL)
	{
		Node * current = head;

		//using a linear search since the list is not sorted
		while((current != NULL && !found) )
		{
			// printf("current->item = %s\n",current->item);
			if(strcmp(current->item,target) != 0)
			{
				current=current->next;	//current will get data from next node
			}
			else
			{
			//	printf("successful END SEARCH\n");

				found = true;
				return found;
			}
		}
	}
	return found;
}


char * firstItem()
{
	//make sure that there is a list to return first item
	if(head != NULL)
	{
		CURR = head;	//initialize CURR
		return CURR->item;
	}
	return NULL;
}

char *nextItem()
{	
	char * itemToReturn = NULL;
	
	if(head == NULL)	//checking for empty list; CURR will also be NULL
		return NULL;	
	else
	{
		CURR = CURR->next; //increment CURR
		
		if(CURR != NULL)	//verify if CURR points to node
		{
			//return current node item
			itemToReturn = CURR->item;
		}
		else //CURR not pointing to any nodes
		{
			itemToReturn = NULL;
			CURR = head;	//go to beginning
		}
	}
	return itemToReturn;
}

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
	FILE *f = fopen("output_ZA.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

  char *theWord = firstItem();
  
  while ( theWord )
  {
    printf( "%s\n", theWord );
	//const char *text = "Write this to the file";
	fprintf(f,"%s\n", theWord);
    theWord = nextItem();
  }
}

int main( int argc, char *argv[] )
{
	printf("printConcordance - STARTED\n");

	loadFile();
	printf("\nLOAD FILE - SUCCESSFULL\n");
	printConcordance();
	clearList();
	printf("\nPROGRAM END - SUCCESSFULL\n");
  return EXIT_SUCCESS;
}
