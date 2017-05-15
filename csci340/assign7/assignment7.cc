/**************************************
Programmer: Caleb Ugent
Date: 11/4/15
Program: to create and sort a heap


***************************************/

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void build_heap(vector < int >&, int,
	bool(*compar)(int, int));

void heapify(vector < int >&, int, int, bool
	(*compar)(int, int));

bool less_than(int, int);

bool greater_than(int, int);

void heap_sort(vector < int >&, int,
	bool(*compar)(int, int));

int extract_heap(vector < int >& , int&, bool
	(*compar)(int, int));

void print_vector(vector < int >&, int, int);



int main(int argc, char** argv) {
	// ------- creating input vector --------------
	vector<int> v;
	v.push_back(-1000000);    // first element is fake
	int heap_size = 24;
	for (int i = 1; i <= heap_size; i++)
		v.push_back(i);
	random_shuffle(v.begin() + 1, v.begin() + heap_size + 1);
	cout << "\nCurrent input numbers: " << endl;
	print_vector(v, 1, heap_size);

	// ------- testing min heap ------------------
	cout << "\nBuilding a min heap..." << endl;
	build_heap(v, heap_size, less_than);
	cout << "Min heap: " << endl;
	print_vector(v, 1, heap_size);
	heap_sort(v, heap_size, less_than);
	cout << "Heap sort result (in ascending order): " << endl;
	print_vector(v, 1, heap_size);

	// ------- testing max heap ------------------
	cout << "\nBuilding a max heap..." << endl;
	build_heap(v, heap_size, greater_than);
	cout << "Max heap: " << endl;
	print_vector(v, 1, heap_size);
	heap_sort(v, heap_size, greater_than);
	cout << "Heap sort result (in descending order): " << endl;
	print_vector(v, 1, heap_size);

	return 0;
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In:a vector the heap size and a generic bool function to compare
Out: nothing
Function: builds the heap and calls heapify
************************************/
void build_heap(vector < int >& v, int heap_size,
	bool(*compar)(int, int))
{
for (int x = heap_size; x >= 1; x--)
	{
		heapify(v, x , heap_size, compar);
	}
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: a vector an int r and an int heap_size and a generic compare function bool
Out: nothing
Function: Heapifies the vector based on the bool function passed
************************************/

void heapify(vector < int >& v, int r, int heap_size, bool
	(*compar)(int, int))
{
//cout << "This ran";
//cout << "THis runs" << endl;
	int L = 2 * r;
	int R = 2 * r + 1;
	int largest = 0;
	if (L <= heap_size && compar(v[L], v[r]))
	{
		largest = L;
	}
	else
	{
		largest = r;
	}
	if (R <= heap_size && compar(v[R], v[largest]))
	{
		largest = R;
	}

	if (largest != r)
	{
		int temp = v[r];
		v[r]= v[largest];
		v[largest] = temp;
    		heapify(v, largest ,heap_size, compar);
}
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: 2 ints
Out: a bool
Function: returns if e1 is less then e2
************************************/

bool less_than(int e1, int e2)
{
	return e1 < e2;
}
/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: 2 ints
Out: bool
Function: returns if e1 is greater then e2
************************************/


bool greater_than(int e1, int e2)
{
	return e1 > e2;
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: a vector, the heapsize and a generic compare function
Out: nothing
Function: to sort the heap
************************************/

void heap_sort(vector < int >& v, int heap_size,
	bool(*compar)(int, int))
{
	int temp = 0;
//	build_heap(v, heap_size, compar);
	for (int i = heap_size; i >= 2; i--)
	{
		temp = v[i + 1];
		v[i + 1] = v[1];
		v[1] = temp;
		heapify(v, i, heap_size, compar);
	}
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: a vector the heap size and a generic bool function
Out: an int that is the largest/smallest number
Function: pulls the largest or smallest out
************************************/

int extract_heap(vector < int >& v, int& heap_size, bool
	(*compar)(int, int))

{
	int max = 0;
	if (heap_size < 1)
	{
		cout << "heap underflow";
	}
	max = v[1];
	v[1] = v[heap_size];
	heap_size = heap_size - 1;
cout << "HEAP SIZE: " <<  heap_size;
	heapify(v, 1, heap_size, compar);
	return max;
}

/***********************************

Programmer: Caleb Ugent
Date: 11/4/15
In: the vector a pint pos and a size
Out: nothing
Function: prints the vector  out 
************************************/

void print_vector(vector < int >& v, int pos, int size)
{

	int count = 0;
	for (int x = pos; x <= size; x++)
	{
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
		cout << setw(4) <<  v[x];
		count++;
	}

	cout << endl << endl;
}

