// array_list.h
#include <stddef.h>
typedef struct _array_list ArrayList;
ArrayList *newArrayList(size_t);
void deleteArrayList(ArrayList*);
struct _array_list {
	size_t sizeOfElement;
	size_t numOfElements;
	void **elements;
	void(*add)(ArrayList*, void*);
	void(*insert)(ArrayList*, int, void*);
	void *(*remove)(ArrayList*, int);
	size_t(*size)(ArrayList*);
	void *(*get)(ArrayList*, int);
};
