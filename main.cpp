#include <iostream>
#include <string>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {
	TodoList todoList;

	// Displays help list if user doesn't enter a parameter.
	if (argc == 1) {
		cout << "./TODO add [date] [task]" << endl
					<< "./TODO remove [task]" << endl
					<< "./TODO printList" << endl
					<< "./TODO printDay [date]" << endl;
		return 0;
	}

	// The first parameter is what the user wants to do.
	string firstArg = string(argv[1]);

	if (firstArg == "add" && argc == 4) {
		todoList.add(string(argv[2]), string(argv[3]));

		cout << "Added " + string(argv[2]) << " " << string(argv[3]) << endl;
	} else if (firstArg == "remove" && argc == 3) {
		// Checks if the task is in the todo list.
		if (!todoList.remove(string(argv[2]))) {
			cout << "Task not found" << endl;
		} else {
			todoList.remove(string(argv[2]));

			cout << "Task successfully removed" << endl;
		}
	} else if (firstArg == "printList" && argc == 2) {
		todoList.printTodoList();
	} else if (firstArg == "printDay" && argc == 3) {
		todoList.printDaysTasks(string(argv[2]));
	} else {
		cout << "./TODO add [date] [task]" << endl
					<< "./TODO remove [task]" << endl
					<< "./TODO printList" << endl
					<< "./TODO printDay [date]" << endl;
	}

	return 0;
}