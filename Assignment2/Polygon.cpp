#include "pch.h"
#include "Functions.h"
#include "Shape.h"
#include "Vector.h"
class Polygon : public Shape {
private:
	
	float * coord;
	std::string type;
	float polyArea;
	int capacity = 10;
	bool isConv;
	int numberOfPoints = 0;
	int numOfSides;
	float centerCoord[2];
	float * xCoord;
	float  * yCoord;
	Vector point;

public:

	~Polygon()
	{
		
		delete[] xCoord;
		delete[] yCoord;
	}
	void operator=(const Shape &p)
	{
		std::cout << "You can only do this with polygons.";
	}
	void operator=(const Polygon &p)
	{
		this->isConv = p.isConv;
		this->numberOfPoints = p.numberOfPoints;
		this->coord = p.coord;
		this->numOfSides = p.numOfSides;
		this->polyArea = p.polyArea;
		this->centerCoord[0] = p.centerCoord[0];
		this->centerCoord[1] = p.centerCoord[1];
		this->xCoord = p.xCoord;
		this->yCoord = p.yCoord;
		
	}
	
	void operator+(const float *plusCoord)
	{
		//if counter >= capacity capacity*=2
		float * extraCoords = new float[capacity];
		std::copy(coord, coord + numberOfPoints , extraCoords);
		//Hämta float * med coords. Hitta slutet på den. Mata in points efter den
		
		delete[] coord;
		coord = extraCoords;
		coord[numberOfPoints] = plusCoord[0];
		coord[numberOfPoints + 1] = plusCoord[1];
		numberOfPoints += 2;
		numOfSides = numberOfPoints / 2;
		
	}
	void operator+(Shape &s)
	{
		
		int otherPoints = s.getNumberOfPoints();
		float * sCoords = s.getCoord();

		float * extraCoords = new float[numberOfPoints + otherPoints];
		std::copy(coord, coord + numberOfPoints, extraCoords);
		
		std::copy(sCoords, sCoords + otherPoints, extraCoords + numberOfPoints);
		
		delete[] coord;
		this->coord = extraCoords;
		this->numberOfPoints += otherPoints;
		this->numOfSides = numberOfPoints / 2;
		if (numberOfPoints == 2)
		{
			this->type = "point";
		}
		if (numberOfPoints == 4)
		{
			this->type = "line";
		}
		if (numberOfPoints == 6)
		{
			this->type = "triangle";
		}
		if (numberOfPoints >= 8)
		{
			this->type = "polygon";
		}
		
	}
	void operator<<(const Shape &s) {
		std::cout << "The vertices for this " << type << " are: \n";
		int j = 0;
		for (int i = 0; i < numOfSides; i++)
		{
			std::cout << "(" << coord[j] << " , " << coord[j + 1 ] << ") \n";
			j += 2;
		}
	}
	Polygon(float * floatArray, int numberOfPoints) {
		this->numberOfPoints = numberOfPoints;
		
		numOfSides = numberOfPoints / 2;
		coord = floatArray;
		std::copy(floatArray, floatArray + numberOfPoints, coord);
	
		this->xCoord = new float[numOfSides];
		this->yCoord = new float[numOfSides];
		if (numberOfPoints == 2)
		{
			type = "point";
		}
		else if (numberOfPoints == 4)
		{
			type = "line";
		}
		else if (numberOfPoints == 6)
		{
			type = "triangle";
		}
		else if (numberOfPoints >= 8)
		{
		type = "polygon";
		}
	}
	float area() {
		
		bool isInter;
		int j = 0;
		int k = 0;
		if (type == "point" || type == "line")
		{
			polyArea = -1;
		}
		else
		{
			for (int i = 0; i < numberOfPoints; i++)
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
			int l = numOfSides - 1;
			for (int n = 0; n < numOfSides; n++)
			{
				polyArea += (xCoord[l] + xCoord[n]) * (yCoord[l] - yCoord[n]);
				l = n;
			}
			polyArea = abs(polyArea / 2);
			isConv = isConvex();
			isInter = isIntersect();
		}
		if (polyArea == 0 || isConv == false || isInter== true)
		{
			polyArea = -1;
		}
		return polyArea;
	}




