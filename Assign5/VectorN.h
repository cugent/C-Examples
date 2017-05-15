

/*********************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER: Caleb Ugent
LOGON ID:   z1729481
DUE DATE:   3/25/15

FUNCTION:   This is the header for the class VectorN
*********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <iomanip>
#include <stdexcept>


using namespace std;

class VectorN
{
	friend ostream & operator<< (ostream &, const VectorN &);
	friend VectorN  operator * (const double num, const VectorN rightObj);
	friend VectorN  operator * (const VectorN rightObj, const double num);
	friend bool operator==(const VectorN &leftObj, const VectorN &rightObj);
public:
	VectorN();
	VectorN(double[], int);
	~VectorN();
	VectorN(const VectorN &obj);
	void clear();
	int size() const;
	VectorN operator+(const VectorN & rightObj) const;
	VectorN operator-(const VectorN & rightObj) const;
	VectorN & operator=(const VectorN &rightObj);
	double operator*(const VectorN & rightObj) const;
	double & operator[](const int &);
	double operator[](const int &)const;
	double at(int sub) const throw(out_of_range);
	double& at(int sub) throw(out_of_range);



private:
	double *AR;
	int numberOfElements;



};
#endif
