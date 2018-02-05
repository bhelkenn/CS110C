/**
	@file	LinkedQueue.h
	ADT queue: Link-based implementation.
	@author	Brady Helkenn
	@date	11/21/2014
*/
#include "QueueInterface.h"
#include "Node.h"

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template<class ItemType>
class LinkedQueue: public QueueInterface<ItemType>
{
protected:
	//The queue is implemented as a chain of linked nodes that has
	//two external pointers, a head pointer for the front of the queue
	//and a tail pointer for the back of the queue.
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue&);
	~LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const ItemType&);
	bool dequeue();
	/**
		@throw PrecondViolatedExcep if the queue is empty
	*/
	ItemType peekFront() const;
};

#endif