#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"

int main(void) {
	Task todoList[10] = { 0 };
	Date doneByDate = { 0, 0, 0, 0, 0};
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

	int choice;

	while (1) {
		printf("\nMenu:\n1. New Task\n2. Delete Task\n3. Update Task\n4. Display Task\n5. Display Range\n6. Display all Tasks\n7. Search for Tasks");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);
		if (choice == 1) {
			char title= "nothing";
			char description = "nothing";
			int tm_min = 0;
			int tm_hour = 0;
			int tm_mday = 0;
			int tm_mon = 0;
			int tm_year = 0;
			int tm_wday = 0;

			
			printf("Please input task title");
			scanf("%s", title);
			printf("Please input task description");
			scanf("%s", description);
			printf("Please input task done by hour");
			scanf("%d", tm_hour);
			printf("Please input task done by minute");
			scanf("%d", tm_min);
			printf("Please input task done by number date of month");
			scanf("%d", tm_mday);
			printf("Please input task done by number of month");
			scanf("%d", tm_mon);
			printf("Please input task done by number of year");
			scanf("%d", tm_year);

			Date doneByDate = setDate(tm_min, tm_hour, tm_mday, tm_mon, tm_year);
			int position = 0;
			if (todoList[position].title != NULL) {
				position++;
			}

			todoList[position] = createTask(title, doneByDate, description);
		}
		else if (choice == 2) {
			int orderPosition = 0;
			printf("please input the position number of the task you would like to delete");
			scanf("%d", orderPosition);
			deleteTask(todoList, orderPosition);
		}
		else if (choice == 3) {
			int orderPosition = 0;
			int taskUpdate = 0;
			printf("please input the position number of the task you would like to update");
			scanf("%d", orderPosition);
			printf("please input 1 to update title, 2 to update date, 3 to update description");
			scanf("%d", taskUpdate);
			if (taskUpdate == 1) {
				printf("Please input new Title");
				scanf("%s", title);
				updateTitle(todoList, title, orderPosition);
			}
			else if (taskUpdate == 2) {
				int tm_min = 0;
				int tm_hour = 0;
				int tm_mday = 0;
				int tm_mon = 0;
				int tm_year = 0;
				int tm_wday = 0;
				printf("Please input task done by hour");
				scanf("%d", tm_hour);
				printf("Please input task done by minute");
				scanf("%d", tm_min);
				printf("Please input task done by number date of month");
				scanf("%d", tm_mday);
				printf("Please input task done by number of month");
				scanf("%d", tm_mon);
				printf("Please input task done by number of year");
				scanf("%d", tm_year);

				Date doneByDate = setDate(tm_min, tm_hour, tm_mday, tm_mon, tm_year);
				updateDoneByDate(todoList, doneByDate, orderPosition);
			}
			else if (taskUpdate == 3) {
				printf("Please input new description");
				scanf("%s", description);
				updateDescription(todoList, description, orderPosition);
			}

		}
		else if (choice == 4) {
			int orderPosition = 0;
			printf("please input the position number of the task you would like to display");
			scanf("%d", orderPosition);
			
		}
		else if (choice == 5) {

		}
		else if (choice == 6) {

		}
		else {
			printf("Invalid choice. Try again.\n");
		}
	}
	return 0;
}