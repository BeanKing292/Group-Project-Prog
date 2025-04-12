#pragma once

typedef struct ManagerInfo {
	int taskAmount;
}ManagerInfo;

void mainUI(Task** todoList, ManagerInfo* position);

void newTaskUI(Task** todoList, ManagerInfo* position);