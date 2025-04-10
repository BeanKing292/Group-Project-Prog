#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"

// a new temp main file so i can get everything organized - Alex


// made some changes to the file reader to simplify it - Alex
//File reader 
FILE* openFile(){
	FILE* TaskManager;
	TaskManager = fopen("TaskList.txt", "r");
	if (TaskManager != NULL) {
		for (int i = 0; i < 10; i++) {
			fscanf(TaskManager, "%s %s %d %d %d\n", todoList[i].title, todoList[i].description, &todoList[i].doneByDate.tm_year, &todoList[i].doneByDate.tm_mon, &todoList[i].doneByDate.tm_mday);
		}
	}
	// If no existing data can be found, create a new one
	else {

		Task newestTask = createTask(title, doneByDate, description);
		for (int i = 0; i < 10; i++) {
			todoList[i] = newestTask;
		}
	}
}

int main(void) {

}