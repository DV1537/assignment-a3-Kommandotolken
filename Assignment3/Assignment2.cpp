
#include "pch.h"
#include "Functions.h"

#include "Triangle.cpp"
#include "Polygon.cpp"
#include "Line.cpp"
#include <sstream>
//This program only makes use of the polygon class instead of Line, Point et.c

int main(int argc, const char * argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int startingSize = 10;
	int capacity = startingSize;
	float * floatArray = new float[startingSize];
	float * floatArray2 = nullptr;
	float a;

	int numberOfPoints = 0;
	int shapeCounter = 0;
	
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
	Shape **s = new Shape*[shapeCounter];
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
		if (numberOfPoints % 2 != 0)
		{
			std::cout << "You missed a coordinate";
			return 1;
		}
		s[i] = new Polygon(floatArray, numberOfPoints);
	
		numberOfPoints = 0;
		delete[] floatArray2;
	}

	
		
	s[0]->operator<<(*s[0]);
	s[1]->operator<<(*s[1]);
	s[0]->operator+(*s[1]);
	s[0]->operator<<(*s[0]);
	
	for (int i = 0; i < shapeCounter; i++)
	{
		delete s[i];
	}
		delete s;
		delete[] floatArray;
		
		
		
		
}

	