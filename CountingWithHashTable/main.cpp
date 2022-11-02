/**
 * Using a hashtable to count individual items
 */

#include <iostream>
#include <map>


template<typename T, typename U>
class MyHashTable: public std::map<T, U> {

public:
	MyHashTable():std::map<T, U>() {};

	MyHashTable(std::initializer_list<std::pair<const T, U>> list):std::map<T, U>(list){};

	template<typename V, typename W>
	friend std::ostream &operator << (std::ostream &, const MyHashTable<U, W> &);
};

template<typename T, typename U>
std::ostream &operator<<  (std::ostream &o, const MyHashTable<T, U> &ms)
{
	o << '{';

	bool f = false;
	for (auto entry : ms) {
		if(f) { o << ','; };
		o << "'" << entry.first << "': " << entry.second;
		f = true;
	}
	o << "}\n";

	return o;
}


int main()
{

	//define a set of items that we want to reduce duplicates
	std::string items[] = {
		"apple", "pear", "orange", "banana", "apple",
		"orange", "apple", "pear", "banana", "orange",
		"apple", "kiwi", "pear", "apple", "orange"
	};

	//TODO: create a hashtable object to hold the items and counts
	MyHashTable<std::string, int> counter;

	//TODO: iterate over each item and increment the count for each one
	for(std::string item: items){
		//if the key isn't contained in the hashtable...
		if(counter.find(item) == counter.end()){
			counter[item] = 1;
		//if it is...
		} else {
			counter[item]++;
		}
	}

	//TODO: print the results
	std::cout << counter;

	return 0;
}
