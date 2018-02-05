/*
If you use a circular array to implement a queue, you must be able to distinguish between the queue-full and 
queue-empty conditions. You can make this distinction by counting the number of items in the queue, using a 
boolean variable isFull, or leaving one array location empty.
*/

//in situations where back catches up to front
if (back == front - 1)
{
	if (count == 0)
		//isEmpty
	else if (count == MAX_COUNT)
		//isFull
}