// array_list.h
#include <stddef.h>
#include "iterator.h"

typedef struct _array_list ArrayList;
ArrayList *newArrayList(size_t);
void deleteArrayList(ArrayList*);
void deleteIterator(Iterator*);

struct _array_list {
	size_t sizeOfElement;
	size_t numOfElements;
	Iterator* (*iterator)(ArrayList*);
	void **elements;
	void(*add)(ArrayList*, void*);
	void(*insert)(ArrayList*, int, void*);
	void *(*remove)(ArrayList*, int);
	void(*delete)(ArrayList *);
	size_t(*size)(ArrayList*);
	void *(*get)(ArrayList*, int);	
};
