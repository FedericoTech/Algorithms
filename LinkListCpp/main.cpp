#include <iostream>

//Linked list example

class Node
{
public:
	Node(int val):next{nullptr}, val{val}{}

	int get_data(){ return val; }

	void set_data(int val) { this->val = val; }

	Node *get_next(){ return next; }

	void set_next(Node *next){ this->next = next; }

private:
	Node *next;
	int val;
};

class LinkedList
{
public:
	LinkedList(Node *head = nullptr): head(head){}

	int get_count(){ return count; }

	void insert(int data)
	{
		Node *new_node = new Node(data);
		new_node->set_next(head);
		head = new_node;
		++count;
	}

	Node *find(int val)
	{
		Node *tempnode = head;

		while(tempnode && tempnode->get_data() != val){
			tempnode = tempnode->get_next();
		}

		return tempnode;
	}

	void deleteAt(int indx)
	{
		if(indx > count - 1) { return; }

		if(indx == 0){
			Node *aux = head->get_next();
			delete head;
			head = aux;
		} else {
			int tempInx = 0;
			Node *temp = head;
			while(tempInx++ < indx -1){
				temp = temp->get_next();
			}
			Node *deletee = temp->get_next();
			temp->set_next(temp->get_next()->get_next());
			delete deletee;
			--count;
		}
	}

	friend std::ostream& operator<<(std::ostream &, const LinkedList &);

	~LinkedList() {
		Node *current = head;
		while(current){
			Node *next = current->get_next();
			delete current;
			current = next;
		}
	}
private:
	Node *head;
	int count = 0;
};

std::ostream&  operator<<(std::ostream &o, const LinkedList &ll)
{
	Node *tempnode = ll.head;
	while(tempnode){
		o << "Node: " << tempnode->get_data() << '\n';
		tempnode = tempnode->get_next();
	}

	return o;
}


int main()
{
	//create a linked list and insert some items
	LinkedList itemList;
	itemList.insert(38);
	itemList.insert(49);
	itemList.insert(13);
	itemList.insert(15); //this is now the head.

	std::cout << itemList;

	/*
	std::cout << "Item count: " << itemList.get_count() << '\n';
	std::cout << "Finding item: " << itemList.find(13) << '\n';
	std::cout << "finding item: " << itemList.find(78);
	*/

	itemList.deleteAt(3);
	std::cout << "Item count: " << itemList.get_count() << '\n';
	std::cout << "Finding item: " << itemList.find(38) << '\n';

	std::cout << itemList;
}

