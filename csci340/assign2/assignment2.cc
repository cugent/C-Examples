//Caleb Ugent
//9.9.15
//Assignment 2.
//Due 9/11/2015
//Goal: to compare 2 vectors and tally how similar they are.
//Includes
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
//Global constant

//Prototype the functions
const int TOBE_SEARCHED = 5000;
bool linearSearch ( const vector < int >& v, int x );
void genRndNums ( vector < int >& v, int vec_size, int seed );
bool binarySearch ( const vector < int >& v, int x );
void printStat ( int totalSucCnt, int vec_size );
int search ( const vector < int >& v1, const vector <int >& v2, bool ( *p ) ( const vector < int >&, int ));
void sortVector ( vector < int >& v );


//Main method
int main()
{

 vector<int> container, tobeSearched;
    genRndNums(container, 10000, 9);
    genRndNums(tobeSearched, TOBE_SEARCHED, 3);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVector( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );



return 0;
}
//This method will search for an item and determine if its in there if it is it will return true. else false.
//It takes in the vector to search, and the int x is what it is searching for.
bool linearSearch ( const vector < int >& v, int x )
{
vector<int>::iterator it;
if(x==*find(v.begin(),v.end(), x))
{
    return true;
}
else
{
    return false;
}
}
//This function creates a random number list and inserts it into a vector. It takes in a vec that holds all the data, and 2 ints one to hold the size and the
//Other is to hold the seed. It returns nothing
void genRndNums ( vector < int >& v, int vec_size, int seed )
{
    const int HIGH = 10000;
    const int LOW = 1;
    srand(seed);
    for (int x = 0; x < vec_size; x++)
    {
        v.push_back(rand()%(HIGH - LOW + 1) + LOW);
    }
}
//This function performs a binary search. This function takes in a vector to search, and x the number to search for. it returns a bool if it found
//what was passed or not.
bool binarySearch ( const vector < int >& v, int x )
{

return binary_search (v.begin(),v.end(), x);
}

//This function manages the searches it calles whichever one is needed. It takes in 2 vectors to compare. It also takes in a generic function so it can call
//either of the two search functions we created. It returns an int in which is the number of times we found a match.
int search ( const vector < int >& v1, const vector <int >& v2, bool ( *p ) ( const vector < int >&, int ))
{

int cnt = 0;

for (int x = 0; x < v2.size(); x++)
{

    if (p(v1, v2[x]))
    {
        cnt++;
    }

}
cout << cnt;
return cnt;


}
//Sorts the vector in order. takes in a vector to sort and returns nothing.
void sortVector ( vector < int >& v )
{
sort(v.begin(), v.end());
}

//Prints the results, takes in an int to determine how many matches found, and the other int is the size of the vectors,
//returns nothing
void printStat ( int totalSucCnt, int vec_size )
{
cout << "Successful Searches: " << (((float)totalSucCnt/(float)vec_size) * 100) << "%" << endl;
}


