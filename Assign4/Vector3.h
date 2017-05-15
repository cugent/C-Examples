/*********************************************************************
PROGRAM:    CSCI 241 Assignment 4
PROGRAMMER: Caleb Ugent
LOGON ID:   z1729481
DUE DATE:   3/20/15

FUNCTION:   This implements all the methods of the files
*********************************************************************/
#include <iomanip>
#include <iostream>

using namespace std; 
class Vector3
{
	friend ostream & operator<< (ostream &, const Vector3 &);
	friend bool operator==(const Vector3 &leftObj, const Vector3 &rightObj);
	friend Vector3  operator * (const float num, const Vector3 rightObj);
	friend Vector3  operator * (const Vector3 rightObj,const float num);
public:
	Vector3(float = 0, float = 0, float = 0);
	Vector3 operator+(const Vector3 & rightObj) const;
	Vector3 operator-(const Vector3 & rightObj) const;
	float & operator[](const int &);
	float operator[](const int &)const;
	float operator*(const Vector3 & rightObj) const;
private:
	float x;
	float y;
	float z;
};

