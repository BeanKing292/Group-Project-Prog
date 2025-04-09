#include "Task.h"

Task createTask(const char* title, Date doneByDate, char* description) {
	Task newTask = { 0 };
	int len = strlen(title) + 1;
	*newTask.title = (char*)malloc(len * sizeof(char));
	if (newTask.title == NULL) {
		fprintf(stderr, "error");
		exit(EXIT_FAILURE);
	}
	strncpy(newTask.title, title, len);

	len = strlen(description) + 1;
	*newTask.description = (char*)malloc(len * sizeof(char));
	if (newTask.description == NULL) {
		fprintf(stderr, "error");
		exit(EXIT_FAILURE);
	}
	strncpy(newTask.description, description, len);
	newTask.doneByDate = doneByDate;
	return newTask;
}

Task* getTask(Task* todoList[], int orderPosition) {
	return todoList[orderPosition - 1];
}

void deleteTask(Task* todoList[], int orderPosition) {
	free(todoList[orderPosition - 1]);
	while (todoList[orderPosition] != '\0') {
		if (todoList[orderPosition - 1] == NULL) {
			if (todoList[orderPosition] != NULL || todoList[orderPosition - 1] != '\0') {
				todoList[orderPosition - 1] = todoList[orderPosition];
				orderPosition++;
			}
		}
	}
}

void updateTitle(Task* todoList[], char title, int orderPosition) {
	strcpy(todoList[orderPosition]->title, title);
}

void updateDoneByDate(Task* todoList[], Date doneByDate, int orderPosition) {
	todoList[orderPosition]->doneByDate = doneByDate;
}

void updateDescription(Task* todoList[], char description, int orderPosition) {
	strcpy(todoList[orderPosition]->description, description);
}

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year) {
	Date newDate;
	newDate.tm_min = tm_min;
	newDate.tm_hour = tm_hour;
	newDate.tm_mday = tm_mday;
	newDate.tm_mon = tm_mon;
	newDate.tm_year - tm_year;
}
void displayOne(Task* TodoList) {
	int boolean = 0, check = 11, sumDate;
	scanf("%d", &boolean);
	if (boolean == 1) {
		int min = 10000000;
		//	sumDate = day + (30 * month) + (364 * year);
		for (int i = 0; i <= sizeof(TodoList); i++) {
			sumDate = TodoList[i].doneByDate.tm_mday + (30 * TodoList[i].doneByDate.tm_mon) + (364 * TodoList[i].doneByDate.tm_year);
			if (sumDate < min) {
				min = sumDate;
				check = i;
			}
		}
	}
	else if(boolean == 2){
		int day, month, year, lookDate;
		scanf("%d %d", &day, &month, &year);
		for (int i = 0; i <= sizeof(TodoList); i++) {
			lookDate = day + (30 * month) + (364 * year);
			sumDate = TodoList[i].doneByDate.tm_mday + (30 * TodoList[i].doneByDate.tm_mon) + (364 * TodoList[i].doneByDate.tm_year);
			if (sumDate == lookDate) {
				check = i;
			}
		}
	}
	else if (boolean == 3) {
		char* title = TodoList[0].title;
	//	scanf("%s", title);
		for (int i = 0; i <= sizeof(TodoList); i++) {
			if (TodoList[i].title == title) {
				check = i;
			}
		}
	}
	if (check < 10) {
		printf("%s \n %s.\n", TodoList[check].title, TodoList[check].description);
	}
}

void displayRange(Task* TodoList) {
	int boolean = 0;
	printf("put in 1 for range in order made and 2 for range in date\n");
	scanf("%d", &boolean);
	if (boolean == 1) {
		printf("put in bottom of range then top\n");
		int rangeBottom = 0, rangeTop = 0;
		scanf("%d %d", &rangeBottom, &rangeTop);
		for (int i = rangeBottom; i <= rangeTop; i++) {
			printf("%s \n %s.\n", TodoList[i].title, TodoList[i].description);
		}
	}
	else if (boolean == 2){
		printf("put in bottom of range then top\n");
		int dayBottom = 0, monthBottom = 0, yearBottom = 0, dayTop = 0, monthTop = 0, yearTop = 0, sumBottom, sumTop, sumDate;
		scanf("%d %d", &dayBottom, &monthBottom, &yearBottom, &dayTop, &monthTop, &yearTop);
		sumBottom = dayBottom + (30 * monthTop) + (364 * yearBottom);
		sumTop = dayTop + (30 * monthTop) + (364 * yearTop);
		for (int i = 0; i <= sizeof(TodoList); i++) {
			sumDate = TodoList[i].doneByDate.tm_mday + (30 * TodoList[i].doneByDate.tm_mon) + (364 * TodoList[i].doneByDate.tm_year);
			if (sumDate < sumTop && sumDate > sumBottom) {
				printf("%s \n %s.\n", TodoList[i].title, TodoList[i].description);
			}
		}
	}
}

void displayAll(Task* TodoList) {
	for (int i = 0; i <= sizeof(TodoList); i++) {
		printf("%s \n %s.\n", TodoList[i].title, TodoList[i].description);
	}
}

void printDate(Task* task) {
	printf("%d:%d\n", task->doneByDate.tm_hour, task->doneByDate.tm_min);
	printf("%d/%d/%d", task->doneByDate.tm_mon, task->doneByDate.tm_mday, task->doneByDate.tm_year);
}

void printTask(Task* TodoList[], int orderPosition) {
	Task* task;
	task = getTask(TodoList, orderPosition);

	printf("%s\n", task->title);
	printf("%s\n", task->description);
	printDate(task);

}