	float circumference() {

		float polyCircumference = 0;
		int l = numOfSides - 1;
		if (type == "point" || type == "line")
			polyCircumference = -1;
		else
		{
			for (int n = 0; n < numOfSides; n++)
			{

				polyCircumference += sqrt(pow(xCoord[n] - xCoord[l], 2) + pow(yCoord[n] - yCoord[l], 2));
				l = n;
			}
			polyCircumference = polyCircumference;
			
		}
		return polyCircumference;
	}



	float *position() {
		
		float centerX = 0;
		float centerY = 0;
		if (type == "triangle")
		{
			centerX = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
			centerY = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;
			centerCoord[0] = centerX;
			centerCoord[1] = centerY;

		}
		else if (type == "point")
		{
			return coord;
		}
		else if (type == "line")
		{
			centerX = (coord[2] - coord[0]) / 2;
			centerY = (coord[3] - coord[1]) / 2;

			centerCoord[0] = centerX;
			centerCoord[1] = centerY;
		}
		else {

			if (isConv == false)
			{

				float xHighest = xCoord[0];
				float yHighest = yCoord[0];
				float xLowest = xCoord[0];
				float yLowest = yCoord[0];
				for (int n = 0; n < numOfSides; n++)
				{
					if (xCoord[n] < xLowest)
						xLowest = xCoord[n];
					if (yCoord[n] < yLowest)
						yLowest = yCoord[n];
					if (yCoord[n] > yHighest)
						yHighest = yCoord[n];
					if (xCoord[n] > xHighest)
						xHighest = xCoord[n];
				}

				float dy = yHighest - yLowest;
				float dx = xHighest - xLowest;
				centerCoord[0] = dx / 2;
				centerCoord[1] = dy / 2;
			}
			else
			{
				for (int n = 0; n < numOfSides; n++)
				{
					centerY += yCoord[n];
					centerX += xCoord[n];
				}
				centerX /= 2;
				centerY /= 2;
				centerCoord[0] = centerX;
				centerCoord[1] = centerY;
			}
		}
		return centerCoord;
	}



	bool isConvex() {
		bool isConv = false;
		if (type == "point" || type == "line" || type == "triangle")
		{
			isConv = true;
		}
		else {
			//Kolla vinkeln arctan dy/dx och spara den i en temporär variabel. Kolla arctan dy+1/dx+1 och kolla den är mindre än föregående, om den är större så är den konkav.
			float dy;
			float dx;
			float angle;
			float m = 0;

			//If convex it can not self intersect
			for (int n = 0; n < numOfSides; n++)
			{


				dx = xCoord[n + 2 % numOfSides] - xCoord[n + 1 % numOfSides];
				dy = yCoord[n + 2 % numOfSides] - yCoord[n + 1 % numOfSides];

				angle = abs(atan(dy / dx) * 100);

				if (angle > 180)
				{
					isConv = false;

				}
				else
					isConv = true;
			}



			return isConv;
		}
	}


		
		
	
		

	bool isIntersect() {
		float dy;
		float dx;
		float interiorAngle = 0;
		float exteriorAngle = 0;
	
		
		for (int n = 0; n < numOfSides-1; n++)
		{
			//dx = xCoord[n + 1 % numOfSides] - xCoord[n];
			//dy = yCoord[n + 1 % numOfSides] - yCoord[n];
		
			dx = xCoord[n + 2 % numOfSides] - xCoord[n + 1 % numOfSides];
			dy = yCoord[n + 2 % numOfSides] - yCoord[n + 1 % numOfSides];
			interiorAngle = atan(dy / dx) * 100;
			exteriorAngle += (180 - abs(interiorAngle));
		}
		if (exteriorAngle > 360)
		{
			return true;
		}
		else
			return false;
	}

	float distance(Shape *s) {
		float * sCoord = s->position() + 0;
		float d = sqrt(pow(sCoord[0] - coord[0], 2) + pow(sCoord[1] - coord[1], 2));
		
		
		
		return d;
	}

	std::string getType()
	{
		return type;
	}

	void print() {
		std::cout.precision(3);
		std::cout << "The type is: " << getType() << "\n";
		std::cout << "The area is: " << area() << "\n";
		std::cout << "The circumference is: " << circumference() << "\n";
		std::cout << "The center coordinate is: " << position()[0] << " and " << position()[1] << "\n";
	}

	int getNumberOfPoints() {
		return numberOfPoints;
	}

	float * getCoord() {
		return coord;
	}
};