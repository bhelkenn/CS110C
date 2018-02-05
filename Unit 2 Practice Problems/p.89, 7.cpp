#include<iostream>
using namespace std;

/**	@file p.89, 7.cpp
	writes and tests numCount recursive function
	@author Brady Helkenn
	@date 10/11/2014
*/

/**
	numCount takes any positive integer and counts to it from one, inclusively
	@param	n = any positive integer that the recursive call ends at
	@pre	n > 0;
	@post	n remains unchanged
*/
void numCount(int n) {
	if (n == 1)
		cout << n << " ";
	else {
		numCount(n - 1);
		cout << n << " ";
	}
}

int main() {
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;
	numCount(n);
	cin >> n;
	return 0;
}