/**
	@file p.286, 3.cpp
	Defines the copy constructor for the class LinkedList
	@author Brady Helkenn
	@date 10/14/2014
*/

/**
	copies a node into a new LinkedList at same position
	@param	position = chain position
	@param	entry = data in node at specified position
	@pre	position is at the end of the chain
*/
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
	//points to nodes in original chain
	Node<ItemType>* origChainPtr = aList.headPtr;
	
	//if list is empty
	if (origChainPtr == nullptr)
		headPtr = nullptr;
	else
	{
		//copy first node
		headPtr = new Node<ItemType>();
		headptr->setItem(origChainPtr->getItem());
		
		//copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		
		//Points to last node in new chain
		origChainPtr = origChainPtr->getNext();
		while (origChainPtr != nullptr)
		{
			//get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
			
			//create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			
			//link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			//advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}
	}
}