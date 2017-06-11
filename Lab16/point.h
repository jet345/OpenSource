
// point.h
// type definition
#include <stdio.h>
typedef struct Point Point;
struct Point {
	double x;
	double y;
	double(*getX)(Point*);
	double(*getY)(Point*);
	double(*distance)(Point *, Point *);
	void(*writeObject)(Point *, FILE *);
	void(*readObject)(Point *, FILE *);
};

Point *newPoint(double x, double y);
void deletePoint(Point *this);
static double distance(Point *p1, Point *p2);
static double getX(Point *this);
static double getY(Point *this);
static void writeObject(Point *, FILE *);
static void readObject(Point *, FILE*);
