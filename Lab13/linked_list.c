// linked_list.c
#include "linked_list.h"
#include "iterator.h"
#include <stdlib.h>
#include <string.h>
static void deleteIterator(Iterator *);
static bool hasNext(Iterator *);
static void *next(Iterator *);

static void add(LinkedList*, void*);
static void insert(LinkedList*, int, void*);
static void *remove(LinkedList*, int);
static size_t size(LinkedList*);
static void *get(LinkedList*, int);

typedef struct {
	void* node;
} LinkedListIterator;

Iterator *iterator(LinkedList *this) {
	Iterator *newIter = malloc(sizeof(Iterator));
	LinkedListIterator *newListIter = malloc(sizeof(LinkedListIterator));
	
	newListIter->node = this->head;

	newIter->delete = deleteIterator;
	newIter->hasNext = hasNext;
	newIter->next = next;
	newIter->data = newListIter;

	return newIter;
}

void deleteIterator(Iterator *iter) {
	free(iter);
}

bool hasNext(Iterator *iter) {
	LinkedListIterator *a = iter->data;
	ListNode *b = a->node;

	if (b->next != NULL) {
		//iterator ��ĭ �ű��
		a->node = b->next;
		return true;
	}
	else
		return false;
}

void *next(Iterator *iter) {
	//�׻� hasNext�Լ� ������ ����ȴٰ� ����
	//iterator�� data�� �ǵ������ʴ´�.
	return iter->data;
}


LinkedList *newLinkedList(size_t sizeOfElement) {
	LinkedList *a;
	ListNode *node;
	node = (ListNode *)malloc(sizeof(ListNode));
	node->next = NULL;
	node->data = NULL;

	a = (LinkedList *)malloc(sizeof(LinkedList));
		
	a->head = node;
	a->sizeOfElement = sizeOfElement;
	a->numOfElements = 0;

	a->add = add;
	a->get = get;
	a->insert = insert;	
	a->remove = remove;
	a->size = size;	
	a->delete = deleteLinkedList;
	a->iterator = iterator;
	
	return a;
}

void deleteLinkedList(LinkedList* this) {
	ListNode *a = this->head;
	while(this->head != NULL) {
		while (a->next != NULL) {
			a = a->next;
		}
		free(a);
		a = this->head;
	}
}

void add(LinkedList *this, void* value) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *move = this->head;
	this->numOfElements++;
	node->data = value;
	node->next = NULL;
	if (this->head->data == NULL) {
		this->head = node;
	}
	else {
		while (this->head->next != NULL) {
			move = move->next;
		}
		move->next = node;
	}
}

void insert(LinkedList *this, int i, void *value) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	//ListNode *move = this->head;
	int index = 0;
	this->numOfElements++;

	if (i == 0) {
		node->data = value;
		node->next = this->head;
		this->head = node;
		return;
	}
	
	for (int index = 0; index < (i-1); index++) {
		this->head = this->head->next;
	}
	node->data = value;
	node->next = this->head->next;
	this->head->next = node;
}

void *remove(LinkedList *this, int i) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	//ListNode *move = this->head;
	ListNode *remove_node;
	int index = 0;
	void *data;

	if (i == 0) {
		remove_node = this->head;
		this->head = remove_node->next;
	}

	for (index = 0; index < (i - 1); index++) {
		this->head = this->head->next;
	}

	remove_node = this->head->next; //�������
	this->head->next = remove_node->next;
	data = remove_node->data;

	free(remove_node);

	return data;
}

size_t size(LinkedList *this) {
	return this->numOfElements;
}

void *get(LinkedList *this, int i) {
	//return this->elements[i];

}


