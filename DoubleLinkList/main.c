#include <stdio.h>
#include <stdlib.h>

struct DblLink {
	int value;
	struct DblLink *next;
	struct DblLink *prev;
};

struct DobleLinkList {
	struct DblLink* head;
	struct DblLink* tail;
	size_t size;
};

struct DobleLinkList *createList()
{
	struct DobleLinkList *list = (struct DobleLinkList *)malloc(sizeof(struct DobleLinkList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

struct DblLink* push_front(struct DobleLinkList *list, int value)
{
	if(list == NULL){
		return NULL;
	}

	struct DblLink *current = (struct DblLink *)malloc(sizeof(struct DblLink));
	current->value = value;
	current->prev = NULL;

	//if there is not head yet...
	if(list->head == NULL){
		current->next = NULL;
		list->head = current;
		list->tail = current; //we assume there wasn't tail either.
		list->head->next = list->tail;
		list->tail->prev = list->head;
	} else {
		list->head->prev = current;
		current->next = list->head;
		list->head = current;
	}
	++list->size;
	return current;
}

struct DblLink* push_back(struct DobleLinkList *list, int value)
{
	if(list == NULL){
		return NULL;
	}

	struct DblLink *current = (struct DblLink *)malloc(sizeof(struct DblLink));
	current->value = value;
	current->next = NULL;

	//if there is not tail yet...
	if(list->tail == NULL){
		current->next = NULL;
		list->tail = current;
		list->head = current; //we assume there wasn't tail either.
		list->tail->prev = list->head;
		list->head->next = list->tail;
	} else {
		list->tail->next = current;
		current->prev = list->tail;
		list->tail = current;
	}
	++list->size;
	return current;
}

void delete_first(struct DobleLinkList *list)
{
	if(list == NULL || list->head == NULL){
		return;
	}

	if(list->head == list->tail){
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	struct DblLink *head = list->head->next;
	free(list->head);
	head->prev = NULL;
	list->head = head;
	--list->size;
}

void delete_last(struct DobleLinkList *list)
{
	if(list == NULL || list->tail == NULL){
		return;
	}

	if(list->head == list->tail){
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	struct DblLink *tail = list->tail->prev;
	free(list->tail);
	tail->next = NULL;
	list->tail = tail;
	--list->size;
}

struct DblLink* search_element(struct DobleLinkList *list, size_t index)
{
	if(list == NULL || list->head == NULL || index > list->size){
		return NULL;
	}

	struct DblLink* current = list->head;
	for(int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

struct DblLink* insert_after(struct DobleLinkList *list, size_t index, int value)
{
	struct DblLink* current = search_element(list, index);

	if(current == NULL){
		return NULL;
	}

	struct DblLink *new = (struct DblLink *)malloc(sizeof(struct DblLink));
	new->value = value;
	new->prev = current;

	if(current != list->tail){
		new->next = current->next;
		current->next->prev = new;
	} else {
		list->tail = new;
		new->next = NULL;
	}
	current->next = new;

	++list->size;

	return new;
}

void delete_at(struct DobleLinkList *list, size_t index)
{
	struct DblLink* current = search_element(list, index);

	if(current == NULL){
		return;
	}

	//if there is only one element left...
	if(list->head == list->tail){
		list->head = NULL;
		list->tail = NULL;
	} else if(current == list->head){
		current->next->prev = NULL;
		list->head = current->next;
	} else if(current == list->tail) {
		current->prev->next = NULL;
		list->tail = current->prev;
	} else {
		current->next->prev = current->prev;
		current->prev->next = current->next;
	}

	free(current);
	--list->size;
}



void print_from_head(struct DobleLinkList *list){
	if(list == NULL || list->head == NULL){
		return;
	}

	struct DblLink *current = list->head;

	while(current != NULL){
		printf("%d\n", current->value);
		current = current->next;
	}
}

void print_from_tail(struct DobleLinkList *list){
	if(list == NULL || list->tail == NULL){
		return;
	}

	struct DblLink *current = list->tail;

	while(current != NULL){
		printf("%d\n", current->value);
		current = current->prev;
	}
}



int main()
{
	struct DobleLinkList *list = createList();

	push_front(list, 1);
	push_front(list, 2);
	push_back(list, 3);
	push_back(list, 4);

	printf("printing from the head\n");
	print_from_head(list);

	printf("Inserting an element\n");
	insert_after(list, 1, 5);
	print_from_head(list);

	printf("Inserting after the first element\n");
	insert_after(list, 0, 6);
	print_from_head(list);

	printf("Inserting after the last element\n");
	insert_after(list, 5, 7);
	print_from_head(list);

	printf("printing from the tail\n");
	print_from_tail(list);

	printf("deleting first and last\n");
	delete_first(list);
	delete_last(list);
	print_from_head(list);

	printf("deleting second element\n");
	delete_at(list, 2);
	print_from_head(list);


	printf("deleting first\n");
	delete_first(list);
	print_from_head(list);

	printf("deleting last\n");
	delete_last(list);
	print_from_head(list);

	printf("deleting at the first element\n");
	delete_at(list, 1);
	print_from_head(list);

	printf("deleting at the first element\n");
	delete_at(list, 0);
	print_from_head(list);


	return 0;
}
