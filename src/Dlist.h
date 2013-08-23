/*
 * Dlist.h
 *
 *  Created on: 23/08/2013
 *      Author: tim
 */

#ifndef DLIST_H_
#define DLIST_H_
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct __Dlist Dlist_t;
typedef struct Dlist_Node DlistN_t;

struct __Dlist {
	DlistN_t* head;
	DlistN_t* tail;
	uint32_t size;
};

struct Dlist_Node {
	DlistN_t* prev;
	DlistN_t* next;

	char TaskName[256];
	uint32_t Time;

	bool repeating;
	uint32_t repeatTime;
};

Dlist_t* Dlist_Init();
void Dlist_Clear(Dlist_t* Dlist);
void Dlist_Insert(Dlist_t* Dlist, DlistN_t* n);
void Dlist_list(Dlist_t* Dlist);
DlistN_t* Dlist_FindByName(Dlist_t* Dlist, char* TaskName);
DlistN_t* Dlist_Remove(Dlist_t* Dlist, DlistN_t* n);

#endif /* DLIST_H_ */
