// All function involving our UI

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "menu.h"
#include "input.h"

// 1. New task menu
void newTaskUI(Task** todoList, ManagerInfo* position) {
	// initializing variables
	char title[MAX_TITLE_SIZE] = {0};
	char description[MAX_DESC_SIZE] = { 0 };
	inputString(title, "Please input task title: ", MAX_TITLE_SIZE);
	inputString(description, "Please input task description: ", MAX_DESC_SIZE);	

	Date doneByDate = setDate(
		inputInt("Please input task done by minute: "),
		inputInt("Please input task done by hour: "),
		inputInt("Please input task done by number date of month: "),
		inputInt("Please input task done by number of month: "),
		inputInt("Please input task done by number of year: ")
	);
	if (todoList[position->taskAmount]->title != NULL) {
		position->taskAmount++;
	}
	todoList[position->taskAmount-1] = createTask(title, doneByDate, description);
}

// 3. Update task menu
void updateTaskUI(Task** todoList) {
	int orderPosition = inputInt("\nplease input the position number of the task you would like to update: ");
	int taskUpdate = inputInt("please input 1 to update title, 2 to update date, 3 to update description: ");
	if (taskUpdate == 1) {
		char newTitle[MAX_TITLE_SIZE] = { 0 };
		inputString(newTitle, "Please input new Title: ", MAX_TITLE_SIZE);
		updateTitle(todoList, newTitle, orderPosition);
	}
	else if (taskUpdate == 2) {
		Date doneByDate = setDate(
			inputInt("Please input task done by minute: "),
			inputInt("Please input task done by hour: "),
			inputInt("Please input task done by number date of month: "),
			inputInt("Please input task done by number of month: "),
			inputInt("Please input task done by number of year: ")
			);
		updateDoneByDate(todoList, doneByDate, orderPosition);
	}
	else if (taskUpdate == 3) {
		char newDescription[MAX_DESC_SIZE] = { 0 };
		inputString(newDescription, "Please input new description: ", MAX_DESC_SIZE);
		updateDescription(todoList, newDescription, orderPosition);
	}
}

// The main UI
void mainUI(Task** todoList, ManagerInfo* position) {
	printf(
		"\nMenu:"
		"\n1. New Task"
		"\n2. Delete Task"
		"\n3. Update Task"
		"\n4. Display Task"
		"\n5. Display Range"
		"\n6. Display all Tasks"
		"\n7. Search for Tasks"
		"\n8. Exit");
	// Option selection
	switch (inputInt(">>>")) {
		case 1:
			if (position > MAX_TASKS) {
				printf("To many tasks, delete some to make room for new ones");
				break;
			}
			newTaskUI(todoList, position);
			break;
		case 2:
			deleteTask(todoList, inputInt("please input the position number of the task you would like to delete: "), position);
			break;
		case 3:
			updateTaskUI(todoList);
			break;
		case 4: {
			int orderPosition = inputInt("please input the position number of the task you would like to display: ");
			if (orderPosition > position->taskAmount) {
				fprintf(stderr, "ERROR: task does not exist");
				break;
			}
			printTask(todoList, orderPosition, orderPosition);
			break;
		}
		case 5: {

			int lower = inputInt("please input the lower range of the tasks you would like to display: ");
			int upper = inputInt("please input the upper range of the tasks you would like to display: ");
			if (lower > position->taskAmount || upper > position->taskAmount) {
				fprintf(stderr, "ERROR: task does not exist");
				break;
			}
			printTask(todoList, lower, upper);
			break;
		}
		case 6:
			if (position->taskAmount = 0) {
				fprintf(stderr, "ERROR: No tasks to display");
				break;
			}
			printTask(todoList, 1, position->taskAmount);
			break;
		case 7:
			printf("\n7. Search for Tasks");
			break;
		case 8:
			printf("Exiting...");
			exit(0);
		default:
			fprintf(stderr, "\nERROR: invalid input");
			break;
	}
}