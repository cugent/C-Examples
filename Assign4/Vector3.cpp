#include "Vector3.h"
/*********************************************************************
PROGRAM:    CSCI 241 Assignment 4
PROGRAMMER: Caleb Ugent
LOGON ID:   z1729481
DUE DATE:   3/20/15

FUNCTION:   This program includes all the overloaded functions to do the calculations needed from
the vector3 class
*********************************************************************/


//This is the constructor method and it takes in 3 floats and sets the private data member floats to them
Vector3::Vector3(float xs, float ys, float zs)
{

	x = xs;
	y = ys;
	z = zs;
}
//This function overloads the output operator so you can just output a class
ostream & operator<< (ostream &leftObj, const Vector3 &rightObj)
{
	
	leftObj << "(" << rightObj.x << ", " << rightObj.y << ", " << rightObj.z << ")";

	return leftObj;
}

//This method overloads the + operator so you can add two vector3 objects
Vector3 Vector3::operator+(const Vector3 & rightObj) const
{
	Vector3 result;

	result.x = x + rightObj.x;
	result.y = y + rightObj.y;
	result.z = z + rightObj.z;

	return result;
}
//This method overloads the - operator so you can subtract 2 objects
Vector3 Vector3::operator-(const Vector3 & rightObj) const
{
	Vector3 result;

	result.x = x - rightObj.x;
	result.y = y - rightObj.y;
	result.z = z - rightObj.z;

	return result;
}
//This method overloads the * operator so you can multiply two objects
float Vector3::operator*(const Vector3 & rightObj) const
{
	float result;

	result = (x * rightObj.x) + (y * rightObj.y) + (z * rightObj.z);

	return result;
}
//This function allows you to multiply a constant float by and obj and overloads the multiply operator
Vector3 operator*(const float num, const Vector3 rightObj)
{
	Vector3 result;

	result.x = num * rightObj.x;
	result.y = num * rightObj.y;
	result.z = num * rightObj.z;

	return result;
}
//This function allows you to multiply an obj by a constant float and overloads the multiply operator
Vector3 operator*(const Vector3 leftObj, const float num)
{
	Vector3 result;

	result.x = leftObj.x * num;
	result.y = leftObj.y * num;
	result.z = leftObj.z * num;

	return result;
}
//This method overloads the index operator to allow you to change data members in an obj 
float & Vector3::operator[](const int &subscript)
{
	float error = 0.0;
	if (subscript == 0)
		return x;
	else if (subscript == 1)
		return y;
	else if (subscript == 2)
		return z;
	else
	{
		return error;
	}
}

//This method overloads the index operator to allow you to see the data members in an obj
float Vector3::operator[](const int &subscript) const
{
	if (subscript == 0)
	{
		return x;
	}
	else if (subscript == 1)
	{
		return y;
	}
	else if (subscript == 2)
	{
		return z;
	}
	else
	{
		return 0;
	}
}

//This function compares two obj to see if they are equal and returns true or false depending
bool operator==(const Vector3 &leftObj, const Vector3 &rightObj)
{
	if (leftObj.x == rightObj.x && leftObj.y == rightObj.y && leftObj.z == rightObj.z)
	{
		return true;
	}
	else
	{
		return false;
	}
}

