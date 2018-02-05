#include<iostream>
using namespace std;

/**	@file p.52, fact().cpp
	writes and tests factorial recursive function
	@author Brady Helkenn
	@date 10/13/2014
*/

/**
	fact() takes any positive integer and returns the factorial of that number
	@param	n = any positive integer to take the factorial of
	@post	n remains unchanged
	@return n! (n factorial)
	@return -1 if (n < 0) to declare invalid use of the program
*/

int fact(int n) {
	if (n == 0)
		return 1;
	else if (n < 0)
		return -1;
	else
		return n * fact(n - 1);
}

int main() {
	cout << "Enter a positive integer: ";
	int n;
	cin >> n;
	int fact = fact(n);
	if (fact == -1) {
		cout << "You entered a negative number!" << endl;
		cin >> fact;
	}
	else
		cout << "fact(" << n << ") == " << fact << endl;
		
	return 0;
}