/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project7\
Due Date: 11/10/18
Instructor: Jie Hu Meichsner
*/

#include "Chores.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Chores::Chores() {
}

/* Displays a given list and uses a try-catch block for handling exceptions.
@pre must pass a list
@post displays the list and handles an exception */
void Chores::displayList(const LinkedList<std::string> list) {
	std::cout << "There are " << list.getLength() << " items on the list." << endl;
	std::cout << "***** Today's List *****" << endl;
	for (int pos = 1; pos <= list.getLength(); pos++) {
		try {
			std::cout << pos << ".  " << list.getEntry(pos) << endl;
		}
		catch (PrecondViolatedExcep except) {
			std::cout << "Exception thrown getting entry inserted at position " << pos << endl;
			std::cout << except.what() << endl;
		}
	}
	std::cout << endl;
}

/* Reads in a given list line by line from a given file.
@pre must pass a filename and list.
@post reads each line of a file and adds it to the list */
LinkedList<std::string> Chores::getListFromFile(std::string fileName, LinkedList<std::string>& list) {
	std::string line;
	std::ifstream file(fileName.c_str());
	int pos = 1;
	if (!file) {
		std::cout << "Unable to open file: " << fileName << endl << "The program will now terminate." << endl;
		return list;
	}
	else if (file) {
		while (getline(file, line)) {
			list.insert(pos, line);
			pos++;
		}
	}
	file.close();
	return list;
}