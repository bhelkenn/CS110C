#include<iostream>
#include<string>
using namespace std;

/**
	@file p.61, writeBackward2().cpp
	writes and tests writeBackward2 function
	@author Brady Helkenn
	@date 10/13/2014
*/

/**
	writeBackward2 takes any string and prints it out in reverse
	@param	s = string to be printed out in reverse
	@pre	s is not empty
	@post	s remains unchanged
*/
void writeBackward2(string s) {
	if (s.size() == 0)
		return;
	else {
		writeBackward2(s.substr(1, s.size()));
		cout << s[0];
		return;
	}
}

int main() {
	cout << "Enter a string to print backwards: ";
	string s;
	cin >> s;
	cout << s << " printed backwards is ";
	writeBackward2(s);
	cout << endl;
	return 0;
}