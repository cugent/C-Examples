//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To implement all the functions of class circle

#include "Circle.h"
#include <iostream>
#include <iomanip>

//Constructor of class circle takes in a string and an int. Returns nothing. Inherits from the class Shape constructor.
Circle::Circle(string newcolor,int newradius)
:Shape(newcolor)
{
	radius = newradius;
}

//Print function prints all the members of the class Circle. Calls Shapes print function as well. Takes in nothing, returns nothing.
void Circle::print()
{
	
	Shape::print();
	cout << "circle " << "radius " << radius << " " << " " << get_area() << endl;
	
}

//Circles specific get_area function. Takes in nothing returns a double. Does the specific calculations needed for circles area class.
double Circle::get_area()
{
	return 3.14159 * (radius * radius); 
}

