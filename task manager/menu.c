// All function involving our UI

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "menu.h"
#include "input.h"

// 1. New task menu
void newTaskUI(Task* todoList) {
	// initializing variables
	char title[MAX_TITLE_SIZE] = {0};
	char description[MAX_DESC_SIZE] = { 0 };
	int position = 0;

	inputString(title, "Please input task title", MAX_TITLE_SIZE);
	inputString(description, "Please input task description", MAX_DESC_SIZE);	

	Date doneByDate = setDate(
		inputInt("Please input task done by minute: "),
		inputInt("Please input task done by hour: "),
		inputInt("Please input task done by number date of month: "),
		inputInt("Please input task done by number of month: "),
		inputInt("Please input task done by number of year: ")
	);
	if (todoList[position].title != NULL) {
		position++;
	}
	todoList[position] = createTask(title, doneByDate, description);
}

// 2. New task menu

// 3. Update task menu

// 4. Display task menu


// The main UI
void mainUI(Task* todoList) {
	printf(
		"\nMenu:"
		"\n1. New Task"
		"\n2. Delete Task"
		"\n3. Update Task"
		"\n4. Display Task"
		"\n5. Display Range"
		"\n6. Display all Tasks"
		"\n7. Search for Tasks");
	// Option selection
	switch (inputInt(">>>")) {
	case 1:
		newTaskUI(todoList);
		break;
	case 2:
		printf("\n2. Delete Task");
		break;
	case 3:
		printf("\n3. Update Task");
		break;
	case 4:
		printf("\n4. Display Task");
		int orderPosition = inputInt("please input the position number of the task you would like to display: ");
		printf("%s", todoList[orderPosition].title);
		break;
	case 5:
		printf("\n5. Display Range");
		break;
	case 6:
		printf("\n6. Display all Tasks");
		break;
	case 7:
		printf("\n7. Search for Tasks");
		break;
	default:
		printf("\nERROR: invalid input");
		break;
	}
}