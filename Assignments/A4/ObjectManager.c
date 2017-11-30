/*
 * ObjectManager.c
 *
 *  Created on: Nov 24, 2017
 *      Author: hp8460p
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "ObjectManager.h"

//This will used to assign next references, starts 1 (default), 0 is if its empty.
static Ref nextRef = 1;

//A MEMOBJECT is a memory block; holds all necessary info about each memory regions created in the objectmanager
typedef struct MEMOBJECT memObject;

struct MEMOBJECT
{
	Ref ID; 			//needed to reference the object
	int size;			//size of it in bytes
	int offset;			//starting location of this object, relative to the previous memblocks
	int refCount;		//how many references to this object
	memObject * next;	//similar to node structure, points to next block in memory

};

//like a linked list, head will be null to initialize. The end is there as well, so we do not overwrite, and to run garbage collection.
static memObject * memRegionStart;
static memObject * memRegionEnd;
static int numObjects;

//allocating large memory chunks, each object will allocate blocks from here.
static unsigned char * buffer1;	//buffer 1 is the one that gives blocks
static unsigned char * buffer2;	//buffer 2 is used when defragmenting - swapping.

//current buffer we are working with
static unsigned char currBuffer;

//pointer to empty or free memory block/location.
static int freePtr = 0;

void initPool()
{
	printf("RUNNING INITPOOL() \n");
	memRegionStart = NULL;
	memRegionEnd = NULL;
	numObjects = 0;

	printf("\tRUNNING INITPOOL: allocate buffer1 next\n");
	buffer1 = malloc(MEMORY_SIZE);
	printf("\tALLOCATING BUFFER  - SUCCESSFULL\n");

//	assert here
	if(buffer1 == NULL)
	{
		assert(buffer1 != NULL);
	}

	buffer2 = malloc(MEMORY_SIZE);
	//assert here
	currBuffer = *buffer1;
	printf("RUNNING INITPOOL() - SUCCESSFULL\n");
}

Ref insertObject(ulong size)
{

	memObject * curr = memRegionStart;
	memObject * newMemBlock = malloc(size);
	newMemBlock->ID = nextRef;
	nextRef++; //NEW OR THE NEXT OBJECT SHOULD HAVE THIS ID
	newMemBlock->size = size;
	newMemBlock->refCount = 1;
	newMemBlock->next = NULL;
	newMemBlock->offset = freePtr;

	if(curr == NULL)
		memRegionStart = newMemBlock;
	else
	{
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newMemBlock;
		curr = curr->next;
		curr = newMemBlock;
	}
	freePtr += size;

	if(newMemBlock == NULL)
	{
		return (nextRef=0); //0 indicates NULL, while >0 indicates this object's id
	}
	printf("insertObject() new block pointer: %p\n", newMemBlock);
	printf("insertObject() memRegionStart pointer: %p\n", memRegionStart);
	return newMemBlock->ID;
}

void *retrieveObject( Ref ref )
{
	memObject * curr = memRegionStart;
	while(curr != NULL)
	{
		if(curr->ID == ref)
		{
			return curr;
		}
		curr = curr->next;
	}
	printf("FAILED\n");
	return NULL;
}

void addReference(Ref ref)
{
	memObject * curr = retrieveObject(ref);
	curr->refCount += 1;
	printf("ADDING REFERENCE TO ID %lu\n",ref);


	printf("\tID: %lu has %d references\n",ref,(curr->refCount));
	printf("ADDING REFERENCE TO ID %lu - SUCCESSFULL\n",ref);
}

void dropReference( Ref ref )
{
	memObject * curr = retrieveObject(ref);
	curr->refCount--;
	printf("DROPPING REFERENCE IN ID %lu\n",ref);


	printf("\tID: %lu has %d references\n",ref,(curr->refCount));
	printf("DROPPING REFERENCE IN ID %lu SUCCESSFULL\n",ref);
}

int main(void)
{
	printf("\nRUNNING MAIN\n");
	initPool();
	Ref id = insertObject(32); //returns nextRef ID.
	printf("\tinserted object id = %lu \n",id);

	printf("\tretrieved object with id 1 %p\n",retrieveObject(id));

	addReference(1);

	dropReference(1);

	Ref id2 = insertObject(32);
	printf("\tinserted object id = %lu \n",id2);

	printf("\tretrieved object with id %lu %p\n",id2,retrieveObject(id2));

	addReference(id2);
	addReference(id2);
	addReference(id2);
	addReference(id2);

	dropReference(id2);



}

