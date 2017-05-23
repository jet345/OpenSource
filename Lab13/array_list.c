// array_list.c
#include "array_list.h"
#include "iterator.h"
#include <stdlib.h>
#include <string.h>

static void deleteIterator(Iterator *);
static bool hasNext(Iterator *);
static void *next(Iterator *);

static void add(ArrayList*, void*);
static void insert(ArrayList*, int, void*);
static void *remove(ArrayList*, int);
static size_t size(ArrayList*);
static void *get(ArrayList*, int);

typedef struct {
	ArrayList *list;
	int index;
} ListIterator;

Iterator *iterator(ArrayList *this) {
	Iterator *newIter = malloc(sizeof(Iterator));
	ListIterator *newListIter = malloc(sizeof(ListIterator));
	
	newListIter->list = this;
	newListIter->index = 0;

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
	ListIterator *a = iter->data;

	if (a->index < a->list->numOfElements)
		return true;
	else
		return false;
}

void *next(Iterator *iter) {
	ListIterator *a = iter->data;
	a->index++;
	return a->list->elements[a->index - 1];
}

ArrayList *newArrayList(size_t sizeOfElement) {
	ArrayList *a;
	a = (ArrayList *)malloc(sizeof(ArrayList));
	 
	a->add = add;
	a->elements = NULL;
	a->get = get;
	a->insert = insert;
	a->numOfElements = 0;
	a->remove = remove;
	a->size = size;
	a->sizeOfElement = sizeOfElement;
	a->delete = deleteArrayList;
	a->iterator = iterator;

	return a;
}

void deleteArrayList(ArrayList* this) {
	free(this);
}

void add(ArrayList *this, void* value) {
	void** tmp;
	this->numOfElements++;
	if (this->elements == NULL)
		tmp = calloc(this->numOfElements, this->sizeOfElement);
	else
		tmp = realloc(this->elements, this->numOfElements * this->sizeOfElement);
	this->elements = tmp;
	this->elements[this->numOfElements - 1] = value;
}

void insert(ArrayList *this, int i, void *value) {
	void** tmp;
	int result = -1;
	this->numOfElements++;
	if (this->elements == NULL)
		tmp = calloc(this->numOfElements, this->sizeOfElement);
	else
		tmp = realloc(this->elements, (this->numOfElements + 1) * this->sizeOfElement);
	
	this->elements = tmp;
	memmove(this->elements + (i + 1), this->elements + i, (this->numOfElements - 1 - i) * this->sizeOfElement);
	this->elements[i] = value;
}

void *remove(ArrayList *this, int i) {
	void **tmp;

	this->numOfElements--;
	tmp = this->elements[i];
	memmove(this->elements + i, this->elements + (i + 1), (this->numOfElements - i) * this->sizeOfElement);

	
	return tmp;	
}

size_t size(ArrayList *this) {
	return this->numOfElements;
}

void *get(ArrayList *this, int i) {
	return this->elements[i];
}
