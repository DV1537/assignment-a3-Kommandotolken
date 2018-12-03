
#include "pch.h"
#include "Functions.h"
#include "Triangle.cpp"
#include "Polygon.cpp"
#include "Line.cpp"
#include <sstream>
//#include "Vector.h"

int main(int argc, const char * argv[])
{


	int startingSize = 100;
	int capacity = startingSize;
	float * floatArray = new float[startingSize];
	float * floatArray2;
	float a;
	int numberOfPoints = 0;
	int shapeCounter = 0;
	Shape *s[2];
	

	if (argc < 2)
	{
		std::cout << "You forgot to enter a filename.";
		return 1;
	}
	std::ifstream myInputFile;

	std::string line;
	char fileName[30];
	strcpy_s(fileName, argv[1]);
	myInputFile.open(fileName);

	if (myInputFile.fail())
	{
		std::cout << "There was an error opening the file.";
		return 1;
	}

	while (std::getline(myInputFile, line))
	{
		shapeCounter++;
	}
	myInputFile.clear();
	myInputFile.seekg(0, std::ios::beg);

	for (int i = 0; i < shapeCounter; ++i) {
		std::getline(myInputFile, line);
		std::stringstream stream(line);

		while (!stream.eof()) {
			stream >> a;

			if (numberOfPoints >= capacity)
			{
				floatArray2 = new float[capacity * 2];

				std::copy(floatArray, floatArray + capacity, floatArray2);

				delete[] floatArray;


				floatArray = floatArray2;
				capacity *= 2;

			}
			floatArray[numberOfPoints] = a;


			numberOfPoints++;
		}
		s[i] = new Polygon(floatArray, numberOfPoints);
		numberOfPoints = 0;
	}

		//skapa shapes
	
	s[0]->operator<<(*s[0]);
	s[1]->operator<<(*s[1]);
	s[0]->operator+(*s[1]);
	s[0]->operator<<(*s[0]);
	s[0]->print();

}

	/*while (myInputFile >> a)
	{
		numberOfPoints++;
	}
	while (myInputFile >> a)
	{



	myInputFile.close();
	/*s[0]->operator+(*s[1]);
	s[0]->operator<<(*s[0]);
	s[0]->print();
			/*if (counter % 2 != 0)
			{
				std::cout << "You missed a coordinate";
				return 1;
			}
			if (counter == 2)
			{

				s[0] = new Point(floatArray, counter);


			}
			if (counter == 4)
			{
				s[0] = new Line(floatArray, counter);


			}
			if (counter == 6)
			{

				s[0] = new Triangle(floatArray, counter);


			}
			if (counter >= 8)
			{
				

				s[0] = new Polygon(floatArray, counter);
				s[0]->print();


			}

			*/

	


	


