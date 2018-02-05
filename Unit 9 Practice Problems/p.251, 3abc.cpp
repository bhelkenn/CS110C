/*
An operation that displays the contents of a stack can be useful during program debugging. Add a display
method to the ADT stack such that
a. The method uses only ADT stack operations; that is, it is independent of the stack’s implementation.
b. The method assumes and uses the link-based implementation of the ADT stack.
c. The method assumes and uses the array-based implementation of the ADT stack.
NOTE: For exercises 3b and 3c, do not call any Stack member functions.
*/
#include<iostream>
using namespace std;

//(a)
template<class ItemType>
void Stack<ItemType>::displayStack()
{
	Stack<ItemType>* auxStack = new Stack();
	
	//sets up auxStack so that as it's put back to aStack, cout statements can display the stack
	while (!isEmpty())
	{
		auxStack->push(peek());
		pop();
	}
	
	cout << "aStack: ";
	//couts each element and adds it back to aStack
	while (!auxStack->isEmpty())
	{
		//prints item
		cout << auxStack->peek() << " ";
		//moves it back to aStack
		push(auxStack->peek());
		//pops from auxStack
		auxStack->pop();
	}
	//endl for better display
	cout << endl;
	
	//cleanup
	delete auxStack;
	auxStack = nullptr;
}

//(b)
template<class ItemType>
void LinkedStack<ItemType>::displayStack()
{
	//auxStack pointers
	Node<ItemType>* headPtr = nullptr;
	Node<ItemType>* endPtr = nullptr;
	
	
	//sets up auxStack so that as it's put back to aStack, cout statements can display the stack
	while (topPtr != nullptr)
	{
		//pushes peek() to auxStack
		//if auxStack is empty, populates headPtr as first item
		if (headPtr == nullptr)
		{
			headPtr = new Node<ItemType>(topPtr->getItem(), topPtr);
			endPtr = headPtr;
		}
		else
		{
			Node<ItemType>* prevPtr = endPtr;
			endPtr = new Node<ItemType>(topPtr->getItem(), topPtr);
			prevPtr->setNext(endPtr);
		}
		
		//pop
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
	}
	
	cout << "aStack: ";
	//couts each element and adds it back to aStack
	while (endPtr != nullptr)
	{
		//prints item
		cout << endPtr->getItem() << " ";
		//moves it back to aStack
		topPtr = new Node<ItemType>(endPtr->getItem(), topPtr);
		
		//pops from auxStack
		Node<ItemType>* prevPtr = headPtr;
		while (prevPtr->getNext()->getNext() != nullptr)
		{
			prevPtr = prevPtr->getNext();
		}
		prevPtr->setNext(nullptr);
		delete endPtr;
		endPtr = prevPtr;
	}
	//endl for better display
	cout << endl;
}

//(c)
template<class ItemType>
void ArrayStack<ItemType>::displayStack()
{
	cout << "aStack: ";
	//couts each element
	for (int i = 0; i < top; i++)
	{
		cout << items[i] << " ";
	}
	//endl for better display
	cout << endl;
}