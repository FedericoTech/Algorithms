#include "ArrayLib/ArrayLib.h"
#include <stdio.h>

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
