//Write pseudocode that merges two sorted lists into a new third sorted list by using only ADT sorted list operations.

#include"SortedListInterface.h"
using namespace std;

SortedListInterface mergedLists(SortedListInterface& sorted1, SortedListInterface& sorted2)
{
	SortedListInterface newList();
	
	int length1 = sorted1.getLength();
	for (int i = 1; i <= length1; i++)
	{
		newList.insertSorted(sorted1.getEntry(i));
	}
	
	int length2 = sorted2.getLength();
	for (int i = 1; i <= length2; i++)
	{
		newList.insertSorted(sorted2.getEntry(i));
	}
	
	//empties old lists
	sorted1.clear();
	sorted2.clear();
}