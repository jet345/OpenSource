#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "iterator.h"
#include "point.h"
void main() {
	Point *p1, *p2, *p3, *p4;
	LinkedList *list = newLinkedList(sizeof(Point*));
	p1 = newPoint(1, 1); p2 = newPoint(2, 2);
	p3 = newPoint(3, 3); p4 = newPoint(4, 4);
	list->add(list, p3);
	list->insert(list, 0, p1);
	list->add(list, p4);
	//list->insert(list, 1, p2);
	//deletePoint(list->remove(list, 0));
	Iterator *iter = list->iterator(list);
	while (iter->hasNext(iter)) {
		Point *p = iter->next(iter);
		printf("List : (%f, %f)\n", p->getX(p), p->getY(p));
	}
	iter->delete(iter);
	list->delete(list);
}