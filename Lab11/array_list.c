// array_list.c
#include "array_list.h"
#include "point.h"
#include <stdlib.h>
#include <string.h>
static void add(ArrayList*, void*);
static void insert(ArrayList*, int, void*);
static void *remove(ArrayList*, int);
static size_t size(ArrayList*);
static void *get(ArrayList*, int);

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

	return a;
}
void deleteArrayList(ArrayList* this) {
	if (this->elements = !NULL)
		free(this->elements);
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
	Point *tmp;

	this->numOfElements--;
	memmove(this->elements + i, this->elements + (i + 1), (this->numOfElements - i) * this->sizeOfElement);
	tmp = this->elements[i];

	/*if (this->elements == NULL)
		tmp = calloc(this->numOfElements, this->sizeOfElement);
	else
		tmp = realloc(this->elements, (this->numOfElements) * this->sizeOfElement);
	this->elements = tmp;*/	
}

size_t size(ArrayList *this) {
	return this->numOfElements;
}
void *get(ArrayList *this, int i) {
	return this->elements[i];
}