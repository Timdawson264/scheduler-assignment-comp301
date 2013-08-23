/*
 * scheduler.h
 *
 *  Created on: 23/08/2013
 *      Author: tim
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Dlist.h"



void Scheduler_Init();

void Scheduler_Add(uint32_t Time, char* TaskName);
void Scheduler_AddRep(uint32_t Time, uint32_t RepTime, char* TaskName);
void Scheduler_Time(uint32_t Time);
void Scheduler_Delete(char* Name);
void Scheduler_List();
void Scheduler_Clear();

#endif /* SCHEDULER_H_ */
