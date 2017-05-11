#pragma once
// point.h
// type definition
typedef struct Point Point;
struct Point {
	double x;
	double y;
	double(*getX)(Point*);
	double(*getY)(Point*);
	double(*distance)(Point *, Point *);
};

Point *newPoint(double x, double y);
void deletePoint(Point *this);
static double distance(Point *p1, Point *p2);
static double getX(Point *this);
static double getY(Point *this);