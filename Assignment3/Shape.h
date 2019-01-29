#ifndef SHAPE_H
#define SHAPE_H
#include "Functions.h"


class Shape {
private:

	//float * coord;
	int counter;
	

public:

	virtual ~Shape() {
		
	}
	virtual void operator=(const Shape &s) = 0;
	
	virtual void operator+(const float[]) = 0;
	virtual void operator+(Shape &s) = 0;
	virtual void operator<<(const Shape &s) = 0;
	virtual float area() = 0;


	virtual std::string getType() const = 0;

	virtual float circumference() const = 0;



	virtual float *position() = 0;



	virtual bool isConvex() const= 0;



	virtual float distance(Shape *s) const = 0;

	virtual float * getCoord() const = 0; 
	virtual int getNumberOfPoints() const = 0;
	virtual void print() = 0;
	

};


#endif SHAPE_H
