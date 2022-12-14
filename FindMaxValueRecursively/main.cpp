/**
 * use a recursive algorithm to find a maximum value
 * O(n)
 */


#include <iostream>

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
T find_max(const T * const items, const size_t &size)
{
	//TODO: breaking condition: last item in list? return it
	if(size == 1){
		return items[0];
	}

	//TODO: otherwise get the first item and call function
	//again to operate on the rest of the list
	T op1 = items[0];

	T aux[size -1];
	std::copy(&items[1], &items[size], aux);

	T op2 = find_max(aux, size - 1);

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
