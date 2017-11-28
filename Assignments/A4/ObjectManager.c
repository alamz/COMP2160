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
	currBuffer = *buffer1;
	buffer1 = malloc(MEMORY_SIZE);
	printf("RUNNING INITPOOL() - SUCCESSFULL\n");
	//assert here
	buffer2 = malloc(MEMORY_SIZE);
	//assert here
	printf("RUNNING INITPOOL() - SUCCESSFULL\n");
}

Ref insertObject(ulong size)
{
	nextRef++; //this object has at least one reference to it.
	memObject * curr = memRegionStart;
	memObject * newMemBlock = malloc(size);
	newMemBlock->ID = nextRef;
	newMemBlock->size = size;
	newMemBlock->refCount = 1;
	newMemBlock->next = NULL;
	newMemBlock->offset = freePtr;

	if(curr == NULL)
		memRegionStart = newMemBlock;
	else
	{
		while(curr != NULL)
		{
			curr = curr->next;
		}
		curr = newMemBlock;
	}
	freePtr += size;

	return nextRef;
}

int main(void)
{
	initPool();
	Ref id = insertObject(32);
	printf("%lu \n",id);
}

