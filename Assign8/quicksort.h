
//Programmer: Caleb Ugent
//Date: 4/24/15
//ZID: z1729481
//Description:
//To implment all the methods needed to run the quick sort

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Prototype the functions/methods
template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& , int , int , bool (*compare)(const T&, const T&));



//This method takes in a vector, and a generic function and calls the actual sorting function.
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
quickSort(set, 0, set.size()-1, compare);
}




//This function takes in a vector, two ints, and a generic function. This quicksorts the items in the vector using recursion.
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{

int pivotPoint;
if (start < end)
  {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
  }
}



//Takes in a vector, two ints, and a generic function. This is what creates the pivot, the middle, of the vector
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
  int pivotIndex, mid;
  T pivotValue;
  T temp;
   
   mid = (start + end) / 2;
   //Swap elements start and mid of the vector	
	temp = set[start];
	set[start] = set[mid];
	set[mid] = temp;
 
   pivotIndex = start;
   pivotValue = set[start];
 
   for (int scan = start + 1; scan <= end; scan++)
      {
      if (compare(set[scan], pivotValue))
         {
         pivotIndex++;
         //Swap elements pivotIndex and scan of the vector
	temp = set[pivotIndex];
	set[pivotIndex] = set[scan];
	set[scan] = temp;
         }
      }
	temp = set[pivotIndex];
	set[pivotIndex] = set[start];
	set[start] = temp;
	
   

   return pivotIndex; 


}

#endif
