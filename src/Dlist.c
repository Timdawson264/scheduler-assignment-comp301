/*
 * Dlist.c
 *
 *  Created on: 23/08/2013
 *      Author: tim
 */
#include "Dlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Dlist_t* Dlist_Init(){
	Dlist_t* Dlist = malloc(sizeof(Dlist_t)); //return Dlist
	//TODO Check Dlist == NUll

	Dlist->head=NULL;
	Dlist->tail=NULL;
	Dlist->size=0;
	return Dlist;
}

DlistN_t* Dlist_FindByName(Dlist_t* Dlist, char* TaskName){
	DlistN_t* n = Dlist->head;
	while(n!=NULL){
		if(strncmp(TaskName,n->TaskName,sizeof(n->TaskName))==0){
			return n;
		}
		n=n->next;
	}
	//Nothing Found
	return NULL;
}

void Dlist_Insert(Dlist_t* Dlist, DlistN_t* n){
	Dlist->size++;

	//First Element
	if(Dlist->head==NULL && Dlist->tail==NULL){
		Dlist->head=n;
		Dlist->tail=n;
		//Set Nodes Pointers
		n->next=NULL;
		n->prev=NULL;
		return;
	}

	//insert at head
	if(n->Time < Dlist->head->Time){
		Dlist->head->prev=n;
		n->next=Dlist->head;
		Dlist->head=n;
		n->prev=NULL;

		return;
	}

	DlistN_t* testNode=Dlist->tail;//Start at tail
	while(testNode!=NULL){

		if(n->Time > testNode->Time){
			//if insert at very end
			if(testNode==Dlist->tail){
				Dlist->tail=n;
			}

			//insert after testNode
			if(testNode->next!=NULL)//not tail which has not next
				testNode->next->prev=n;
			n->next=testNode->next; //null if tail node
			testNode->next=n;
			n->prev=testNode;

			return; //done
		}
		//next node
		testNode=testNode->prev;
	}
	//Should Never Get here
	fputs("ERROR Dlist Insert Failed",stderr);
	Dlist->size--; //correct count

}

DlistN_t* Dlist_Remove(Dlist_t* Dlist, DlistN_t* n){
	if(Dlist->head==n)
		Dlist->head=n->next;

	if(Dlist->tail==n)
		Dlist->tail=n->prev;

	if(n->next!=NULL)
		n->next->prev=n->prev;

	if(n->prev!=NULL)
		n->prev->next=n->next;

	Dlist->size--;
	return n;
}

void Dlist_Clear(Dlist_t* Dlist){
	DlistN_t* n = Dlist->head;
	while(n!=NULL){
		DlistN_t* n_next=n->next;
		free(n);
		n=n_next;
	}
	Dlist->head=NULL;
	Dlist->tail=NULL;
	Dlist->size=0;
}

void Dlist_list(Dlist_t* Dlist){
	DlistN_t* n = Dlist->head;
	printf("Dlist Dump, Size=%u:\n",Dlist->size);
	while(n!=NULL){
		printf("Node: %s, %u\n",n->TaskName,n->Time);
		n=n->next;
	}
}


