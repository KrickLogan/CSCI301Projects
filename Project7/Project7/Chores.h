/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project7\
Due Date: 11/10/18
Instructor: Jie Hu Meichsner
*/

#ifndef CHORES_
#define CHORES_
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>

class Chores {
private:
public:
	Chores();
	void displayList(const LinkedList<std::string> list);
	LinkedList<std::string> getListFromFile(std::string fileName, LinkedList<std::string>& list);
};
#include "Chores.cpp"
#endif