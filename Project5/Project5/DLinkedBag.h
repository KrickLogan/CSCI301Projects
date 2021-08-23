//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	@file LinkedBag.h
	Listing 4-3 */
#ifndef DLINKED_BAG_
#define DLINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class DLinkedBag : public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node
	Node<ItemType>* prevPtr; // Pointer to the previous node
	int itemCount;           // Current count of bag items

	// Returns either a pointer to the node containing a given entry
	// or the null pointer if the entry is not in the bag.
	Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
	DLinkedBag();
	DLinkedBag(const DLinkedBag<ItemType>& aBag); // Copy constructor
	virtual ~DLinkedBag();                       // Destructor should be virtual
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
}; // end LinkedBag

#include "DLinkedBag.cpp"
#endif