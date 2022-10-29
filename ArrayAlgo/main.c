#include <stdio.h>
#include <inttypes.h>

/**
 * Array Operations
 *
 * - Calculate item index: O(1)
 * - Insert or delete item at beginning: O(n)
 * - Insert or delete item in middle: O(n)
 * - Insert or delete item at the end: O(1)
 */

void list_values(int *arr, size_t n)
{
	size_t i;
	//we list the original elements
	for(i = 0; i < n; i++){
		printf("LA[%I64u] = %d \n", i, arr[i]);
	}
}

void update_array(int *arr, size_t *n, size_t k, int item)
{
	int j = *n;

	while(j-- >= k) //whilst we don't reach the desired index from the top...
	{
		arr[j + 1] = arr[j]; //we move the element on position up
	}

	arr[k] = item;   //now we set the value in the position we wanted.
	++(*n);
}

size_t search_element(int *arr, size_t n, int item)
{
	size_t j = 0;
	while(j++ < n){
		if(arr[j] == item) {
			break;
		}
	}

	return j;
}

void delete_element(int *arr, size_t *n, size_t k)
{
	size_t j = k;

	while(j++ < *n) {
	   arr[j-1] = arr[j];
	}

   --(*n);
}

int main() {
	int LA[] = {1,3,5,7,8};	//array with 5 elements
	size_t n = 5;			//num of elements in array

	//we list the original elements
	list_values(LA, n);

	//we update the item 3 with the value 10
	update_array(LA, &n, 3, 10);

	//now we list all the elements again
	printf("The array elements after insertion: \n");
	list_values(LA, n);

	//now we search an item
	printf(
		"Found element %d at position %I64u\n",
		10,
		search_element(LA, n, 10)
	);

	//now we delete an element
	delete_element(LA, &n, 3);

	//now we list all the elements again
	printf("The array elements after deletion: \n");
	list_values(LA, n);

	return 0;
}
