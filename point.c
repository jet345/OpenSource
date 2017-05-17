#include "point.h"
#include <stdlib.h>
#include <math.h>
// constructor using malloc
Point *newPoint(double x, double y) {
	Point *a;
	a = (Point *)malloc(sizeof(Point));
	a->x = x;
	a->distance = distance;
	a->getX = getX;
	a->getY = getY;
	a->y = y;

	return a;
}
// deconstructor using free
void deletePoint(Point* this) {
	free(this);
}
// member method
double getX(Point *this) {
	return this->x;
}

double getY(Point *this) {
	return this->y;
}

double distance(Point *p1, Point *p2) {
	double result;
	double x_value;
	double y_value;

	x_value = (p1->x - p2->x)*(p1->x - p2->x);
	y_value = (p1->y - p2->y)*(p1->y - p2->y);

	result = sqrt(x_value + y_value);

	return result;
}