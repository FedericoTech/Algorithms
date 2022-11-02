/**
 * Searching and Ordered List
 *
 * searching for an item in an ordered list
 * this technique uses a binary search
 */

#include <iostream>

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
int binarySerach(const T &item, const T * const itemList, const size_t &size)
{
	//get the list size
	size_t listsize = size - 1;

	//start at the two ends of the list
	size_t lowerIdx = 0;
	size_t upperIdx = listsize;

	while(lowerIdx <= upperIdx){
		//TODO: calculate the middle point
		size_t midPt = (lowerIdx + upperIdx) / 2;

		//TODO: if item is found, return the index
		if(itemList[midPt] == item){
			return midPt;
		}

		//TODO: otherwise get the next midpoint
		if(item > itemList[midPt]){
			lowerIdx = midPt + 1;
		} else {
			lowerIdx = midPt -1;
		}
	}

	if(lowerIdx > upperIdx){
		return -1;
	}

	return -1;
}


int main()
{
	int items[] = {6, 8, 19, 20, 23, 41, 49, 53, 56, 87};
	size_t size = sizeof items / sizeof items[0];

	std::cout << binarySerach(23, items, size) << '\n';
	std::cout << binarySerach(87, items, size) << '\n';
	std::cout << binarySerach(250, items, size) << '\n';

	return 0;
}
