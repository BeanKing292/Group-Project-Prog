#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "menu.h"
#include "input.h"

// a new temp main file so i can get everything organized - Alex

// Made some changes to the file reader - Alex
// Read from File
Task** openTaskFile(char* fileName, ManagerInfo* position){
	// Allocate memory for pointer array
	Task** taskList = malloc(sizeof(Task*) * MAX_TASKS);
	// Exit if malloc failed
	if (taskList == NULL) {
		printf("Failed to allocate memory. Exiting...");
		exit(1);
	}
	// Open file
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("No file found.");
		return taskList;
	}
	for (int i = 0; i < MAX_TASKS; i++) {
		taskList[i] = malloc( sizeof(Task));
		if (taskList[i] == NULL) {
			fprintf(stderr, "error");
			exit(EXIT_FAILURE);
		}
		fread(taskList[i], sizeof(Task), 1, fp);
		if (taskList[i]->isTask == 1) {
			position->taskAmount++;
		}
	}
	fclose(fp);
	return taskList;
}

// Save to File
void saveTaskFile(char* fileName, Task** taskList) {
	// Write to file
	FILE* fp = fopen(fileName, "wb");

	for (int i = 0; i < MAX_TASKS; i++) {
		fwrite(taskList[i], sizeof(Task), 1, fp);
	}
	fclose(fp);
		fclose(fp);
}


int main(void) {
	ManagerInfo* position = calloc(0, sizeof(ManagerInfo));
	if (position == NULL) {
		fprintf(stderr, "error");
		exit(EXIT_FAILURE);
	}
	position->taskAmount = 0;
	Task** taskList = openTaskFile("TaskList.bin", position);
	while (1) {
		mainUI(taskList, position);
		saveTaskFile("TaskList.bin", taskList);
	}

}