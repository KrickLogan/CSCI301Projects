/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project9\
Due Date: 12/5/18
Instructor: Jie Hu Meichsner
*/

#include "Event.h"

Event::Event()
{
	type = '0';
	arrivalTime = 0;
	transLength = 0;
}

Event::~Event()
{
}

void Event::setType(const char c)
{
	type = c;
}

void Event::setArrivalTime(const int time)
{
	arrivalTime = time;
}

void Event::setTransLength(const int length)
{
	transLength = length;
}

char Event::getType()
{
	return type;
}

int Event::getArrivalTime()
{
	return arrivalTime;
}

int Event::getTransLength()
{
	return transLength;
}
