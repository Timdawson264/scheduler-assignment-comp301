/*
 * scheduler.c
 *
 *  Created on: 23/08/2013
 *      Author: tim
 */


#include "scheduler.h"

Dlist_t* list=NULL;
uint32_t TIME=0;

void Scheduler_Init(){
	list = Dlist_Init();
}

static void Scheduler_AddBasic(char* TaskName, uint32_t Time, bool Repeating, uint32_t RepTime){
	DlistN_t* task = malloc(sizeof(DlistN_t));

	strncpy(task->TaskName, TaskName, sizeof(task->TaskName));
	task->Time=Time;
	task->repeating=Repeating;
	task->repeatTime=RepTime;

	Dlist_Insert(list, task);
}

void Scheduler_Add(char* TaskName, uint32_t Time){
	Scheduler_AddBasic(TaskName,Time,false,0);
}

void Scheduler_AddRep(char* TaskName, uint32_t Time,uint32_t RepTime){
	Scheduler_AddBasic(TaskName,Time,true,Time);
}

void Scheduler_Time(uint32_t Time){
	TIME=Time;

	while(list->head->Time < TIME){

		DlistN_t* n = Dlist_Remove(list,list->head); //pop head
		if(n->repeating==true){
			n->Time+=n->repeatTime;
			Dlist_Insert(list,n);//reinsert
		}else{
			free(n);
		}
	}
}

void Scheduler_Delete(char* Name){
	free(Dlist_Remove(list,
			Dlist_FindByName(list,Name)));
}

void Scheduler_List(){

}

void Scheduler_Clear(){
	Dlist_Clear(list);
}
