/*
An operation that displays the contents of a queue can be useful during program debugging. Add a display
operation to the ADT queue such that display assumes and uses the link-based implementation of the ADT 
queue.
*/

template<class ItemType>
void LinkedQueue<ItemType>::display()
{
	Node<ItemType>* curPtr = frontPtr;
	cout << "Queue: ";
	while (curPtr != nullptr)
	{
		cout << curPtr->getItem() << " ";
		curPtr = curPtr->getNext();
	}
	curPtr = nullptr;
}