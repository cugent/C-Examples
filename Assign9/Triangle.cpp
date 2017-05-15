
//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To implement all the functions of class triangle
#include "Triangle.h"
#include <iostream>
#include <iomanip>

//Base constructor takes in a string and 2 ints. Returns nothing. Inherits from constructor of shape.
Triangle::Triangle(string newcolor, int newbase, int newheight)
:Shape(newcolor)
{
	height = newheight;
	base = newbase;
}

//Takes in nothing returns nothing. print out the data members specific to this class and calls the Parent classes print method.
void Triangle::print()
{

	Shape::print();
	cout << "triangle " << "height " << height << " base " << base << " area " << get_area() << endl;

}

//Does the specific get_area function needed for the triangle class. Takes in nothing returns a double
double Triangle::get_area()
{
	return .5*(base * height);
}
