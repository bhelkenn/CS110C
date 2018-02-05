#include<iostream>
using namespace std;
/**	@file lab1.cpp
	writes and tests displayBase free function
	@author Brady Helkenn
	@date 10/07/2014
*/

/**
	displayBase takes any positive integer and returns a representation of that integer in a different base
	@param	n = any integer to be restructured and returned in a different base
	@param	base = any integer representing the new base of the returned value
	@pre	n >= 0;
	@pre	base > 0;
	@post	base remains unchanged
	@return	returns n in altered base form
*/
int displayBase(int n, int base)
{
	if (n < base)
		return n;
	else
		return n % base + displayBase(n / base, base) * 10;
}

int main()
{
	int n = 0;
	int base = 0;
	while (n != -1)
	{
		cout << "Enter a positive integer to convert (enter -1 to exit): ";
		cin >> n;
		//putting an if condition here, since if -1 is input I don't want to bother with the rest and 
		//instead finish the while loop and exit program
		if (n != -1)
		{
			cout << "Enter the new base: ";
			cin >> base;
			cout << n << " base 10 is " << displayBase(n, base) << " base " << base << endl << endl;
		}
	}
	return 0;
}