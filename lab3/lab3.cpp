/**
	@file	lab3.cpp
	main program file to implement indirect sorting on an array loaded from a file
	@author	Brady Helkenn
	@date	11/09/2014
*/
#include<iostream>
#include<string>
#include<fstream>
#include"insertionSort_template.cpp"
using namespace std;

int main()
{
	const int SIZE = 10;
	
	string unsortedArray[SIZE];
	int indexArray[SIZE];
	fstream file;
	
	//populate unsortedArray from file
	//User input MUST BE 'cities.dat', otherwise the program will not work correctly
	string filename;
	cout << "Enter name of file: ";
	getline(cin, filename);
	file.open("cities.dat");
	for (int i = 0; i < SIZE; i++) {
		getline(file, unsortedArray[i]);
	}
	file.close();
	
	//populate indexArray
	for (int i = 0; i < SIZE; i++)
	{
		indexArray[i] = i;
	}
	
	//sort indexArray
	insertionSort<string>(unsortedArray, indexArray, SIZE);
	
	//display unsortedArray as proof it was untouched
	cout << "Unsorted data:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << unsortedArray[i] << endl;
	}
	
	//display unsortedArray using index values from indexArray as proof of "sorting"
	cout << "\nSorted data:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << unsortedArray[indexArray[i]] << endl;
	}
	
	//display indexArray values as further evidence that unsortedArray was untouched
	cout << "\nContents of index array:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << indexArray[i] << endl;
	}
	
	return 0;
}
