
#include <stdio.h>
#include <stdlib.h>

struct Link {
	int value;
	struct Link *next;
};

struct Link* head;

struct Link* create_link(int value)
{
	struct Link* aux = (struct Link *) malloc(sizeof(struct Link));
	aux->value = value;
	aux->next = NULL;

	return aux;
}

//we are passing the pointer to the pointer of the head
struct Link *push_last(struct Link **head, int value)
{
	if(*head == NULL){
		//so that if it doesn't exist we can create it right on the spot.
		*head = create_link(value);
		return *head;
	}

	struct Link *current = *head;

	//we look for the last element
	while(current->next != NULL){
		current = current->next;
	}

	current->next = create_link(value); //now the last points to the new one.
	return current;
}

//we are passing the pointer to the pointer of the head
struct Link *push_first(struct Link **head, int value)
{
	if(*head == NULL){
		//so that if it doesn't exist we can create it right on the spot.
		*head = create_link(value);
		return *head;
	}

	struct Link *new = create_link(value);
	new->next = *head;
	*head = new; //we replace the head
	return *head;
}

struct Link *search_element(struct Link *head, size_t index)
{
	if(head == NULL){
		return NULL; //index not found
	}

	size_t i = 0;
	struct Link *current = head;

	//we look for the index
	while(current->next != NULL && i != index){
		current = current->next;
		++i;
	}
	//if we didn't reach the index
	if(i != index){
		return NULL; //index not found
	}

	return current;
}

struct Link *insert_element(struct Link *head, size_t index, int value)
{
	struct Link *current = search_element(head, index);

	if(current == NULL){
		return NULL; //index not found
	}

	struct Link *new = create_link(value);

	//if the current is not the last
	if(current->next != NULL){
		new->next = current->next;
	}

	current->next = new;

	return new;
}

int remove_element(struct Link **head, size_t index)
{
	struct Link *current;
	if(index > 0){
		//we take the one before
		current = search_element(*head, index - 1);

		if(current == NULL || current->next == NULL){
			return -1;
		}

		struct Link *next = current->next->next;
		free(current->next);
		current->next = next;
		int value = current->next->value;

		return value;
	}

	if(*head == NULL){
		return -1;
	}


	current = *head;

	int value = current->value;
	*head = current->next;
	free(current);
	return value;
}

int count_elements(struct Link *head)
{
	if(head == NULL){
		return 0;
	}

	struct Link *current = head;
	int i = 1;

	while(current->next != NULL){
		++i;
		current = current->next;
	}

	return i;
}

void print_elements(struct Link *head)
{

	if(head == NULL){
		return;
	}

	struct Link *current = head;

	do {
		printf("%d\n", current->value);
		current = current->next;
	} while(current != NULL);
}

void delete_all_elements(struct Link **head)
{
	if(*head == NULL){
		return;
	}

	if((*head)->next != NULL){
		delete_all_elements(&(*head)->next);
	}
	free(*head);
	*head = NULL;
}

void reverse_list(struct Link **head)
{
	struct Link* prev   = NULL;
	struct Link* current = *head;
	struct Link* next;
	while (current != NULL)
	{
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}


int main()
{
	head = create_link(1);

	push_last(&head, 2);

	push_first(&head, 3);

	insert_element(head, 0, 4);

	remove_element(&head, 1);

	print_elements(head);

	printf(
		"\nthe element:%d is: %d\n",
		0,
		search_element(head, 0)->value
	);

	printf("there are %d elements\n", count_elements(head));

	printf("reversing list\n");

	reverse_list(&head);

	print_elements(head);

	printf("deleting list\n");

	delete_all_elements(&head);

	printf("after deletion there are %d elements\n", count_elements(head));

	printf("done\n");

	return 0;

}

