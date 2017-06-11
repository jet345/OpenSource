// array_list.c
#include "linked_list.h"
#include "iterator.h"
#include "point.h"
#include <stdlib.h>
#include <string.h>
void deleteIterator(Iterator *);
static bool hasNext(Iterator *);
static void *next(Iterator *);

static void add(LinkedList*, void*);
static void insert(LinkedList*, int, void*);
static void *removel(LinkedList*, int);
static size_t size(LinkedList*);
static void *get(LinkedList*, int);

static void writeObject_linked(LinkedList *this, FILE *fp);
static void readObject_linked(LinkedList *this, FILE *fp);

typedef struct {
	void* node;
} LinkedListIterator;

void writeObject_linked(LinkedList *this, FILE *fp) {
	//printf("sizeof *this = %d\n", sizeof(*this));
	fwrite(this, sizeof(*this), 1, fp);
	Iterator *iter = this->iterator(this); //iterator 선언
	while (iter->hasNext(iter)) {
		Point *p = iter->next(iter);
		p->writeObject(p, fp);
	}
}

void readObject_linked(LinkedList *this, FILE *fp) {
	fread(this, sizeof *this, 1, fp);
	//printf("sizeof *this->sizeof = %d\n", this->numOfElements);
	this->head = NULL;
	int i = 0;
	for (i = 0;i < this->numOfElements;i++) {
		Point *p = newPoint(0, 0);		
		p->readObject(p, fp);
		if (feof(fp)) break;
		this->add(this, p);
	}

	this->numOfElements = i + 1;	
}

Iterator *iterator(LinkedList *this) {
	Iterator *newIter = newIterator();
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
	LinkedListIterator* a = iter->data;
	ListNode* b = a->node;
	if (b != NULL)
		return true;
	else
		return false;
}

void *next(Iterator *iter) {
	LinkedListIterator* a = iter->data;
	ListNode* b = a->node;
	a->node = b->next;
	return b->data;
}


LinkedList *newLinkedList(size_t sizeOfElement) {
	LinkedList *a;
	ListNode *node;
	node = (ListNode *)malloc(sizeof(ListNode));
	node->next = NULL;
	node->data = NULL;

	a = (LinkedList *)malloc(sizeof(LinkedList));
		
	a->head = NULL;
	a->sizeOfElement = sizeOfElement;
	a->numOfElements = 0;

	a->add = add;
	a->get = get;
	a->insert = insert;	
	a->remove = removel;
	a->size = size;	
	a->delete = deleteLinkedList;
	a->iterator = iterator;
	
	a->writeObject = writeObject_linked;
	a->readObject = readObject_linked;
	return a;
}

void deleteLinkedList(LinkedList* this) {
	ListNode* listnode_tmp;
	int i;
	while (this->numOfElements>0) {
		listnode_tmp = this->head;
		i = 0;
		while (i<this->numOfElements - 1) {
			listnode_tmp = listnode_tmp->next;
			i++;
		}
		free(listnode_tmp);
		this->numOfElements--;
	}
	free(this);
}

void add(LinkedList *this, void* value) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *move = this->head;
	this->numOfElements++;
	node->data = value;
	node->next = NULL;

	if (this->head == NULL) {
		this->head = node;
		return;
	}
	else {
		while (move->next != NULL)
			move = move->next;
		move->next = node;
	}
}

void insert(LinkedList *this, int i, void *value) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *move = this->head;
	int index = 0;
	this->numOfElements++;

	if (i == 0) {
		node->data = value;
		node->next = move;
		this->head = node;
		return;
	}
	
	for (int index = 0; index < (i-1); index++) {
		move = move->next;
	}
	node->data = value;
	node->next = move->next;
	move->next = node;
}

void *removel(LinkedList *this, int i) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	ListNode *move = this->head;
	ListNode *remove_node;
	int index = 0;
	void *data;
	this->numOfElements--;

	if (i == 0) {
		remove_node = this->head;
		this->head = remove_node->next;
		data = remove_node->data;
		free(remove_node);
		return data;
	}

	for (index = 0; index < (i - 1); index++) {
		move = move->next;
	}

	remove_node = move->next; //삭제대상
	move->next = remove_node->next;
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


