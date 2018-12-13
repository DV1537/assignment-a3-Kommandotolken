#ifndef FIGURE_H
#define FIGURE_H
#include "Functions.h"
#include "Shape.h"

class Figure {
private:
	int capacity;
	Shape **shapeArray;
	float * floatArray;
	int numberOfPoints;
	int numberOfFigures = 0;
	

public:
	Figure();
	~Figure();
	Figure(int);
	void addShape(Shape *s, float * floatArray, int numberOfPoints);
	void addShape(Shape *s);
	float getBoundingBox();

};

#endif FIGURE_H