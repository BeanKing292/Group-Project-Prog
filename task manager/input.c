// making separate input functions because they help with organization - Alex

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "input.h"

#define MAX_TASKS 10
#define MAX_TITLE_SIZE 20
#define MAX_DESC_SIZE 100

int inputInt(char* prompt) {
	int input = 0;
	// prints  prompt.
	printf("\n%s", prompt);
	// Get the input form user
	scanf_s("%d", &input);
	// Clear the input buffer
	while (getchar() != '\n');
	return input;
}

void inputString(char* dst, char* inputPrompt, int MaxLength) {
	char input[MAX_DESC_SIZE] = { 0 };
	// prints the input prompt.
	printf("%s", inputPrompt);
	// Get the input form user
	scanf_s("%[^\n]", input, MaxLength);
	// Clear the input buffer
	while (getchar() != '\n');
	strncpy_s(dst, (sizeof(char) * MaxLength), input, MaxLength);
}