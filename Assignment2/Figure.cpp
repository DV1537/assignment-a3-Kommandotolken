#include "pch.h"
#include "Shape.h"
#include "Figure.h"
#include "Polygon.cpp"
/*
Figure::Figure() 
{

}
Figure::Figure(int capacity)
{
	
	this->capacity = capacity;
	this->shapeArray = new Shape*[capacity];
}
Figure::~Figure() {
	delete[] shapeArray;
}
void Figure::addShape(Shape *s, float * floatArray, int numberOfPoints) {
	
	if (capacity <= numberOfFigures)
		capacity *= 2;
	s = new Polygon(floatArray, numberOfPoints);
	for (int i = numberOfFigures; i < capacity; i++)
	{
		shapeArray[i] = s;
	}
	numberOfFigures++;
}

void Figure::addShape(Shape *s) {
	if (numberOfFigures >= capacity)
	{

		Shape **shapeArrayTemp = new Shape*[numberOfFigures];
		std::copy(shapeArray, shapeArray + capacity, shapeArrayTemp);
		delete[] shapeArray;
		shapeArray = shapeArrayTemp;
	}

	shapeArray[numberOfFigures] = s;

	(*(static_cast<Polygon*>(shapeArray[numberOfFigures]))).print();
	numberOfFigures++;

	
}


float Figure::getBoundingBox() {
	return 2;
}

*/
