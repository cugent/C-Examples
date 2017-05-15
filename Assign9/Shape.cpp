//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To implement the base class for the program.

#include "Shape.h"
#include <iostream>

//Constructor takes in a string, and returns nothing.
Shape::Shape(const string & newColor)
{
	color = newColor;
}

//Print function prints the members of the shape class
void Shape::print() const
{
	cout << color << " ";
}
//Basic deconstructor does nothing takes in nothing and returns nothing. Without it will cause an error.
Shape::~Shape()
{

}


