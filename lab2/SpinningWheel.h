/**
	@file	SpinningWheel.h
	SpinningWheel class header file
	@author Brady Helkenn
	@date	10/16/2014
*/
#include"Node_template.cpp"
using namespace std;

#ifndef SPINNINGWHEEL_H
#define SPINNINGWHEEL_H

/**
	@param	startingPtr = initial node pointer
	@param	curPtr = pointer to track new nodes and to link them to previous ones
	@param	ptr = pointer to track position on the wheel during spins
	@param	wheelSize = determins the size of the wheel (how many nodes are in it)
	@param	spinCount = tracks the number of spins made
	@param	points = tracks the accumulated number of points earned from previous spins
*/
class SpinningWheel
{
private:
	Node<int>* startingPtr;
	Node<int>* curPtr;
	Node<int>* ptr;
	int wheelSize;
	int spinCount;
	int points;
public:
	SpinningWheel(int);
	~SpinningWheel();
	int spin();
};

#endif