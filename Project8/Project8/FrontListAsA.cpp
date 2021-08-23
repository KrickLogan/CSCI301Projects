#include "FrontListAsA.h"

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA()
{
}

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA(const FrontListAsA<ItemType>& sList) :
	LinkedList<ItemType>(static_cast<LinkedList<ItemType>>(sList))
{
}

template<class ItemType>
FrontListAsA<ItemType>::~FrontListAsA()
{
}

template<class ItemType>
bool FrontListAsA<ItemType>::insert(const ItemType & newEntry)
{
	return LinkedList<ItemType>::insert(1, newEntry);
}

template<class ItemType>
bool FrontListAsA<ItemType>::remove()
{
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
ItemType FrontListAsA<ItemType>::retrieve() const
{
	bool ableToGet = LinkedList<ItemType>::getLength() >= 1;
	if (ableToGet)
	{
		return LinkedList<ItemType>::getEntry(1);
	}
}

template<class ItemType>
void FrontListAsA<ItemType>::clear()
{
	LinkedList<ItemType>::clear();
}  // end clear


template<class ItemType>
bool FrontListAsA<ItemType>::isEmpty() const
{
	return LinkedList<ItemType>::isEmpty();
}  // end isEmpty

template<class ItemType>
int FrontListAsA<ItemType>::getLength() const
{
	return LinkedList<ItemType>::getLength();
}  // end getLength

template<class ItemType>
bool FrontListAsA<ItemType>::remove(int position)
{
	return LinkedList<ItemType>::remove(position);
}

template<class ItemType>
ItemType FrontListAsA<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	return LinkedList<ItemType>::getEntry(position);
}