#include "VectorN.h"
/*********************************************************************
PROGRAM:    CSCI 241 Assignment 5
PROGRAMMER: Caleb Ugent
LOGON ID:   z1729481
DUE DATE:   3/25/15

FUNCTION:  This is the program that implements all the functions and methods
for the class VectorN
*********************************************************************/


//Default constructer setting everything to 0
VectorN::VectorN()
{
	numberOfElements = 0;
	AR = new double[0];
}
//Constructor that takes in an AR of doubles and the size of AR and set the private data members equal to them
VectorN::VectorN(double doubleAR[], int sizeOfAR)
{
	numberOfElements = sizeOfAR;
	AR = new double[sizeOfAR];
	for (int i = 0; i < sizeOfAR; i++)
	{
		AR[i] = doubleAR[i];
	}
	
}
//Copy constructor
VectorN::VectorN(const VectorN &obj)
{
	AR = NULL;
	numberOfElements = 0;

	numberOfElements = obj.numberOfElements;
	if (numberOfElements > 0)
	{
		AR = new double[obj.numberOfElements];
		for (int i = 0; i < numberOfElements; i++)
		{
			AR[i] = obj.AR[i];
		}
	}
	else
	{
		AR = NULL;
	}

}

//Deconstructor
VectorN::~VectorN()
{
	delete [] AR;
}

//Clear functions used to set the array size back to 0
void VectorN::clear()
{
	
	numberOfElements = 0;
	
	
}

//Returns the size of the array
int VectorN::size()const
{
	
	return numberOfElements;
}
//Overloading the + operator to add two vectors together and return a new vector. If one is smaller it goes with the smallest
VectorN VectorN::operator+(const VectorN & rightObj) const
{
	VectorN returnVector = VectorN();

	if (this->numberOfElements < rightObj.numberOfElements)
	{
		returnVector.numberOfElements = this->numberOfElements;
		returnVector.AR = new double[returnVector.numberOfElements];

		for (int i = 0; i < this->numberOfElements; i++)
		{
			returnVector.AR[i] = this->AR[i] + rightObj.AR[i];
		}
	}
	else
	{
		returnVector.numberOfElements = rightObj.numberOfElements;
		returnVector.AR = new double[returnVector.numberOfElements];

		for (int i = 0; i < returnVector.numberOfElements; i++)
		{
			returnVector.AR[i] = this->AR[i] + rightObj.AR[i];
		}
	}
	return returnVector;

}
//Overloading the - operator to subtract two vectors together and return a new vector. If one is smaller it goes with the smallest for number of

VectorN VectorN::operator-(const VectorN & rightObj) const
{
	VectorN returnVector = VectorN();

	if (this->numberOfElements < rightObj.numberOfElements)
	{
		returnVector.numberOfElements = this->numberOfElements;
		returnVector.AR = new double[returnVector.numberOfElements];

		for (int i = 0; i < this->numberOfElements; i++)
		{
			returnVector.AR[i] = this->AR[i] - rightObj.AR[i];
		}
	}
	else
	{
		returnVector.numberOfElements = rightObj.numberOfElements;
		returnVector.AR = new double[returnVector.numberOfElements];

		for (int i = 0; i < returnVector.numberOfElements; i++)
		{
			returnVector.AR[i] = this->AR[i] - rightObj.AR[i];
		}
	}
	return returnVector;

}
//Overloading the assigment operator for dynamic memory
VectorN & VectorN::operator=(const VectorN &rightObj)
{
	if (this == &rightObj)
	{
		return *this;
	}

	delete[] AR;
	numberOfElements = rightObj.numberOfElements;
	AR = new double[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		AR[i] = rightObj.AR[i];
	}
	return *this;

}
//Overloading the output operator for properly formatted output
ostream & operator<< (ostream &leftObj, const VectorN &rightObj)
{
	if (rightObj.numberOfElements == 0)
	{
		leftObj << "()";
		return leftObj;

	}
	else
	{
		leftObj << "(";

		for (int x = 0; x < rightObj.numberOfElements; x++)
		{
			
			leftObj << rightObj.AR[x];
			if (x != rightObj.numberOfElements - 1)
			{
				cout << ", ";
			}

		}
		leftObj << ")";

		return leftObj;

	}

	

	return leftObj;
}

//Overloading the multiplication operator so that a double can be multiplied by a vectorN array
VectorN  operator * (const double num, const VectorN rightObj)
{
	VectorN result = VectorN(rightObj);

	for (int x = 0; x < rightObj.numberOfElements; x++)
	{
		result.AR[x] = num * rightObj.AR[x];
	}


	return result;


}

//Overloading the multplication operator so that a VectorN object can be multiplied by a double
VectorN  operator * (const VectorN rightObj, const double num)
{
	VectorN result2 = VectorN(rightObj);

	for (int x = 0; x < rightObj.numberOfElements; x++)
	{
		result2.AR[x] = rightObj.AR[x] * num;
	}
	return result2;

}

//TEsting to see if two vectorNs are equal to each other
bool operator==(const VectorN &leftObj, const VectorN &rightObj)
{
	
	if (leftObj.numberOfElements != rightObj.numberOfElements)
	{
		return false;
	}
	else
	{
		for (int x = 0; x < rightObj.numberOfElements; x++)
		{
			if (leftObj.AR[x] != rightObj.AR[x])
			{
				return false;
			}
		}
		return true;
	}

}
//Overloading the subscript operator to allow manipulation of the data
double & VectorN::operator[](const int &subscript)
{

	return AR[subscript];
}
//Overloading the subscript operator to allow reading of the data
double VectorN::operator[](const int &subscript) const
{
	return AR[subscript];
}

//Overloading the multiplication operator so you can multiply two vectors against each other.
double VectorN::operator*(const VectorN & rightObj) const
{
	double result = 0.0;
	
	if (rightObj.numberOfElements < numberOfElements)
	{
		for (int x = 0; x < rightObj.numberOfElements; x++)
		{
			result += (AR[x] * rightObj.AR[x]);
		}
	}
	else
	{
		for (int x = 0; x < numberOfElements; x++)
		{
			result += (AR[x] * rightObj.AR[x]);
		}
	}
	return result;
}

//Error checking a subscript and making sure you didnt put to much or to little subscript
double VectorN::at(int sub) const throw(out_of_range)
{
	if (sub >= this->numberOfElements || sub < 0)
	{
		throw out_of_range("subscript out of range");
	}
	else
	{
		return this->AR[sub];
	}

	

}
//Error checking a subscript and making sure you didnt put to much or to little subscript
double& VectorN::at(int sub) throw(out_of_range)
{
	if (sub >= this->numberOfElements || sub < 0)
	{
		throw out_of_range("subscript out of range");
	}
	else
	{
		return this->AR[sub];
	}

}


