/**
	@file	main.cpp
	Main program file
	@author	Brady Helkenn
	@date	11/24/2014
*/

#include<iostream>
#include<string>
#include"LinkedScroll.cpp"
#include"LinkedQueue.cpp"
#include"Node.cpp"
using namespace std;

int main()
{
	cout << "Instruction maintenance program" << endl << endl;
	
	LinkedScroll<string> ls;
	
	//uses to determine if ***instructions*** should display (only if true)
	bool displayInstructions = false;
		
	int choice = 0;
	while (choice != 3)
	{
		cout << "1) Enter instruction" << endl;
		cout << "2) Undo last instruction" << endl;
		cout << "3) Quit" << endl;
		cout << "Enter choice: ";
		
		//user input variables
		string instruction;
		cin >> choice;
		cin.ignore();
		
		switch (choice)
		{
			case 1:
				cout << "Enter instruction: ";
				getline(cin, instruction);
				ls.enqueue(instruction);
				displayInstructions = true;
				break;
			case 2:
				//if removeLast returns false, it's because ls is already empty
				if (!ls.removeLast())
					cout << "There are no instructions to undo" << endl;
				break;
			case 3:
				break;
			default:
				break;
		}
		//iterates through if Quit wasn't invoked
		if (choice != 3)
		{
			//special case: if nothing was ever enqueued, do not display anything
			if (!displayInstructions)
			{
			}
			//something has been enqueued in the past, therefore display ***instructions***
			else
			{
				cout << "***Instructions***" << endl;
				//if this has now been emptied, display the special banner as shown in lab doc
				if (ls.isEmpty())
					cout << "***There are no instructions at this time***" << endl;
				else
				{
					//creates temp scroll
					LinkedScroll<string> auxScroll;
					//clears out ls and enqueues into auxScroll
					while (!ls.isEmpty())
					{
						//enqueue front item of ls to auxScroll (this preserves order)
						auxScroll.enqueue(ls.peekFront());
						//dequeue from ls to get next item as "front"
						ls.dequeue();
					}
					//moves values back and prints out values during the process
					while (!auxScroll.isEmpty())
					{
						//displays the instruction
						cout << auxScroll.peekFront() << endl;
						//enqueue front item of auxScroll to ls (this preserves order)
						ls.enqueue(auxScroll.peekFront());
						//dequeue from auxScroll to get next item as "front"
						auxScroll.dequeue();
					}
				}
			}
		}
		//extra whitespace for display
		cout << endl;
	}
	return 0;
}