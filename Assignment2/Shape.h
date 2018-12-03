#ifndef SHAPE_H
#define SHAPE_H
#include "Functions.h"


class Shape {
private:

	float * coord;
	int counter;
	

public:

	//Shape(float * a, int c);
	//Shape();
	
	virtual void operator=(const Shape &s) = 0;
	
	virtual void operator+(const float[]) = 0;
	virtual void operator+(Shape &s) = 0;
	virtual void operator<<(const Shape &s) = 0;
	virtual float area() = 0;


	virtual std::string getType() = 0;

	virtual float circumference() = 0;



	virtual float *position() = 0;



	virtual bool isConvex() = 0;



	virtual float distance(Shape *s) = 0;

	virtual float * getCoord() = 0; 
	virtual int getNumberOfPoints() = 0;
	virtual void print() = 0;
	
//	friend Shape *operator+(Shape& shape1, Shape& shape2);
};

/*Shape *operator+(Shape& shape1, Shape& shape2) {
	float * shape1Array = shape1.getCoord();
	float * shape2Array = shape2.getCoord();

	auto numberOfPoints = shape1.getNumberOfPoints() + shape2.getNumberOfPoints();
	float * pointsArray = new float[numberOfPoints];
	std::copy(shape1Array, shape1Array + shape1.getNumberOfPoints(), pointsArray);
	std::copy(shape2Array, shape2Array + shape2.getNumberOfPoints(), pointsArray + shape1.getNumberOfPoints());
	for (int i = 0; i < numberOfPoints; i++)
	{
		std::cout << *(pointsArray + i);
	}
	Shape *shape;
	if (numberOfPoints == 2)
		shape = new Point(pointsArray, numberOfPoints);
	else if (numberOfPoints == 4)
		shape = new Line(pointsArray, numberOfPoints);
	else if (numberOfPoints == 6)
		shape = new Triangle(pointsArray, numberOfPoints);
	else if (numberOfPoints >= 8)
		shape = new Polygon(pointsArray, numberOfPoints);
	return shape;
}*/
#endif SHAPE_H
