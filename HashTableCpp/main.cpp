
/**
 * Hash Tables
 * - Key-to-value mapping are unique
 * - Hash tables are typically very fast
 * - For small datasets, arrays are usually more efficient
 * - Hash tables don't order entries in a predictable way
 */

#include <map>
#include <iostream>

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
	//demonstrate hashtable usage

	//TODO: create hashtable all at once.

	MyHashTable<std::string, int> items1 = {{"key1", 1}, {"key2", 2}, {"key3", 3}, {"key4", 4}};

	std::cout << items1;

	//TODO: create a hashtable progressively

	MyHashTable<std::string, int> items2;
	items2["key1"] = 1;
	items2["key2"] = 2;
	items2["key3"] = 3;

	std::cout << items2;


	//TODO: try to access a nonexistent key

	try{
		std::cout << items2.at("key6") << '\n';
	} catch(std::exception &e) {
		std::cout << "Exception: " << e.what() << '\n';
	}

	std::cout << items2["key6"] << '\n';

	std::cout << items2;

	//TODO: replace an item

	items2["key2"] = 8;

	std::cout << items2["key2"] << '\n';

	std::cout << items2;

	//TODO: iterate the keys and values in the dictionary

	for (auto entry : items2) {
		std::cout << "Key: " << entry.first << " value: " << entry.second << '\n';
	}


	return 0;
}
