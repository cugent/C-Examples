//Coder: Caleb Ugent
//Date Due 9/6/2015
//Assignment 1
//Date 9/3/15
//CSCI 340
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

//Prototype
void printVec ( const vector < int >&, int);
void genRndNums ( vector < int >& , int, int);
int main()
{
    vector<int> v;
    genRndNums( v, 100, 9 );
    sort(v.begin(), v.end());
    printVec(v, 100);

    return 0;


}

//This method creates a vector and fills it with random numbers between high and low
 void genRndNums ( vector < int >& v, int vec_size, int seed )
{
    const int HIGH = 10000;
    const int LOW = 1;
    srand(seed);
//This loop fills the vector with random numbers
    for (int x = 0; x < vec_size; x++)
    {
        v.push_back(rand()%(HIGH - LOW + 1) + LOW);
    }
}


//This method cycles through the vector and displays its contents formatted
void printVec ( const vector < int >& v, int vec_size)
{
int y = 0;
//This loops for the size
 for (int x = 0; x < vec_size; x++)
 {

//If its null its end
     if (v[x] == NULL)
     {
         break;
     }
//Prints it out
     else
     {
         cout << v[x] << " ";
     }
    y++;
// if 12 numbers get printed add a new line and set the counter back to 0;
    if (y == 12)
    {
    cout << endl;
    y =0;
    }
}
}

