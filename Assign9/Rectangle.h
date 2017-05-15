//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To declare all the functions and methods of Rectangle

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <iostream>
#include "Shape.h"

using namespace std;
class Rectangle :public Shape
{

public:

	Rectangle(string, int, int);
	virtual void print();
	double get_area();
protected:
	int height;
	int width;
};
#endif
