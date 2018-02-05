/**
	@file	LinkedScroll.h
	ADT scroll: Link-based implementation.
	@author	Brady Helkenn
	@date	11/24/2014
*/

#include"LinkedQueue.h"

#ifndef LINKEDSCROLL_H
#define LINKEDSCROLL_H

template<class ItemType>
class LinkedScroll: public LinkedQueue<ItemType>
{
public:
	bool removeLast();
};

#endif