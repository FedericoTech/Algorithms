/**
 * searching for an item in an unordered list
 * sometimes called a linear search
 *
 * O(n)
 */

#include <iostream>

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
int find_item(const T &item, const T * const itemList, size_t &size)
{
	for(size_t i = 0; i < size; i++) {
		if(item == itemList[i]){
			return i;
		}
	}
	return -1;
}

int main()
{
	// declare a list of values to operate on
	int items[] = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};
	size_t size = sizeof items / sizeof items[0];

	std::cout << find_item(87, items, size) << '\n';
	std::cout << find_item(250, items, size) << '\n';

	return 0;
}
