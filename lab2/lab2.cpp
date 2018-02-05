/**
	@file	lab2.cpp
	tests a spinning wheel game using a circular, singly linked list of nodes
	@author Brady Helkenn
	@date	10/16/2014
*/

#include<iostream>
#include<time.h> //for srand()
#include"SpinningWheel.h"
using namespace std;

int main()
{
	srand(unsigned(time(0)));
	
	SpinningWheel* wheel = new SpinningWheel(20);
	
	char spinAgain = 'y';
	while (spinAgain == 'y' || spinAgain == 'Y')
	{
		int points = wheel->spin();
		cout << "\nPoints so far: " << points << endl;
		cout << "Spin again (y/n)? ";
		cin >> spinAgain;
		
		//error checking
		while (spinAgain != 'y' && spinAgain != 'Y' && spinAgain != 'n' && spinAgain != 'N')
		{
			cout << "Invalid entry, please enter Y or N: ";
			cin >> spinAgain;
		}
	}
	
	//return memory to system and clean up the pointer
	delete wheel;
	wheel = nullptr;
	
	return 0;
}