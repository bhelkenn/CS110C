/**
	@file	p.286, 5.cpp
	implements the method getPosition() for each of the classes ArrayList and LinkedList
	@author	Brady Helkenn
	@date 10/21/2014
*/

/**
	@param anEntry = ItemType to identify location of
	@return position (0 if not found) of anEntry
*/
template<class ItemType>
int ArrayList<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 0;
	
	if (!isEmpty())
	{
		int index = 0;
		
		while ((position == 0) && (index < itemCount)) // while not found
		{
			if (anEntry == items[index])
				position = index + 1; // anEntry is located
			else
				index++;
		}
	}
	return position;
}

/**
	@param anEntry = ItemType to identify location of
	@return position (0 if not found) of anEntry
*/
int LinkedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 0;
	if (!isEmpty())
	{
		int index = 0;
		Node<ItemType>* curPtr = headPtr;
		
		while ((position == 0) && (index < itemCount)) // while not found
		{
			if (anEntry == curPtr->getItem())
				position = index + 1; // anEntry is located
			else
			{
				index++;
				curPtr = curPtr->getNext();
			}
		}
	}
	return position;
}