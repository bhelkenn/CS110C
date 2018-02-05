#include<iostream>
using namespace std;

/**	@file p.89, 9.cpp
	writes and tests writeBackward recursive function
	@author Brady Helkenn
	@date 10/11/2014
*/

/**
	writeBackward takes any positive integer and couts it in reverse
	@param	num = any positive integer to be couted in reverse
	@pre	num > 0;
	@post	num remains unchanged
*/
void writeBackward(int num) {
	if (num == 0)
		return;
	else {
		cout << num % 10;
		writeBackward(num / 10);
	}
}

int main() {
	cout << "Input a number: ";
	int num;
	cin >> num;
	cout << "num backwards: ";
	writeBackward(num);
	cout << endl;
	cin >> num;
	return 0;
}