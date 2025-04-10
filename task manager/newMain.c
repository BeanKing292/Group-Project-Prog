#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "menu.h"
#include "input.h"

// a new temp main file so i can get everything organized - Alex

// made some changes to the file reader to simplify it - Alex
//File reader 
Task** openTaskFile(char* fileName){
	// Allocate memory for pointer array
	Task** taskList = malloc(sizeof(Task*) * MAX_TASKS);
	// Exit if malloc failed
	if (taskList == NULL) {
		printf("Failed to allocate memory. Exiting...");
		exit(1);
	}
	// Open file
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("No file found.");
		return taskList;
	}
	//fread(taskList, sizeof(Task), MAX_TASKS, fp);
	fclose(fp);
	return taskList;
}

int main(void) {
	int position = 0;
	Task** taskList = openTaskFile("TaskList.txt");
	while (1) {
		position = mainUI(taskList, position);
		printf("%d", position);
	}

}