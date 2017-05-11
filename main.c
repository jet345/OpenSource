// main.c
#include <stdio.h>
#include "point.h"
void main() {
	Point *p1, *p2;
	double dist;
	p1 = newPoint(1, 1);
	p2 = newPoint(4, 5);
	dist = p1->distance(p1, p2);
	printf("p1:(%f, %f)\n", p1->getX(p1), p1->getY(p1));
	printf("p2:(%f, %f)\n", p2->getX(p2), p2->getY(p2));
	printf("Distatnce between p1 and p2:%f\n", dist);
}
