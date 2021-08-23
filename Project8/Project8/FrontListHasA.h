/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#ifndef _Front_List_Has_A
#define _Front_List_Has_A
/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#include "LinkedList.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class FrontListHasA
{
private:
	ListInterface<ItemType>* listPtr;
public:
	FrontListHasA();
	FrontListHasA(const FrontListHasA<ItemType>& aList);
	~FrontListHasA();

	bool insert(const ItemType& newEntry);
	bool remove();
	ItemType retrieve() const;

	bool isEmpty() const;
	int getLength() const;
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
};
#include "FrontListHasA.cpp"
#endif // !_Front_List_Has_A

