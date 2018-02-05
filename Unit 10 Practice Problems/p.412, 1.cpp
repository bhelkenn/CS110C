/**
	Implement the copy constructor for the class LinkedQueue that is declared in Listing 14-3. Hint: Look at the 
	copy constructor for the ADT stack in Listing 7-4 of Chapter 7.
*/

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