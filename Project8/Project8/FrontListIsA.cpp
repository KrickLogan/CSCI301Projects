/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#include "FrontListIsA.h"
#include <cassert>

template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA() {
}

template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA(const FrontListIsA<ItemType>& aList) : LinkedList<ItemType>(aList) {
}

template<class ItemType>
FrontListIsA<ItemType>::~FrontListIsA() {
}

template<class ItemType>
bool FrontListIsA<ItemType>::insert(const ItemType & newEntry) {
	int newPosition = 1;
	return LinkedList<ItemType>::insert(newPosition, newEntry);
}

template<class ItemType>
bool FrontListIsA<ItemType>::remove() {
	bool ableToRemove = false;
	if (!LinkedList<ItemType>::isEmpty())
	{
		int position = 1;

		ableToRemove = position > 0;
		if (ableToRemove)
		{
			ableToRemove = LinkedList<ItemType>::remove(position);
		}  // end if
	}  // end if

	return ableToRemove;
}

template<class ItemType>
ItemType FrontListIsA<ItemType>::retrieve() const {
	bool ableToGet = LinkedList<ItemType>::getLength() >= 1;
	if (ableToGet)
	{
		return LinkedList<ItemType>::getEntry(1);
	}
}

// DISABLED FUNCTIONS

template<class ItemType>
bool FrontListIsA<ItemType>::insert(int newPosition, const ItemType & newEntry) {
	return false;
}

template<class ItemType>
void FrontListIsA<ItemType>::replace(int position, const ItemType & newEntry) throw(PrecondViolatedExcep) {
	throw PrecondViolatedExcep("This is an illegal action!");
}
