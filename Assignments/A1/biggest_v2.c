//-----------------------------------------
// NAME: ZAFAR ALAM
// STUDENT NUMBER: 7738894
// COURSE: COMP 2160, SECTION: A01
// INSTRUCTOR: Stela Seo
// ASSIGNMENT: assignment 1, QUESTION: question 2
//
// REMARKS: Converted from Java. Find the biggest word in textfile and then print it on screen, line by line.
//
//-----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 100

int main(void)
{
	char *inputLine[LINE_MAX] = {NULL}; 		//empty array, pointing to first element
//	printf("inputLine Ptr: %p | %s\n",inputLine,*inputLine);

	char currWord[LINE_MAX] = {""}; //initialized with all empty elements
	char bigWord[LINE_MAX] = {"NULL"};		//char pointer array.
//	printf("BIGWORD: %p %s\n",bigWord,*(bigWord)); //pointer and data at pointer's address

	int bigWeight = 0;
	int weight = 0;
	int index;
	int line = 0;

	int counter;		//counter for currWord array
	int j;				//for loop for inputLine char array
/*
	*inputLine = "NEW";
	printf("YOU: %p %s",inputLine, *inputLine);
	*inputLine = *(inputLine+1);

	*(inputLine) = *(inputLine+1);
	*inputLine = "SECOND";
	printf("YOU: %p %s",inputLine, *inputLine);
*/

	//read line from stdin.
//	fgets(*inputLine , LINE_MAX, stdin);

	while(strcmp(fgets(*inputLine , LINE_MAX, stdin),"NULL") != 0) //fgets return NULL on failure and str on success
	{
		index = 0;
		line++;
		memset(bigWord, 0, strlen(bigWord));
		printf("%s",bigWord);
		bigWeight = 0;
		printf("INPUTLINE: %s,",*inputLine);
		while(index<LINE_MAX)
		{
			weight = 0;
			memset(currWord, 0, strlen(currWord));

			counter = 0;

			//used for inputLine array. Go through each character of inputLine and check for comparisons
			for(j = 0; j < LINE_MAX; j++)
			{
				while(index<LINE_MAX && (*inputLine[j] != ' ' && *inputLine[j] != '\t'))
				{
					currWord[counter] = *inputLine[j];
					weight += *inputLine[j];
					index++;
				}//while end
			}//for end
			if(weight > bigWeight)
			{
				strcpy(bigWord,currWord);
				bigWeight = weight;
			}
			index++;
		}//while end
		if(strcmp(bigWord,"NULL"))
		{
			printf("line %d's word: %s", line, bigWord);
		}
		fgets(*inputLine , LINE_MAX, stdin);
	}//while end
	printf("Program Completed Successfully");
	return 0;
}
