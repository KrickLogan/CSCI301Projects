/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project7\
Due Date: 11/10/18
Instructor: Jie Hu Meichsner
*/

#include "ListInterface.h"
#include "LinkedList.h"
#include "Chores.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	Chores chore;
	LinkedList<string> list;
	int deleteEntry, addPos;
	string addEntry, newEntry;
	bool deletingEntry = true, addingEntry = true;

	// gets a list from a file and stores it in the list
	chore.getListFromFile("choreList.txt", list);
	// displays list
	chore.displayList(list);

	// Let's the user keep deleting entries from the list until they choose to move on.
	while (deletingEntry) {
		std::cout << "Which item do you want to delete from the list? Use -999 to stop. -> ";
		std::cin >> deleteEntry;
		if (deleteEntry == -999) {
			deletingEntry = false;
		}
		else {
			list.remove(deleteEntry);
			chore.displayList(list);
		}
	}

	// Let's the user keep adding entries to the list until they chose to move on.
	while (addingEntry) {
		std::cout << "Would you like to add an item to your list? yes or no. -> ";
		std::cin >> addEntry;
		if (addEntry == "yes") {
			std::cout << "Position -> ";
			std::cin >> addPos;
			std::cout << "Item -> ";
			std::cin.ignore();
			getline(cin,newEntry);

			list.insert(addPos, newEntry);

			chore.displayList(list);
		}
		else if (addEntry == "no") {
			addingEntry = false;
			chore.displayList(list);
		}
	}
	return 0;
}