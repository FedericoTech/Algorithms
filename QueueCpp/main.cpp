/**
 * Queue
 *
 * - Queue: collection that supports adding and removing.
 * - first item added is the first item out
 *
 * 	Usage:
 *
 * 		- Order processing
 * 		- Messaging
 */

#include <queue>
#include <iostream>

template<typename T>
class MyQueue: public std::queue<T> {

	template<typename U>
	friend std::ostream &operator << (std::ostream &, const MyQueue<U> &);
};

template<typename T>
std::ostream &operator<<  (std::ostream &o, const MyQueue<T> &ms)
{
	o << '[';

	std::queue<T> dump = ms;

	for(int i = 0; !dump.empty(); dump.pop(), i++){
		if(i) { o << ','; };
		o << dump. front();
	}
	o << "]\n";

	return o;
}

int main()
{
	// try out the c++ queue functions

	//TODO: create a new empty deque object that will function as a queue

	MyQueue<int> queue;

	//TODO: add some items to the queue

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	//TODO: print the queue contents

	std::cout << queue;

	//TODO: pop an item off the front of the queue

	std::cout << queue.front() << '\n';
	queue.pop();

	std::cout << queue;


	return 0;
}
