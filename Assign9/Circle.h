//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To declare all of class circles functions and methods.
#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
#include <iostream>
#include "Shape.h"



using namespace std;
class Circle:public Shape
{

public:
	
	Circle(string, int);
	virtual void print();
	 double get_area();
protected:
	int radius;
};






#endif
