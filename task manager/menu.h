#pragma once
#include "Task.h"

typedef struct _ManagerInfo {
	int taskAmount;
} ManagerInfo;

void mainUI(Task** todoList, ManagerInfo* position);

void newTaskUI(Task** todoList, ManagerInfo* position);