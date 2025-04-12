#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

#define MAX_TASKS 10
#define MAX_TITLE_SIZE 20
#define MAX_DESC_SIZE 100

typedef struct _Date {
    int tm_min;   // minutes (0-59)
    int tm_hour;  // hours (0-23)
    int tm_mday;  // day of month (1-31)
    int tm_mon;   // month (0-11)
    int tm_year;  
}Date;

typedef struct _Task {
    char title[MAX_TITLE_SIZE];
    Date doneByDate;
    char description[MAX_DESC_SIZE];
    int isTask;
} Task;

Task* createTask(char* title, Date doneByDate, char* description);

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year);

void deleteTask(Task** todoList, int orderPosition, ManagerInfo* position);

void updateTitle(Task* todoList[], char* title, int orderPosition);

void updateDescription(Task* todoList[], char* description, int orderPosition);

void updateDoneByDate(Task* todoList[], Date doneByDate, int orderPosition);

void printTask(Task* TodoList[], int lowerRange, int upperRange);

void printDate(Task* task);

void taskSearch(Task* TodoList[], ManagerInfo* position, char* searchTerm);