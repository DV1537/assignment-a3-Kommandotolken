#include "pch.h"
#include "Functions.h"
#include "shape.h"

class Triangle : public Shape {
private:
	float * coord;
	std::string type = "triangle";
	float centerCoord[2];
	int counter;
	
	float xCoord[3];
	float yCoord[3];
	
public:
	Triangle(float * floatArray, int counter) {
		this->counter = counter;
		coord = floatArray;
		
		std::copy(floatArray, floatArray + counter, coord);
		
		
		
	}

	void operator=(const Triangle &t)
	{
		this->coord = t.coord;
		this->counter = t.counter;
		
	}
	
	void operator=(const Shape &t)
	{
		std::cout << "You can only do this with triangles.";
	}

	void operator+(const float[])
	{
		std::cout << "This operator does not work on Triangle.";
	}
	void operator+(Shape &s) {
		
	}
	void operator<<(const Shape &t) {
		std::cout << "The vertices for this triangle are: \n";
		int j = 0;
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << "(" << coord[j] << " , " << coord[j + 1] << ") \n";
			j += 2;
		}
	}
	float area() {

		int j = 0;
		int k = 0;
		
		for (int i = 0; i < counter; i++)
		{
			
			if (i % 2 == 0)
			{
				xCoord[j] = coord[i];
				j++;
				
			}
			else if (i % 2 != 0)
			{

				yCoord[k] = coord[i];
				k++;
				
			}
		}
		float triArea = 0;

		
		triArea = abs((xCoord[0] * (yCoord[1] - yCoord[2]) + xCoord[1] * (yCoord[2] - yCoord[0]) + xCoord[2] * (yCoord[1] - yCoord[0])))/2;
	
		
			if (triArea == 0 )
			{
				return -1;
			}
			else
		return triArea;

	}


	float circumference() {
		float triCircumference = 0;
		int l = 2;
		for (int n = 0; n < 3; n++)
		{

			triCircumference += sqrt(pow(xCoord[l] - xCoord[n], 2) + pow(yCoord[l] - yCoord[n], 2));
			l = n;
		}
		
		return triCircumference;
	}

	float * position() {
		float centerX;
		float centerY;
		
		centerX = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
		centerY = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;
		centerCoord[0] = centerX;
		centerCoord[1] = centerY;
		
		return centerCoord;
	}

	float distance(Shape *s)
	{
		
		float * sCoord = s->position() + 0;
		float d = sqrt(pow(sCoord[0] - coord[0], 2) + pow(sCoord[1] - coord[1], 2));
		
		return d;
	}

	bool isConvex() {
		return true;
	}

	std::string getType() {
		return type;
	}
	void print() {
		std::cout.precision(3);
		std::cout << "The type is: " << getType() << "\n";
		std::cout << "The area is: " << area() << "\n";
		std::cout << "The circumference is: " << circumference() << "\n";
		std::cout << "The center coordinate is: " << position()[0] << " and " << position()[1] << "\n";
	}
};
