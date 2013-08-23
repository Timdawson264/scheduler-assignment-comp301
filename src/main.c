/*
 * main.c
 *
 *  Created on: 23/08/2013
 *      Author: tim
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scheduler.h"

#define LineLen_d 1024

int  main (int argc, char **argv){

	Scheduler_Init();

	FILE* cmd_file = fopen(argv[1],"r");
	char line[LineLen_d];

	while(fgets(line,LineLen_d,cmd_file)!=NULL){
		line[strlen(line)-1]='\0'; //destroy \n

		char* cmd = strtok(line," ");
		//printf("CMD: %s\n",cmd); //DEBUG

		if(strncmp("ADD",cmd,LineLen_d)==0){
			uint32_t time = strtol(strtok(NULL," "),NULL,10);

			Scheduler_Add(time,strtok(NULL," "));
			continue;
		}
		if(strncmp("ADDREP",cmd,LineLen_d)==0){
			uint32_t time = strtol(strtok(NULL," "),NULL,10);
			uint32_t reptime = strtol(strtok(NULL," "),NULL,10);

			Scheduler_AddRep(time, reptime,strtok(NULL," "));
			continue;
		}
		if(strncmp("TIME",cmd,LineLen_d)==0){
			uint32_t time = strtol(strtok(NULL," "),NULL,10);
			Scheduler_Time(time);
			continue;
		}
		if(strncmp("DEL",cmd,LineLen_d)==0){
			Scheduler_Delete(strtok(NULL," "));
			continue;
		}
		if(strncmp("LIST",cmd,LineLen_d)==0){
			Scheduler_List();
			continue;
		}
		if(strncmp("CLEAR",cmd,LineLen_d)==0){
			Scheduler_Clear();
			continue;
		}
	}

	fclose(cmd_file);

	return 0;
}

