/**
	@file	Node_template.h
	Node class template header file
	@author	Brady Helkenn
	@date	10/14/2014
*/
using namespace std;

#ifndef NODE_TEMPLATE_H
#define NODE_TEMPLATE_H

template<class ItemType>
class Node
{
private: 
	ItemType item; // A data item
	Node<ItemType>* next; // Pointer to next node
public: 
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};

#endif