#ifndef SHAPE_H
#define SHAPE_H

//Programmer Caleb Ugent
//Due date 4/30/15
//ZID z1729481
//Description
//To declare all the functions of the base class


#include <string>
#include <iostream>



using namespace std;
class Shape
{

public:
	Shape(const string &);
	virtual ~Shape();
	virtual void print() const;
	//pure virutal function
	virtual double get_area() = 0;



protected:
	string color;
};






#endif
