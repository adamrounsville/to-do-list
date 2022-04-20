#include "TodoList.h"

TodoList::TodoList() {
		ifstream infile;
		infile.open("TODOList.txt");

		string task;

		if (infile.is_open()) {
			while (getline(infile, currentLine)) {
				dueDates.push_back(currentLine);
				getline(infile, currentLine);
				tasks.push_back(currentLine);
      }
		}

		infile.close();
}

TodoList::~TodoList() {
	ofstream outfile;
	outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);

	for (int i = 0; i < tasks.size(); i++) {
		outfile << dueDates.at(i) << endl;
		outfile << tasks.at(i) << endl;
	}

	outfile.close();
}

void TodoList::add(string _duedate, string _task) {
	dueDates.push_back(_duedate);
	tasks.push_back(_task);
}

int TodoList::remove(string _task) {
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks.at(i) == _task) {
			tasks.erase(tasks.begin() + i);
			dueDates.erase(dueDates.begin() + i);

			return 1;
		}
	}

	return 0;
}

void TodoList::printTodoList() {
	for (int i = 0; i < tasks.size(); i++) {
		cout << dueDates.at(i) << endl;
		cout << tasks.at(i) << endl;
	}
}

void TodoList::printDaysTasks(string _date) {
	for (int i = 0; i < dueDates.size(); i++) {
		if (dueDates.at(i) == _date) {
			cout << tasks.at(i) << endl;
		}
	}
}