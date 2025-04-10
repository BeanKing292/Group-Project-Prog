#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_TITLE_SIZE 20
#define MAX_DESC_SIZE 100

typedef struct Date {
    int tm_min;   // minutes (0-59)
    int tm_hour;  // hours (0-23)
    int tm_mday;  // day of month (1-31)
    int tm_mon;   // month (0-11)
    int tm_year;  
}Date;

typedef struct Task {
    char title[MAX_TITLE_SIZE]; // the title will be shorter then description, saving memory -  Alex
    Date doneByDate;
    char description[MAX_DESC_SIZE];
} Task;

Task createTask(char* title, Date doneByDate, char* description);

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year);

void deleteTask(Task* todoList[], int orderPosition);

void displayRange(Task* TodoList);

void displayAll(Task* TodoList);

void updateTitle(Task* todoList[], char title, int orderPosition);

void updateDescription(Task* todoList[], char description, int orderPosition);

void updateDoneByDate(Task* todoList[], Date doneByDate, int orderPosition);

void printTask(Task* TodoList[], int orderPosition);

void printDate(Task* task);