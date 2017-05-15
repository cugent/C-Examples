//Programmer: Caleb Ugent
//Date: 4/24/15
//ZID: z1729481
//Description:
//To implment all the methods needed to run the merge sortfor the program

#ifndef MERGESORT_H
#define MERGESORT_H



#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Declare the prototypes
template <class T> void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));
template <class T> void mergeSort(vector<T>& , int , int , bool (*compare)(const T&, const T&));
template <class T> void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));



//This method takes in a vector, and a generic function and returns nothing. It is used to start the merge sort
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
mergeSort(set, 0, set.size()-1, compare);
}


//This method takes in a vector, two ints, and a generic function. It compares and decides whats low and high and does the merge sorting.
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
 int mid;
   
   if (low < high)
      {
      mid = (low + high) / 2;
      
      // Divide and conquer
      
      mergeSort(set, low, mid, compare);
      mergeSort(set, mid+1, high, compare);
      
      // Combine
      merge(set, low, mid, high, compare);
      }
   

}

//This method takes in a vector, three ints, and a generic function. It is used to combine the lower and upper half of the vector.
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{



  // Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
         //Copy element j of set into element k of temp
	temp[k] = set[j];
         j++;
         k++;
         }
      else
         {
         //Copy element i of set into element k of temp
	 temp[k] = set[i];	
         i++;
         k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
      //Copy element i of set into element k of temp
      temp[k] = set[i];
      i++;
      k++; 
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
      //Copy element j of set into element k of temp
      temp[k] = set[j];
      j++;
      k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
      {

     // Copy element i of temp into element j of set
           set[j] = temp[i];

      }



}








#endif
