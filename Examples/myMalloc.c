#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 150

int main(void)
{
	/*	Making a STRUCT */
	struct books{
		char title[MAX_SIZE];
		char person[MAX_SIZE];
		int book_ID;
	};
	/*	Declare	a STRUCT*/
	struct books book1;	
	strcpy(book1.title, "Struct v1 Programming Language");
	printf("Book: 	%s\n",book1.title);

	typedef struct books bookStr;
	
	/*	Making a STRUCT with typedef */
	typedef struct friend{
		char title[MAX_SIZE];
		char author[MAX_SIZE];
		int id;
	}friends;
	
	bookStr book_1;
	strcpy(book_1.title, "C Programming Language");
	strcpy(book_1.person, "Dennis Ritchie");
	book_1.book_ID = 1;
	
	printf("Book: 	%s\n",book_1.title);
	printf("Author: %s\n",book_1.person);
	printf("ID: 	%d\n",book_1.book_ID);
}