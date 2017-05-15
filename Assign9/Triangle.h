//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To declare all the functions of Triangle class
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include <iostream>
#include "Shape.h"



using namespace std;
class Triangle :public Shape
{
public:

	Triangle(string, int, int);
	virtual void print();
	double get_area();
protected:
	int height;
	int base;
};
#endif
