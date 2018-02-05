/**
	@file	LinkedQueue.cpp
	ADT queue: Link-based implementation.
	@author	Brady Helkenn
	@date	11/24/2014
*/
#include"LinkedQueue.h"

//default constructor
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;
}

/**
	copy constructor
	@param	aQueue = LinkedQueue object passed by reference to copy contents from
*/
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue)
{
	//Point to nodes in original chain
	if (aQueue.isEmpty())
	{
		frontPtr = nullptr;
		backPtr = nullptr;
	}
	else
	{
		//sets up pointer to iterate through aQueue
		Node<ItemType>* oldQueuePtr = aQueue.frontPtr;
		
		//sets up first item
		frontPtr = new Node<ItemType>(oldQueuePtr->getItem());
		//in case there's only one item, backPtr must be set to frontPtr
		backPtr = frontPtr;
		
		//steps oldQueuePtr forward for the while loop
		oldQueuePtr = oldQueuePtr->getNext();
		
		while (oldQueuePtr != nullptr)
		{
			//creates a new node from the next in line
			Node<ItemType>* newNodePtr = new Node<ItemType>(oldQueuePtr->getItem());
			//links new queue to it
			backPtr->setNext(newNodePtr);
			//moves backPtr forward
			backPtr = newNodePtr;
			//cleans up newNodePtr
			newNodePtr = nullptr;
		}
		//cleans up oldQueuePtr
		oldQueuePtr = nullptr;
	}
}

/**
	destructor
*/
template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	//if the queue is empty, cleans up front and back pointers to ensure no dangling pointers
	if (isEmpty())
	{
		frontPtr = nullptr;
		backPtr = nullptr;
	}
	//if not empty, then delete each item in the queue, making sure to clean up pointers
	else
	{
		//until frontPtr points to the same item as backPtr
		while (frontPtr->getNext() != nullptr)
		{
			//assigns curPtr to item to be deleted
			Node<ItemType>* curPtr = frontPtr;
			//moves frontPtr forward one node
			frontPtr = frontPtr->getNext();
			//delete target item
			delete curPtr;
			//cleans up dangling curPtr
			curPtr = nullptr;
		}
		//now frontPtr and backPtr are both pointing to the last item in the queue
		//delete the item
		delete frontPtr;
		//clean up dangling pointers
		frontPtr = nullptr;
		backPtr = nullptr;
	}
}

/**
	adds an item to the back of the LinkedQueue object
	@param	newEntry = ItemType item passed by reference to be enqueued
*/
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	//Insert the new node
	if (isEmpty())
		frontPtr = newNodePtr; //The queue was empty
	else
		backPtr->setNext(newNodePtr); //The queue was not empty
	backPtr = newNodePtr; //New node is at back
	return true;
}

/**
	retrieves the front item of the queue
	@return	item of ItemType data type, which is the item in the front of the queue
*/
template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const
{
	ItemType result;
	if (!isEmpty())
	{
		return frontPtr->getItem();
	}
	return result;
}

/**
	removes the item at the front of the queue
	@return false if empty, otherwise true
*/
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
	if (!isEmpty())
	{
		//Queue is not empty; remove front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		if (frontPtr == backPtr)
		{//Special case: one node in queue
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		//Return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		result = true;
	}
	return result;
}

/**
	determines if the queue is empty
	@return	true if empty, otherwise false
*/
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return (frontPtr == nullptr && backPtr == nullptr);
}