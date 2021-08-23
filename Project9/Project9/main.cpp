/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project9\
Due Date: 12/5/18
Instructor: Jie Hu Meichsner
*/

#include "LinkedList.h"
#include "ListQueue.h"
#include "Event.h"
#include "SL_PriorityQueue.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main() {	
	std::cout << "Beginning Simulation..." << endl << endl;
	
	ListQueue<Event>* bankQueue = new ListQueue<Event>(); // bank line
	SL_PriorityQueue<Event>* eventListPQueue = new SL_PriorityQueue<Event>(); // event list
	Event eveList;
	std::string fileName = "eventList.txt";
	int customerCount = 0;
	double avgWaitTime = 0, totalWaitTime = 0;

	bool tellerAvailable = true;

	// Create and add arrival events to event list

		std::string line;
		std::ifstream file(fileName.c_str());
		int pos = 1;
		if (!file) {
			std::cout << "Unable to open file: " << fileName << endl;
			return 0;
		}
		else if (file) {
			int arTime, trLength;

			while (file >> arTime >> trLength) {
				eveList.setType('a');
				eveList.setArrivalTime(arTime);
				eveList.setTransLength(trLength);
				eventListPQueue->add(eveList);
			}
		}
		file.close();

	// Event loop
	while (!eventListPQueue->isEmpty()) {
		Event newEvent = eventListPQueue->peek();

		// Get current time
		int currentTime = newEvent.getArrivalTime();

		// Process Arrival
		if (newEvent.getType() == 'a') {
			std::cout << "Processing an arrival event at time: " << currentTime << endl;
			eventListPQueue->remove();
			Event customer = newEvent;
			if (bankQueue->isEmpty() && tellerAvailable) {
				int departureTime = currentTime + newEvent.getTransLength();
				totalWaitTime += currentTime - customer.getArrivalTime();

				Event newDepartureEvent;
				newDepartureEvent.setType('d');
				newDepartureEvent.setArrivalTime(departureTime);

				eventListPQueue->add(newDepartureEvent);
				tellerAvailable = false;
			}
			else
				bankQueue->enqueue(customer);
		}
		else { // Process Departure
			std::cout << "Processing a departure event at time: " << currentTime << endl;
			customerCount++;
			eventListPQueue->remove();

			if (!bankQueue->isEmpty()) {
				Event customer = bankQueue->peekFront();
				bankQueue->dequeue();
				int departureTime = currentTime + customer.getTransLength();
				totalWaitTime += currentTime - customer.getArrivalTime();

				Event newDepartureEvent;
				newDepartureEvent.setType('d');
				newDepartureEvent.setArrivalTime(departureTime);

				eventListPQueue->add(newDepartureEvent);
			}
			else
			{
				tellerAvailable = true;
			}
		}
	}
	std::cout << "Simulation Complete." << endl << endl;
	std::cout << "Final Statistics:" << endl
		<< "Total number of customers processesd: " << customerCount << endl;

	avgWaitTime = totalWaitTime / customerCount;
	std::cout << "Average amount of time spent waiting: " << avgWaitTime << endl;

	return 0;
};