// All function involving our UI

#include "Task.h"
#include "menu.h"

// The main UI
void mainUI() {
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
	switch (inputINT(">>>")) {
	case 1:
		printf("\n1.New Task");
		break;
	case 2:
		printf("\n2. Delete Task");
		break;
	case 3:
		printf("\n3. Update Task");
		break;
	case 4:
		printf("\n4. Display Task");
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