/**
 * determina if a list is sorted
 * O(n)
 */

#include <iostream>
#include <algorithm>

namespace FedericoTech {
	template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
	bool is_sorted(const T * const itemList, const size_t &size)
	{
		//TODO: using brute force method
		for(size_t i = 0; i < size - 1; i++){
			if(itemList[i] > itemList[i + 1]){
				return false;
			}
		}
		return true;
	}
}

int main()
{
	int items1[] = {6, 8, 19, 20, 23, 41, 49, 53, 56, 87};
	int items2[] = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};

	size_t size = sizeof items1 / sizeof items1[0];

	//our implementation
	std::cout << "our implementation\n";
	std::cout << FedericoTech::is_sorted(items1, size) << '\n';
	std::cout << FedericoTech::is_sorted(items2, size) << '\n';

	//STL implementation
	std::cout << "STL implementation\n";
	std::cout << std::is_sorted(std::begin(items1), std::end(items1)) << '\n';
	std::cout << std::is_sorted(std::begin(items2), std::end(items2));
	return 0;
}
