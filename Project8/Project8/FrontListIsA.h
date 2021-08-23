/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#ifndef _Front_List_Is_A
#define _Front_List_Is_A

#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class FrontListIsA : public LinkedList<ItemType> {
public:
	FrontListIsA();
	FrontListIsA(const FrontListIsA<ItemType>& sList);
	~FrontListIsA();

	bool insert(const ItemType& newEntry);
	bool remove();
	ItemType retrieve() const;

	// The inherited methods remove, clear, getEntry, isEmpty, and
	// getLength have the same specifications as given in ListInterface.
 /*
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	bool isEmpty() const;
	int getLength() const;
 */
 // The following methods must be overridden to disable their
 // effect on a front list:
	bool insert(int newPosition, const ItemType& newEntry);
	void replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
};
#include "FrontListIsA.cpp"
#endif // !_Front_List_Is_A