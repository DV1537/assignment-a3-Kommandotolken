#include "pch.h"
#include "Shape.h"
class Point : public Shape {
private:
	std::string type;
	float * coord;
	int counter;
public:
	
	 Point(float * floatArray, int counter) {
		
		this->counter = counter;
		coord = floatArray;
		type = "point";
		std::copy(floatArray, floatArray + counter, coord);
	}

	 void operator=(const Point &p)
	 {
		 
		 this->coord = p.coord;
		 this->counter = p.counter;
		

	 }

	 void operator+(const Point &p)
	 {
		 std::cout << "plus";
	 }

	 void operator<<(const Point &p) {
		 std::cout << "The vertices are: \n";
		 std::cout << "(" << coord[0] << " , " << coord[1];
	 }
	std::string getType() {
		return type;
	}


	float area() {
		return -1;
	}




	float circumference() {
		return 0;
	}



	float * position() {
		
		return coord;
	}



	bool isConvex() {
		return true;
	}


	float distance(Shape *s) {
		
		float * sCoord = s->position() + 0;
		float d = sqrt(pow(sCoord[0] - coord[0], 2) + pow(sCoord[1] - coord[1], 2));
		return d;
	}
};