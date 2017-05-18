#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"
#include "point.h"
void main() {
	Point *p1, *p2, *p3, *p4;
	ArrayList *list = newArrayList(sizeof(Point*));
	p1 = newPoint(1, 1); p2 = newPoint(2, 2);
	p3 = newPoint(3, 3); p4 = newPoint(4, 4);
	list->add(list, p3);
	list->insert(list, 0, p1);
	list->add(list, p4);
	list->insert(list, 1, p2);
	deletePoint(list->remove(list, 0));
	for (int i = 0; i<list->size(list); i++) {
		Point *p = list->get(list, i);
		printf("List %d: (%f, %f)\n", i, p->getX(p), p->getY(p));
	}
}
