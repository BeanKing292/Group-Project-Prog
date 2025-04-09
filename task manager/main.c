#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"

int main(void) {
	Task todoList[10] = { 0 };
	Date doneByDate = { 0, 0, 0, 0, 0, 0, 0 };
	int day = 0;
	char* title = "check";
	char* description = "house";

	//File reader 
	FILE* TaskManager;
	TaskManager = fopen("TaskList.txt", "r");
	if (TaskManager != NULL) {
		for (int i = 0; i < 10; i++) {
			fscanf(TaskManager, "%s %s %d %d %d\n", todoList[i].title, todoList[i].description, &todoList[i].doneByDate.tm_year, &todoList[i].doneByDate.tm_mon, &todoList[i].doneByDate.tm_mday);
		}
	}
	else {

		Task newestTask = createTask(title, doneByDate, description);
		for (int i = 0; i < 10; i++) {
			todoList[i] = newestTask;
		}
	}
	displayRange(&todoList);
	
	displayAll(&todoList);
	
	displayOne(&todoList);
	//File Writer
	TaskManager = fopen("TaskList.txt", "w");
	for(int i = 0; i < 10; i++){
		fprintf(TaskManager, "%s %s %d %d %d\n", todoList[i].title, todoList[i].description, todoList[i].doneByDate.tm_year, todoList[i].doneByDate.tm_mon, todoList[i].doneByDate.tm_mday);
	}
	return 0;
}