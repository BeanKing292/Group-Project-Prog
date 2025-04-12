#include <string.h>
#include "Task.h"
#include "menu.h"
#include "input.h"

Task* createTask(char* title, Date doneByDate, char* description) {
	Task* newTask = malloc(sizeof(Task));
	if (newTask == NULL) {
		fprintf(stderr, "error");
		exit(EXIT_FAILURE);
	}
	strncpy(newTask->title, title, MAX_TITLE_SIZE);
	strncpy(newTask->description, description, MAX_DESC_SIZE);
	newTask->doneByDate = doneByDate;
	newTask->isTask = 1;
	return newTask;
}

Task* getTask(Task** todoList, int orderPosition) {
	return todoList[orderPosition - 1];
}

void deleteTask(Task** todoList, int orderPosition, ManagerInfo* position) {
	// Deletes the task
	free(todoList[orderPosition - 1]);
	// Shifts everything after delete task to the left
	position->taskAmount--;
	for (int i = orderPosition - 1; i < MAX_TASKS; i++){
			todoList[i - 1] = todoList[i];
	}
}

void updateTitle(Task* todoList[], char* newTitle, int orderPosition) {
	strcpy_s(todoList[orderPosition]->title, (sizeof(char) * MAX_TITLE_SIZE), newTitle);
}

void updateDoneByDate(Task* todoList[], Date doneByDate, int orderPosition) {
	todoList[orderPosition]->doneByDate = doneByDate;
}

void updateDescription(Task* todoList[], char* newDescription, int orderPosition) {
	strcpy_s(todoList[orderPosition]->description, (sizeof(char) * MAX_DESC_SIZE), newDescription, MAX_DESC_SIZE);
}

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year) {
	Date newDate;
	newDate.tm_min = tm_min;
	newDate.tm_hour = tm_hour;
	newDate.tm_mday = tm_mday;
	newDate.tm_mon = tm_mon;
	newDate.tm_year - tm_year;
	return newDate;
}

void printDate(Task* task) {
	printf("Time:\t\t%d:%d\n", task->doneByDate.tm_hour, task->doneByDate.tm_min);
	printf("Date:\t\t%d/%d/%d", task->doneByDate.tm_mon, task->doneByDate.tm_mday, task->doneByDate.tm_year);
}

void printTask(Task* TodoList[], int lowerRange, int upperRange) {
	Task* task;
	for (int i = lowerRange; i <= upperRange; i++) {
		task = getTask(TodoList, i);

		printf("\nTitle:\t\t%s\n", task->title);
		printf("Description:\t%s\n", task->description);
		printDate(task);
	}
}

void taskSearch(Task* TodoList[], ManagerInfo* position, char* searchTerm) {
	// I searched how to check if ones string is in another string and this came up.
	Task* task;
	for (int i = 0; i <= position->taskAmount; i++) {
		task = getTask(TodoList, i);
		if (strstr(task->title, searchTerm) != NULL){
			printf("\nTitle:\t\t%s\n", task->title);
			printf("Description:\t%s\n", task->description);
			printDate(task);
			}
	}
}