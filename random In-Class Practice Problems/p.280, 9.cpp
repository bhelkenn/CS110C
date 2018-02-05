/**
	@file	p.280, 9.cpp
	destructor for a LinkedList without using remove() or clear()
	@author Brady Helkenn
	@date 10/15/2014
*/

template<typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->getNext();
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}
	itemCount = 0;
}