/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#ifndef _Front_List_As_A
#define _Front_List_As_A

#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class FrontListAsA : private LinkedList<ItemType> {
public:
	FrontListAsA();
	FrontListAsA(const FrontListAsA<ItemType>& sList);
	~FrontListAsA();

	bool insert(const ItemType& newEntry);
	bool remove();
	ItemType retrieve() const;

	// The following methods are inherited and have the same 
   // specifications as given in ListInterface:
	bool isEmpty() const;
	int getLength() const;
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
};
#include "FrontListAsA.cpp"
#endif // !_Front_List_As_A