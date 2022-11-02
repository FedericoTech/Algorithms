/*
 * use a hashtable to filter out duplicate items
 * O(n)
 */

#include <iostream>
#include <map>
#include <set>

template<typename T>
class MySet: public std::set<T> {

public:
	MySet():std::set<T>() {};

	MySet(std::initializer_list<T> list):std::set<T>(list){};

	template<typename U>
	friend std::ostream &operator << (std::ostream &, const MySet<U> &);
};

template<typename T>
std::ostream &operator<<  (std::ostream &o, const MySet<T> &set)
{
	o << '[';

	bool f = false;
	for (auto entry : set) {
		if(f) { o << ','; };
		o << entry;
		f = true;
	}
	o << "]\n";

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

	//TODO: create a hastable to perform a filter
	std::map<std::string, int> map;

	//TODO: loop over each item and add to the hashtable
	for(auto item: items){
		map[item] = 0;
	}

	//TODO: create a set from the resulting keys in the hashtable
	MySet<std::string> set;

	for(std::map<std::string, int>::iterator i = map.begin(); i != map.end(); i++){
		set.insert(i->first);
	}

	std::cout << set << '\n';


	return 0;
}
