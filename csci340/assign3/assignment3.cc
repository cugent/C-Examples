/****************************************
Name: Caleb Ugent
Date Due: 9/21/2015
Assignment: 3
Goal: To find all prime numbers in a set from 2 to a given range
*****************************************/



#include <algorithm>
#include <iomanip>
#include <iostream>
#include <set>


/****************************************
Name: Caleb Ugent
Date Due: 9/21/2015
Assignment: 3
Method Name: void sieve
Goal: To fill the set with all the numbers until n and then remove the non prime numbers using the sieve method
Variables Take:Take in a set s and a number that it wants the set to go to n
Return: Returns Nothing
*****************************************/

using namespace std;

//GLOBAL CONST VARIABLES
const int NO_ITEMS = 10;
const int ITEM_W = 5;

void sieve( set<int>& s, int n)
{
set<int>::const_iterator it;
set<int>::const_iterator it2; 
//Filling the set from 2 to N.
    for (int x = 2; x < n; x++)
    {
        s.insert(x);
    }

//This will rap through the second iterator and then check that against each number
//In the set it will oncly increment once that is done
//Once it checks it will move on to check remaining numbers against the next 
//Remaining item in the set it can choose from after the removal of so many
for(it2 = s.begin(); it2 != s.end(); it2++)
{
   for(it = s.begin(); it != s.end(); it++)
    {
	if (*it % *it2 == 0 && *it != *it2)
         {
		s.erase(it);
         }
    }
}
}
/****************************************
Name: Caleb Ugent
Date Due: 9/21/2015
Assignment: 3
Method Name: void print_primes
Goal: To print out the numbers in a neat column of 10 and space of 5 apart and make it look like a chart
Variables Take:Take in a set s
Return: Returns Nothing
*****************************************/


void print_primes( const set<int>& s)
{	
    int count = 0;
    int printed = 0;
    set<int>::const_iterator it;
    it = s.begin();
while (it != s.end())
{
count++;
it++;
}
it = s.begin();
//while its not the end print it
cout << "There are " << count << " prime numbers" << endl;
    while (it != s.end())
    {

        if (printed == NO_ITEMS)
        {
            cout << endl;
	    printed = 0;
       }
         cout << setw(ITEM_W) << *it++;
         printed++;

}
cout << endl;
}

int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}


