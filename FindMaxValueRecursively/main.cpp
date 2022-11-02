/**
 * use a recursive algorithm to find a maximum value
 */


#include <iostream>

int find_max(const int * const items, const size_t &size)
{
	//TODO: breaking condition: last item in list? return it
	if(size == 1){
		return items[0];
	}

	//TODO: otherwise get the first item and call function
	//again to operate on the rest of the list
	int op1 = items[0];

	int aux[size -1];
	std::copy(&items[1], &items[size], aux);

	int op2 = find_max(aux, size - 1);

	//TODO: perform the comparison when we're down to just two
	return op1 > op2 ? op1 : op2;
};

int main()
{
	int items[] = {6, 20, 8, 19, 19, 56, 23, 87, 41, 49, 53};
	size_t size = sizeof items / sizeof items[0];

	std::cout << find_max(items, size);

	return 0;
}
