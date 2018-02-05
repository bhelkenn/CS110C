/**
	@file	LinkedScroll.cpp
	ADT scroll: Link-based implementation.
	@author	Brady Helkenn
	@date	11/24/2014
*/

#include"LinkedScroll.h"

/**
	removes the item pointed to by backPtr, rather than standard dequeue process
	@return	result = if empty, returns false; otherwise, return true
*/
template<class ItemType>
bool LinkedScroll<ItemType>::removeLast()
{
	bool result = false;
	if (LinkedQueue<ItemType>::frontPtr != nullptr || LinkedQueue<ItemType>::backPtr != nullptr)
	{
		result = true;
		//special case: only one node left
		if (LinkedQueue<ItemType>::frontPtr == LinkedQueue<ItemType>::backPtr)
		{
			delete LinkedQueue<ItemType>::backPtr;
			LinkedQueue<ItemType>::frontPtr = nullptr;
			LinkedQueue<ItemType>::backPtr = nullptr;
		}
		else
		{
			Node<ItemType>* prevPtr = LinkedQueue<ItemType>::frontPtr;
			//until prevPtr is one node before backPtr
			while (prevPtr->getNext() != LinkedQueue<ItemType>::backPtr)
			{
				//move prevPtr forward one node
				prevPtr = prevPtr->getNext();
			}
			//remove last node from system
			prevPtr->setNext(nullptr);
			delete LinkedQueue<ItemType>::backPtr;
			LinkedQueue<ItemType>::backPtr = prevPtr;
			prevPtr = nullptr;
		}
	}
	return result;
}