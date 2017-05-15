//Programmer: Caleb Ugent
//Date: 4/24/15
//ZID: z1729481
//Description:
//To implment all the methods needed to create the vector, print the vector, and compare items in the vector

#ifndef SORTS_H
#define SORTS_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;
// Prototype the functions
template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);



//This method takes in a vector, and a char. It reads the file and adds each entry to the vector.
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
T item;
ifstream inFile;
inFile.open(fileName);
assert (inFile);
inFile >> item;
while(inFile)
{
set.push_back(item);
inFile >> item;
}
inFile.close();
}

//This method takes a vector, and two ints. It prints the vector out.
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
    for (int x = 0; x < (int)set.size(); x++)
        {
	     if (x % numPerLine == 0)
	       {
		   cout << endl;
	       }
	     cout << setw(itemWidth) << set[x] << " ";
	}
    cout << endl;
}

//This method takes in two T's, and returns a bool. It compares and sees if item1 < item2.
template <class T>
bool lessThan(const T& item1, const T& item2)
{

if (item1 < item2)
{
return true;
}
else
{
return false;
}
}

//This method takes in two T's, and returns a bool. It checks and sees if item1 > item2.
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
if (item1 > item2)
{
return true;
}
else
{
return false;
}
}


#endif
