/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project8\
Due Date: 11/20/18
Instructor: Jie Hu Meichsner
*/

#include "FrontListHasA.h"
#include "LinkedList.h"
#include <cassert>

template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA()
{
	listPtr = new LinkedList<ItemType>();
}

template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA(const FrontListHasA<ItemType>& sList)
{
	// First, create our own list
	listPtr = new LinkedList<ItemType>();

	// Then add items to it using public methods
	for (int position = 1; position <= sList.getLength(); position++)
	{
		listPtr->insert(position, sList.getEntry(position));
	}  // end for	
}

template<class ItemType>
FrontListHasA<ItemType>::~FrontListHasA()
{
}

template<class ItemType>
bool FrontListHasA<ItemType>::insert(const ItemType & newEntry)
{
	return listPtr->insert(1, newEntry);
}

template<class ItemType>
bool FrontListHasA<ItemType>::remove()
{
	bool ableToRemove = false;
	if (!isEmpty())
	{
		int position = 1;

		ableToRemove = position > 0;
		if (ableToRemove)
		{
			ableToRemove = listPtr->remove(position);
		}  // end if
	}  // end if

	return ableToRemove;
}

template<class ItemType>
ItemType FrontListHasA<ItemType>::retrieve() const
{
	bool ableToGet = listPtr->getLength() >= 1;
	if (ableToGet)
	{
		return listPtr->getEntry(1);
	}
}

template<class ItemType>
bool FrontListHasA<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}

template<class ItemType>
int FrontListHasA<ItemType>::getLength() const
{
	return listPtr->getLength();
}

template<class ItemType>
ItemType FrontListHasA<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	return listPtr->getEntry(position);
}
