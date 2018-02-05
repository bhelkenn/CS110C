/**
	@file avgOfArray_template.cpp
	template file for calculating the average of any input array
	@author Brady Helkenn
	@date 10/13/2014
*/

/**
	avgOfArray() takes in an array by reference and returns the average
	@param	a = array of ItemType variables that is passed by reference
	@param	size = integer length of a
	@pre	a is passed by reference
	@pre	size > 0
	@post	size remains unchanged
	@post	a remains unchanged
*/
template<class ItemType>
ItemType avgOfArray(const ItemType a[], int size) {
	ItemType average = 0;
	for (int i = 0; i < size; i++) {
		average += a[i];
	}
	average /= size;
	
	return average;
}