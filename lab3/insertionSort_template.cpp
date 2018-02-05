/**
	@file	insertionSort_template.cpp
	sorts the items in an array into ascending order.
	@author Brady Helkenn
	@date	11/09/2014
*/

/**
	@post	indexArray is sorted such that its values represent items' indices in ascending order
			items is unchanged
			size is unchanged
	@param	items = The given array
	@param	indexArray = The array containing indices for items values
	@param	size = The size of items and indexArray
*/
template<class ItemType>
void insertionSort(const ItemType *items, int *indexArray, int size)
{
	for (int i = 1; i < size; i++)
	{
		int target = i;
		while (target > 0 && items[indexArray[target - 1]] > items[i])
		{
			indexArray[target] = indexArray[target - 1];
			target--;
		}
		indexArray[target] = i;
	}
}