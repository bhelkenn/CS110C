/**
	@file	SpinningWheel.cpp
	SpinningWheel class implementation file
	@author Brady Helkenn
	@date	10/16/2014
*/
#include<iostream>
#include"SpinningWheel.h"
#include"Node_template.h"
using namespace std;

SpinningWheel::SpinningWheel(int size)
{
	wheelSize = size;
	spinCount = 0;
	points = 0;
	
	//create the first loop
	startingPtr = new Node<int>((rand() % 20 + 1) * 5);
	
	//used for spinning later
	ptr = startingPtr;
	
	//establish current node for the following loop as the starting node
	curPtr = startingPtr;
	
	//create remaining nodes and link each to its previous node
	for (int i = 1; i < wheelSize; i++)
	{
		Node<int>* newPtr = new Node<int>((rand() % 20 + 1) * 5); //create new node...
		curPtr->setNext(newPtr); //...and link previous node to new node...
		curPtr = newPtr; //...and update current node to the new node
	}
	
	//set final node to point to starting node, completing the circle
	curPtr->setNext(startingPtr);
}
SpinningWheel::~SpinningWheel()
{
	//set curPtr to 2nd node to allow while loop to begin
	curPtr = startingPtr->getNext();
	
	//return memory of nodes to system throughout the chain, ending right before startingPtr
	while (curPtr != startingPtr)
	{
		Node<int>* nodeToDeletePtr = curPtr; //create nodeToDeletePtr and place it at curPtr...
		curPtr = curPtr->getNext(); //...move curPtr to next node...
		delete nodeToDeletePtr; //...and returns memory of target node to system.
		//no need to do anything else to nodeToDeletePtr, since it falls out of scope upon ending each loop iteration
	}
	//return starting node (should also be the only one left) to system
	delete curPtr;
	
	//cleans up pointers
	curPtr = nullptr;
	startingPtr = nullptr;
	ptr = nullptr;
}
int SpinningWheel::spin()
{
	spinCount++;
	cout << "Spin " << spinCount << ":" << endl;
	int spinStrength = rand() % wheelSize + wheelSize;
	
	//displays all values except the one landed on
	for (int i = 0; i < spinStrength; i++)
	{
		if (i % wheelSize == 0)
			cout << endl;
		cout << ptr->getItem() << " ";
		ptr = ptr->getNext();
	}
	//displays the last value spin to
	cout << ptr->getItem();
	
	//adds to points and return
	return points += ptr->getItem();
}