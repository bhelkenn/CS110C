/**
	@file	insertSorted.h
	defines LinkedSortedList<ItemType>::insertSorted() method, defined on p.356
	@author Brady Helkenn
	@date 10/22/2014
*/

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry); //defined on page 356
	
	if (isEmpty() || (prevPtr == nullptr)) // add at beginning
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	}
	itemCount++;
}