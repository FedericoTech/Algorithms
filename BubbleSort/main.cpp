
/*
 * Very simple to understand and implement
 *
 * Performance: O(n^2)
 * 	- for loops inside of for loops are usually n^2
 *
 * Other sorting algorithms are generally much better
 *
 * Not considered to be a practical solution
 */

#include <iostream>
#include <type_traits>

//Bubble sort algorithm

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void bubbleSort(T *dataset, const size_t &size)
{
	//TODO: start with the array length and decrement each time
	for(size_t i = 0; i < size; i++){
		for(size_t j = 0; j < size - i - 1; j++){
			if(dataset[j] > dataset[j+1]){
				T temp = dataset[j];
				dataset[j] = dataset[j + 1];
				dataset[j+1] = temp;
			}
		}

		//to see how it performs
		for(size_t j = 0; j < size; j++){
			std::cout << dataset[j] << ' ';
		}
		std::cout << '\n';
	}
};

int main()
{
	//int list1[] = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};
	float list1[] = {87, 56, 53, 49, 41, 23, 20, 19, 8, 6};

	//std::string list1[] = {"87", "56", "53", "49", "41", "23", "20", "19", "8", "6"};

	size_t num_elements = sizeof list1 / sizeof list1[0];

	bubbleSort(list1, num_elements);

	for(auto n: list1){
		std::cout << n << '\n';
	}

	return 0;
}
