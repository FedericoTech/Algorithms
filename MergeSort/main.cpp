/*
 * - Divide-and-conqer algorithm
 * - Breaks a dataset into individual pieces and merges them
 * - Uses recursion to operate on datasets
 * - Performs well on large sets of data.
 * - In general has a performance of O(n log n) time complexity
 *
 *
 */

#include<iostream>

template<typename T>
void print_array(T * const dataset, const size_t &size)
{
	const T *iter = dataset, *end = dataset + size;
	while(iter != end){
		std::cout << *iter++ << ' ';
	}
	std::cout << std::endl;
}

template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
void mergesort(T * const dataset, const size_t &size)
{
	if(size > 1){
		size_t mid_l = size / 2;
		size_t mid_r = size - mid_l;
		T leftarr[mid_l];
		T rightarr[mid_r];

		std::copy(dataset, dataset + mid_l, leftarr);
		std::copy(dataset + mid_l, dataset + size, rightarr);

		//print_array(leftarr, mid_l);
		//print_array(rightarr, mid_r);

		//TODO: recursively break down the arrays
		mergesort(leftarr, mid_l);
		mergesort(rightarr, mid_r);

		//TODO: now perform the merging

		size_t i = 0; //index into the left array
		size_t j = 0; //index into the right array
		size_t k = 0; //index into the merged array

		//TODO: while both arrays have content

		while(i < mid_l && j < mid_r) {
			if(leftarr[i] < rightarr[j]){
				dataset[k++] = leftarr[i++];
			} else {
				dataset[k++] = rightarr[j++];
			}
		}

		//TODO: if the left array still has values, add them
		while(i < mid_l){
			dataset[k++] = leftarr[i++];
		}


		//TODO: if the right array still has values, add them
		while(j < mid_r){
			dataset[k++] = rightarr[j++];
		}
	}
}

int main()
{
	float items[] = {6, 20, 8, 19, 56, 23, 87, 41, 49.7f, 53, 12};
	size_t size = sizeof items / sizeof items[0];

	std::cout << "before\n";

	print_array(items, size);

	//std::cout << "during\n";

	mergesort(items, size);

	std::cout << "after\n";

	print_array(items, size);

	return 0;
}
