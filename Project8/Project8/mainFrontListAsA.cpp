/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#include <iostream>
#include <string>
#include "FrontListAsA.h" // ADT sorted list operations

using namespace std;

void displayList(FrontListAsA <string>* listPtr)
{
	std::cout << "The front list contains " << endl;
	for (int pos = 1; pos <= listPtr->getLength(); pos++)
	{
		std::cout << listPtr->getEntry(pos) << " ";
	} // end for
	std::cout << endl << endl;
}  // end displayList

void copyConstructorTester()
{
	FrontListAsA<string> list;
	string items[] = { "zero", "one", "two", "three", "four", "five" };
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Adding " << items[i] << endl;
		list.insert(items[i]);
	}
	cout << endl;
	displayList(&list);

	FrontListAsA<string> copyOfList(list);
	std::cout << "Copy of list: ";
	displayList(&copyOfList);

	std::cout << "The copied list: ";
	displayList(&list);
}  // end copyConstructorTester

void frontListTester(FrontListAsA <string>* listPtr)
{
	string luke = "Luke";
	string brent = "Brent";
	string donna = "Donna";
	string tom = "Tom";
	string sue = "Sue";
	string jerry = "Jerry";

	std::cout << "\nTest isEmpty with an empty list:" << endl;
	if (listPtr->isEmpty())
		std::cout << "List is empty." << endl;
	else
		std::cout << "isEmpty() error: List is not empty." << endl;

	listPtr->insert(luke);
	listPtr->insert(brent);
	listPtr->insert(donna);
	listPtr->insert(tom);
	listPtr->insert(sue);
	listPtr->insert(jerry);

	// display the list
	std::cout << "List should contain\nBrent, Donna, Jerry, Luke, Sue, Tom" << endl;
	std::cout << "\nList actually contains:";
	displayList(listPtr);

	// test remove
	std::cout << "Test remove:\n" << endl;
	while (!listPtr->isEmpty()) {
		listPtr->remove();
	}
	std::cout << "All items should be removed from list." << endl;
	std::cout << "\nTest isEmpty with an empty list:" << endl;
	if (listPtr->isEmpty())
		std::cout << "List is empty." << endl;
	else
		std::cout << "isEmpty() error: List is not empty." << endl;

} // end frontListTester

int main()
{
	copyConstructorTester();

	FrontListAsA <string>* listPtr = new FrontListAsA<string>();
	std::cout << "Testing the Link-Based Front List:" << endl;
	frontListTester(listPtr);
	std::cout << "======================================" << endl;

	return 0;
}  // end main