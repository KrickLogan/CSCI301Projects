/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project9\
Due Date: 12/5/18
Instructor: Jie Hu Meichsner
*/

#ifndef EVENT_
#define EVENT_
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>

class Event {
private:
	char type;
	int arrivalTime, transLength;
public:
	Event();
	~Event();
	void setType(const char c);
	void setArrivalTime(const int time);
	void setTransLength(const int length);
	char getType();
	int getArrivalTime();
	int getTransLength();

friend std::istream& operator >>(std::istream& ins, Event& eve)
{
	int aTime, tLength;
	
	ins >> aTime >> tLength;
	eve.setArrivalTime(aTime);
	eve.setTransLength(tLength);

	return ins;
} // end Node

};

//nonmemeber 
bool operator >(Event a1, Event a2)
{
	if (a1.getArrivalTime() < a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator <(Event a1, Event a2)
{
	if (a1.getArrivalTime() > a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator >=(Event a1, Event a2)
{
	if (a1.getArrivalTime() <= a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator <=(Event a1, Event a2)
{
	if (a1.getArrivalTime() >= a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator == (Event a1, Event a2)
{
	if (a1.getArrivalTime() == a2.getArrivalTime())
		return true;
	else
		return false;
}

bool operator!= (Event a1, Event a2)
{
	if (a1.getArrivalTime() != a2.getArrivalTime())
		return true;
	else
		return false;
}

#include "Event.cpp"
#endif