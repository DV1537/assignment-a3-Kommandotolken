
#include "pch.h"
#include "Functions.h"
#include "Triangle.cpp"
#include "Polygon.cpp"
#include "Point.cpp"
#include "Line.cpp"


int main(int argc, const char * argv[])
{

	float centerCoordinates[2];
	int startingSize = 100;
	int capacity = startingSize;
	float * floatArray = new float[startingSize];
	float * floatArray2;
	float a;
	int counter = 0;
	char ch;
	
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
	
		while (myInputFile >> a)
		{

			if (counter >= capacity)
			{

				floatArray2 = new float[capacity * 2];
				std::copy(floatArray, floatArray + capacity, floatArray2);

				delete[] floatArray;


				floatArray = floatArray2;
				capacity *= 2;

			}
			floatArray[counter] = a;


			counter++;
			myInputFile.get(ch);
			if (ch == '\n' || myInputFile.eof())
			{
				if (counter % 2 != 0)
				{
					std::cout << "You missed a coordinate";
					return 1;
				}
				if (counter == 2)
				{

					Point point(floatArray, counter);
					point << (point);
					std::cout.precision(3);
					std::cout << "The type is: " << point.getType() << "\n";
					std::cout << "The area is: " << point.area() << "\n";
					std::cout << "The circumference is: " << point.circumference() << "\n";
					std::cout << "The center coordinate is: " << point.position()[0] << " And " << point.position()[1] << "\n";


				}
				if (counter == 4)
				{
					Line line(floatArray, counter);
					line << (line);
					std::cout.precision(3);
					std::cout << "The type is: " << line.getType() << "\n";
					std::cout << "The area is: " << line.area() << "\n";
					std::cout << "The circumference is: " << line.circumference() << "\n";
					std::cout << "The center coordinate is: " << line.position()[0] << " And " << line.position()[1] << "\n";
					std::cout << "Distance : " << line.distance(&line);

				}
				if (counter == 6)
				{

					Triangle triangle(floatArray, counter);
					triangle << (triangle);
					std::cout.precision(3);
					std::cout << "The type is: " << triangle.getType() << "\n";
					std::cout << "The area is: " << triangle.area() << "\n";
					std::cout << "The circumference is: " << triangle.circumference() << "\n";
					std::cout << "The center coordinate is: " << triangle.position()[0] << " And " << triangle.position()[1] << "\n";
					std::cout << "Distance : " << triangle.distance(&triangle);

				}
				if (counter >= 8)
				{
					float extraCoords[2] = { 1, 2 };
					Polygon poly(floatArray, counter);

					poly << (poly);

					std::cout.precision(3);
					std::cout << "The type is: " << poly.getType() << "\n";
					std::cout << "The area is: " << poly.area() << "\n";
					std::cout << "The circumference is: " << poly.circumference() << "\n";
					std::cout << "The center coordinate is: " << poly.position()[0] << " and " << poly.position()[1] << "\n";
					poly + (extraCoords);
					poly << (poly);
				}

				counter = 0;
			}
		}
		
	}
	


