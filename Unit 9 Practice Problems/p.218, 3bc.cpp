/*
Suppose that you have a stack aStack and an empty auxiliary stack auxStack. Show how you can do each of the following 
tasks by using only the ADT stack operations.
	b. Count the number of items in aStack, leaving aStack unchanged.
		NOTE: it is okay to change the stack between the beginning and end of the function, as long as the stack is 
		in its original state at the end of the function.
	c. Delete every occurrence of a specified item from aStack, leaving the order of the remaining items unchanged.
*/
using namespace std;

//(b)
//size will contain the number of items in aStack
int size = 0;

//auxStack will be an inverted form of aStack i.e. first last item pushed will be the first item of aStack
while (!aStack.isEmpty())
{
	auxStack.push(aStack.peek());
	aStack.pop();
	size++;
}

//restores aStack and auxStack to original states
while (!auxStack.isEmpty())
{
	aStack.push(auxStack.peek());
	auxStack.pop();
}

cout << "The number of items in aStack is: " << size << endl;

//(c)
//assuming target is populated accordingly
//ItemType target = something;

//auxStack will be an inverted form of aStack i.e. first last item pushed will be the first item of aStack
//of course, it will also be adjusted with only the desired entries
while (!aStack.isEmpty())
{
	//if the value is allowable, moves to auxStack
	if (aStack.peek() != target)
		auxStack.push(aStack.peek());
	//regardless, the value should be popped off aStack
	aStack.pop();
}

//now that only the allowed values are in auxStack, moves them back to aStack
while (!auxStack.isEmpty())
{
	aStack.push(auxStack.peek());
	auxStack.pop();
}