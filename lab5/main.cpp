/**
	@file	main.cpp
	program file for testing BinaryTree class
	@author	Brady Helkenn
	@date	12/08/2014
*/

#include"BinaryTree.cpp"
#include<iostream>
using namespace std;

int main()
{
	//creates binary tree
	BinaryTree<int> tempbt40(40);
	tempbt40.attachLeft(30);
	tempbt40.attachRight(50);
	BinaryTree<int> tempbt20(20);
	tempbt20.attachLeft(10);
	tempbt20.attachRightSubtree(tempbt40);
	BinaryTree<int> bt(60);
	bt.attachLeftSubtree(tempbt20);
	bt.attachRight(70);
	
	//cleans up temp trees
	tempbt20.~BinaryTree();
	tempbt40.~BinaryTree();
	
	//creates max and sum variables
	int max = 0;
	int sum = 0;
	
	//passes max into findMax to modify it to contain the true max value of bt
	bt.findMax(max);
	//passes sum into findSum to modify it to contain the sum of all values in bt
	bt.findSum(sum);
	
	//display results
	cout << "The max value within the tree is: " << max << endl;
	cout << "The sum of all values within the tree is: " << sum << endl;
	
	return 0;
}