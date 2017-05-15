//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To implement all of the driver program to make sure that I have coded the other classes correctly

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <iostream>
void print(const Shape&);

using namespace std;
int main()
{
	

	//Creating the array to test
	Shape * shapeArray[6];
	Rectangle hello("red", 8, 6);
	hello.print();
	shapeArray[0] = new Rectangle("red", 8, 6);
	shapeArray[1] = new Rectangle("blue", 3, 7);
	shapeArray[2] = new Circle("green", 10);
	shapeArray[3] = new Circle("orange", 5);
	shapeArray[4] = new Triangle("black", 10, 4);
	shapeArray[5] = new Triangle("red", 4, 8);
	
	//Printing out all the shapes
	cout << "Printing all Shapes...." << endl << endl << endl;
	for (int x = 0; x < 6; x++)
	{

		Rectangle *recPtr = dynamic_cast<Rectangle *>(shapeArray[x]);
		Circle *circlePtr = dynamic_cast<Circle*>(shapeArray[x]);
		Triangle *trianglePtr = dynamic_cast<Triangle *>(shapeArray[x]);

		
		if (recPtr != 0)
		{
			recPtr->print();
		}
		if (circlePtr != 0)
		{
			circlePtr->print();
		}
		if (trianglePtr != 0)
		{
			trianglePtr->print();
		}




	}
	//Printing out all the triangle specific parts of the array
	cout << endl << endl << endl << "Printing only Triangles: " << endl << endl << endl;
	for (int x = 0; x < 6; x++)
	{
		Triangle *trianglePtr = dynamic_cast<Triangle *>(shapeArray[x]);
		if (trianglePtr != 0)
		{
			trianglePtr->print();
		}
	}

	//Delete each object in the array
	for (int x = 0; x < 6 ; x++) 
	{
		delete shapeArray[x];
	}
	return 0;
}



