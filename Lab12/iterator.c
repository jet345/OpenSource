#include <stdlib.h>
#include "iterator.h"
Iterator *newIterator() {
	Iterator *newIter = malloc(sizeof(Iterator));
	
	return newIter;
}

void delete(Iterator *this) {
	this->delete;
}

bool hasNext(Iterator *this) {
	this->hasNext;
}

void* next(Iterator *this) {
	this->next;

	return this->data;
}