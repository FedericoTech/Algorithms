/**
 * Stacks
 *
 * - Stack: collection that supports push and pop operations
 * - The last item pushed is the first one popped
 *
 * 	Usage:
 * 		- expression processing
 * 		- backtracking: browser back stack, for example.
 *
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

#include <stack>
#include <iostream>

template<typename T>
class MyStack: public std::stack<T> {

	template<typename U>
	friend std::ostream &operator << (std::ostream &, const MyStack<U> &);
};

template<typename T>
std::ostream &operator<<  (std::ostream &o, const MyStack<T> &ms)
{
	o << '[';

	std::stack<T> dump = ms;

	for(int i = 0; !dump.empty(); dump.pop(), i++){
		if(i) { o << ','; };
		o << dump. top();
	}
	o << "]\n";

	return o;
}



int main()
{
	// try out the Python stack functions

	// TODO: create a new empty stack
	MyStack<int> stack;

	// TODO: push items onto the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	//TODO: print the stack contents
	/*
	for(std::stack<int> dump = stack; !dump.empty(); dump.pop()){
		std::cout << dump.top() << '\n';
	}*/

	std::cout << stack;

	//TODO: pop an item off the stack
	int x = stack.top();
	stack.pop();

	std::cout << x << '\n';

	std::cout << stack;
	/*
	for(std::stack<int> dump = stack; !dump.empty(); dump.pop()){
		std::cout << dump.top() << '\n';
	}
	*/
	return 0;
}
