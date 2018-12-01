#include "pch.h"
#include "Functions.h"
#include "Shape.h"

class Polygon : public Shape {
private:
	
	float * coord;
	std::string type;
	float polyArea;

	bool isConv;
	int counter;
	int numOfSides;
	float centerCoord[2];
	float * xCoord;
	float  * yCoord;


public:

	~Polygon()
	{
		
		delete[] xCoord;
		delete[] yCoord;
	}
	/*void operator=(const Polygon &p)
	{
		this->isConv = p.isConv;
		this->counter = p.counter;
		this->coord = p.coord;
		this->numOfSides = p.numOfSides;
		this->polyArea = p.polyArea;
		this->centerCoord[0] = p.centerCoord[0];
		std::memcpy(this->centerCoord, p.centerCoord, sizeof(centerCoord));
		this->xCoord = p.xCoord;
		this->yCoord = p.yCoord;
		
	}*/
	void operator+(float plusCoord[2])
	{
		float * extraCoords = new float[counter + 2];
		std::copy(coord, coord + counter , extraCoords);
		//Hämta float * med coords. Hitta slutet på den. Mata in points efter den
		
		delete[] coord;
		coord = extraCoords;
		coord[counter] = plusCoord[0];
		coord[counter + 1] = plusCoord[1];
		counter += 2;
		numOfSides = counter / 2;
	}
	void operator<<(const Polygon &p) {
		std::cout << "The vertices for the polygon are: \n";
		int j = 0;
		for (int i = 0; i < numOfSides; i++)
		{
			std::cout << "(" << coord[j] << " , " << coord[j + 1 ] << ") \n";
			j += 2;
		}
	}
	Polygon(float * floatArray, int counter) {
		this->counter = counter;
		type = "polygon";
		numOfSides = counter / 2;
		coord = floatArray;
		std::copy(floatArray, floatArray + counter, coord);
		this->xCoord = new float[numOfSides];
		this->yCoord = new float[numOfSides];
		
	}
	float area() {
		
		bool isInter;
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
		int l = numOfSides - 1;
		for (int n = 0; n < numOfSides; n++)
			{
				polyArea += (xCoord[l] + xCoord[n]) * (yCoord[l] - yCoord[n]);
				l = n;
			} 
		polyArea = abs(polyArea / 2);
		isConv = isConvex();
		isInter = isIntersect();
		if (polyArea == 0 || isConv == false || isInter== true)
		{
			return -1;
		}
		else
		return polyArea;
	}




	float circumference() {
		float polyCircumference = 0;
		int l = numOfSides - 1;
		for (int n = 0; n < numOfSides; n++)
		{
			
			polyCircumference += sqrt(pow(xCoord[n] - xCoord[l], 2) + pow(yCoord[n] - yCoord[l], 2));
			l = n;
		}
		polyCircumference = polyCircumference;
		return polyCircumference;
	}



	float *position() {
		
		float centerX = 0;
		float centerY = 0;
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
		return centerCoord;
	}



	bool isConvex() {
		bool isConv = false;

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
			//dx = ;
			//
			//angle = abs(atan(dy / dx) * 100);


	
		return isConv;
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
};