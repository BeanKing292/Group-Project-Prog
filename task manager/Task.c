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

Task* getTask(Task todoList[], int orderPosition) {
//	return  
}

void deleteTask(Task* task) {
	free(task);
}

Task* updateTitle(Task* task, char title) {
	strcpy(task->title, title);
	return task;
}

Task* updateDoneByDate(Task* task, Date doneByDate) {
	task->doneByDate = doneByDate;
	return task;
}

Task* updateDescription(Task* task, char description) {
	strcpy(task->description, description);
	return task;
}

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year, int tm_wday, int tm_yday) {
	Date newDate;
	newDate.tm_min = tm_min;
	newDate.tm_hour = tm_hour;
	newDate.tm_mday = tm_mday;
	newDate.tm_mon = tm_mon;
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
	scanf("%d", &boolean);
	if (boolean == 1) {
		int rangeBottom = 0, rangeTop = 0;
		scanf("%d %d", &rangeBottom, &rangeTop);
		for (int i = rangeBottom; i <= rangeTop; i++) {
			printf("%s \n %s.\n", TodoList[i].title, TodoList[i].description);
		}
	}
	else if (boolean == 2){
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