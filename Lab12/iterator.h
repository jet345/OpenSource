// iterator.h
#pragma once
#include <stdbool.h>
typedef struct _iterator Iterator;
Iterator* newIterator();

struct _iterator {
	void* data;
	void(*delete)(Iterator*);
	bool(*hasNext)(Iterator*);
	void* (*next)(Iterator*);
};