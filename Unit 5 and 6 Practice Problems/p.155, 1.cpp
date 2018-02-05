/** @file	p.155, 1.cpp
	contains C++ statements such that, given headPtr is pointed to the first node in a 2-node linked chain,
	the 2nd node is deleted and returned to the system.
	@author Brady Helkenn
	@date 10/14/2014
*/

Node<ItemType>* targetPtr = headPtr->getNext();
headPtr->setNext(targetPtr->getNext()); //should translate to nullptr
delete targetPtr; //deletes the content of the node targetPtr points to
targetPtr = nullptr; //points targetPtr to nullptr, which cleans up the pointer