
/**
 * The Quicksort
 *
 * - Divide-and-conquer algorithm, like the merge sort.
 * - Also uses recursion to perform sorting.
 * - Generally performs better than merge sort, O(n log n)
 * - Operates in place on the data (not need for extra memory)
 * - Worst case is O(n^2) when data is mostly sorted already
 *
 *
 */

#include<iostream>

template<typename T>
void print_array(T * const dataset, const size_t &size)
{
	const T * iter = dataset, *end = dataset + size;
	while(iter != end){
		std::cout << *iter++ << ' ';
	}
	std::cout << std::endl;
}

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
size_t partition(T * const datavalues, const size_t &size, size_t first, size_t last)
{
	// choose the first item as the pivot value
	T pivotvalue = datavalues[first];
	// establish the upper and lower indexes
	size_t lower = first + 1;
	size_t upper = last;

	//start searching for the crossing point
	while(true){
		//TODO: advance the lower index
		while(lower <= upper && datavalues[lower] <= pivotvalue){
			++lower;
		}

		//TODO: advance the upper index
		while(upper >= lower && datavalues[upper] >= pivotvalue){
			--upper;
		}
		//TODO: if the two indexes cross, we have found the split point
		if(upper < lower){
			break;
		}

		std::swap(datavalues[upper], datavalues[lower]);

	}

	//when the split point is found, exchange the pivot value
	std::swap(datavalues[upper], datavalues[first]);

	// return the split point index
	return upper;
}

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void quickSort(T * const dataset, const size_t &size, const size_t &first, const size_t &last)
{
	if(first < last){
		// calculate the split point
		size_t pivotIdx = partition(dataset, size, first, last);

		quickSort(dataset, size, first, pivotIdx - 1);
		quickSort(dataset, size, pivotIdx + 1, last);
	}
}




int main()
{
	float items[] = {20, 6, 8, 53, 56, 23, 87, 41, 49, 19};
	size_t size = sizeof items / sizeof items[0];

	print_array(items, size);

	quickSort(items, size, 0, size - 1);

	print_array(items, size);

	return 0;
}
