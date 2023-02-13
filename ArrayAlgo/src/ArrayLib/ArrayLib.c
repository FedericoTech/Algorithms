
#include "ArrayLib.h"
#include <stdio.h>

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

	while(j-- >= k){ //whilst we don't reach the desired index from the top...
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
