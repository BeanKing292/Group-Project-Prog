#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct Date {
    int tm_min;   // minutes (0-59)
    int tm_hour;  // hours (0-23)
    int tm_mday;  // day of month (1-31)
    int tm_mon;   // month (0-11)
    int tm_year;  // years since 1900
    int tm_wday;  // day of week (0-6, Sunday=0)
    int tm_yday;  // day of year (0-365)
}Date;

typedef struct Task {
    char title[100];
    Date doneByDate;
    char description[100];
} Task;

Task createTask(char* title, Date doneByDate, char* description);

Date setDate(int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year, int tm_wday, int tm_yday);

void displayRange(Task* TodoList);

void displayAll(Task* TodoList);