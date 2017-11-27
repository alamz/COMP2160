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
	int ID; 			//needed to reference the object
	int size;			//size of it in bytes
	int offset;			//starting location of this object, relative to the previous memblocks
	int refCount;		//how many references to this object
	memObject * next;	//similar to node structure, points to next block in memory

};

static memObject memRegionStart = NULL;
static memObject memRegionEnd = NULL;
static int numObjects = 0;

Ref insertObject( ulong size )
{
	Ref result;

	return result;
}

