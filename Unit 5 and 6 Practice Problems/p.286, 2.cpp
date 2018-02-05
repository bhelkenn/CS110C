/**
	@file	p.286, 2.cpp
	Defines the method setEntry for the class LinkedList
	@author Brady Helkenn
	@date 10/14/2014
*/

/**
	sets the entry for a node at a certain position with a specific ItemType entry
	@param	position = position in the LinkedList
	@param	entry = data of ItemType data type to input at desired position
	@pre	1 <= position <= itemCount
*/
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& entry)
{
	//Enforce precondition
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(entry);
	}
	else
	{
		string message = "setEntry() called with an empty list or invalid position.";
		throw(PrecondViolatedExcep(message));
	}
}