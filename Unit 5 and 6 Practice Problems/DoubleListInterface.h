/**
	@file	DoubleListInterface.h
	Per p.287, 12:
	defines the interface to ADT DoubleListInterface
		A double-ended list has operations that operate at its beginning and end,
		in addition to the operations of the list, as given in Section 8.1 of Chapter 8.
		For example, you can add, remove, and get the first and last entries in a double-ended list
	@author Brady Helkenn
	@date 10/21/2014
*/

#ifndef DOUBLE_LIST_INTERFACE_H
#define DOUBLE_LIST_INTERFACE_H

template<class ItemType>
class DoubleListInterface: public ListInterface
{
public:
	/**
	inserts an entry at the beginning of the list
	@post	newEntry is at the beginning of the list and other entries are renumbered accordingly.
	@param	newEntry = The entry to insert into the list.
	*/
	void insertFirst(1, const ItemType& newEntry);
	
	/**
	inserts an entry at the end of the list
	@post	newEntry is at the end of the list.
	*/
	void insertLast(getLength() + 1, const ItemType& newEntry);
	
	/**
	removes the entry at the beginning of the list
	@post	first entry is removed and other entries are renumbered accordingly.
	*/
	void removeFirst(1);
	
	/**
	removes the entry at the end of the list
	@post	last entry is removed.
	*/
	void removeLast(getLength());
	
	/**
	gets the entry at the beginning of the list
	@return	the ItemType value of the first entry in the list.
	*/
	ItemType getFirst(1);
	
	/**
	gets the entry at the end of the list
	@return	the ItemType value of the last entry in the list.
	*/
	ItemType getLast(getLength());
};

#endif