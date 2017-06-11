#include <stdlib.h>
#include "iterator.h"

Iterator *newIterator() {
	Iterator *newIter = malloc(sizeof(Iterator));	
	return newIter;
}