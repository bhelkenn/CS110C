/**
	@file	p.140, 1.cpp
	has statements to create a linked chain in order of "A" -> "B" -> "C":
		a) first put in "C", then insert "B" in front of it, then insert "A" in front of "B"
		b) first put in "A", then insert "B" after it, then insert "C" after "B"
	@author Brady Helkenn
	@date 10/15/2014
*/

//a)
//create "C" and link headPtr to "C"
Node<string>* newNodePtr = new Node<string>("C");
Node<string>* headPtr = newNodePtr;
//create "B", link "B" to "C", then link headPtr to "B"
newNodePtr = new Node<string>("B");
newNodePtr->setNext(headPtr);
headPtr = newNodePtr;
//create "A", link "A" to "B", then link headPtr to "A"
newNodePtr = new Node<string>("A");
newNodePtr->setNext(headPtr);
headPtr = newNodePtr;

//b)
//create "A" and link headPtr to "A"
Node<string>* curPtr = new Node<string>("A");
Node<string>* headPtr = curPtr;
//create "B" and link "A" to "B"
Node<string>* newNodePtr = new Node<string>("B");
curPtr->setNext(newNodePtr);
//create "C" and link "B" to "C"
newNodePtr = new Node<string>("C");
curPtr->setNext(newNodePtr);