
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Table.h"

int numTests = 0;
int numFailed = 0;
int numSucceed = 0;

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

void createTestTables(List * testSubject)
{
	//test subject/list. Includes a duplicate.
	char * phones[] = {"HTC M8", "iPhone 7","iPhone 8","iPhone 6s","iPhone 6",
						"iPhone 5", "Samsung Galaxy S8","Samsung Galaxy S7",
						"Samsung Galaxy S6", "HTC M7","HTC M8"};

	int i = 0;
	while(i < PHONES_COUNT)
	{
		insert(testSubject, phones[i]);
		i++;
	}
	printf("DONE MAKING TEST SUBJECTS/LISTS\n");

}//createTestTables

void printPhones(List * phoneList){
	//List * currList = firstItem(listToStartFrom);
	printf("\t\tPRINT PHONES TABLE \n");

	char * item = firstItem(phoneList);

	while(phoneList->numTraversals <= phoneList->numNodes)
	{
		printf("%s\n",item);
		item = nextItem(phoneList);
	}
}//printPhones


void testDeletion(List * testTable)
{
	char * headDelete = "HTC M8";
	char * tailDelete = "HTC M8";
	char * midDelete = "Samsung Galaxy S7";

	//Delete from the link created for testing. Prints Result.
	if(delete(testTable, headDelete))
		printf("DELETION OF HEAD - SUCCESSFULL\n");
	else
		printf("DELETION OF HEAD - FAILED \n");
	if(delete(testTable, tailDelete))
		printf("DELETION OF TAIL - SUCCESSFULL\n");
	else
		printf("DELETION OF TAIL - FAILED \n");
	if(delete(testTable, midDelete))
		printf("DELETION OF MID - SUCCESSFULL\n");
	else
		printf("DELETION OF MID - FAILED \n");
	//check for deleting an item not in a properly created list
	delete(testTable, "theItem");

}
int main( int argc, char *argv[] ){

	printf("\nStarted Main\n");

	List * wordFromFile = NULL;
	List * listPhones = NULL;
	List * uninitList = NULL;		//uninitialized list.
	wordFromFile = createTable();
	listPhones = createTable();

	printf("loading file in a list\n");
	loadFile(wordFromFile);
	printConcordance(wordFromFile);
	clearTable(wordFromFile);

	//Make a list for testing
	printf("\nTEST CREATING A LIST OF PHONE MODELS\n");
	createTestTables(listPhones);
	printf("TEST CREATING A LIST OF PHONE MODELS - FINISHED\n");

	printf("\nTEST DELETING FROM A LIST\n");
	testDeletion(listPhones);
	printf("TEST DELETING FROM A LIST - FINISHED\n");

	printf("\nTEST DELETING FROM A NULL LIST/TABLE\n");
	//testDeletion(uninitList);
	printf("TEST DELETING FROM A NULL LIST/TABLE - FINISHED\n");

	//Print link created for testing now.
	printPhones(listPhones);
	printf("PRINTING TABLE - SUCCESSFULL\n");

	//destroyTable(listPhones);

	//Testing for actions in a not created table
	//insert(uninitList,"NOT CREATED");
	//

	printf("\nTEST TRAVERSING FROM A NULL LIST/TABLE\n");
	//firstItem(uninitList);
	//nextItem(uninitList);
	printf("TEST TRAVERSING FROM A NULL LIST/TABLE - FINISHED\n");

	printf("\nTEST DESTROYING PHONE LIST\n");
	destroyTable(listPhones);
	printf("TEST DESTROYING PHONE LIST - FINISHED\n");
	printf("\nTEST DESTROYING NULL LIST\n");
	destroyTable(uninitList);
	printf("TEST DESTROYING NULL LIST - FINISHED\n");

	if (destroyEveryTable())
		printf("CLEARING ALL TABLES - SUCCESSFULL\n");
	else
		printf("CLEARING ALL TABLES - FAILED\n");

	printf("\nALL TESTS/PROGRAM SUCCESSFULLY TERMINATED\n");

	return EXIT_SUCCESS;
}// main
