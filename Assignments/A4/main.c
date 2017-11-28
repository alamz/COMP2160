/*
 * main.c
 *
 *  Created on: Nov 28, 2017
 *      Author: hp8460p
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "ObjectManager.h"

int main(void)
{
	initPool();
	Ref id = insertObject(32);
	printf("%lu \n",id);
}
