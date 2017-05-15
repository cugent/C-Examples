//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To implement all the functions and methods of rectangle

#include "Rectangle.h"
#include <iostream>
#include <iomanip>

//Copy constructor takes in a string and two ints, returns nothing. Inherits from the shape class constructor. 
Rectangle::Rectangle(string newcolor, int newheight, int newwidth)
:Shape(newcolor)
{
	height = newheight;
	width = newwidth;
}


//Print function takes in nothing and returns nothing. Prints out Rectangle specific members and also calls its inherited classes print method
void Rectangle::print()
{

	Shape::print();
	cout << "Rectangle " << "height " << height << " width " << width << " area " << get_area() << endl;

}

//Doubles specific get_area function. takes in nothing and returns nothing. calculates the specific area of a rectangle
double Rectangle::get_area()
{
	return width * height;
}
