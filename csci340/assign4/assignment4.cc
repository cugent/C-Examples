
/*****************************************
Name: Caleb Ugent
Date Due: 10/2/2015
Assignment: 4
Goal: To clean all words of punctuation and add them to a map to see how many times 
they occur
****************************************/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <iomanip>
#include <map>
#include <fstream>
#include <string>
using namespace std;

//Declaring some global variables
const int NO_ITEMS = 3;
const int ITEM_W = 16;
int num1= 0;
int num2 = 0;

/*****************************************
Name: Caleb Ugent
Date Due: 10/2/2015
Assignment: 2
Goal: This function takes in a map and iterates through it to
find and print all items and how often they were entered into the map
Takes in: Map to print from
Returns: nothing
****************************************/

void print_words( const map<string, int>& m)
{
map<string , int>::const_iterator it;
int x = 0;
it = m.begin();
//Runs until the end of map is read
while (it != m.end())
{
//cout << "Print words ran" << endl;
num2++;
//Adds a new line if noitems was printed
if (x == NO_ITEMS)
{
cout << endl;
x = 0;
}
 cout << left << setw(ITEM_W);
  cout <<  it ->first << ":" << setw(4) << it ->second << " ";
  x++;
  ++it;
}
cout << endl << endl;
//Prints out the number of words inputted vs the ones outputted
cout << "no of words in the input stream  : " << num1 << endl;
cout << "no of words in the output list   : " << num2 << endl;



}

/*****************************************
Name: Caleb Ugent
Date Due: 10/2/2015
Assignment: 4
Goal: To remove all uppercase letters and punctuation from a word and make the new
word the a second string
Takes in: 2 strings one for the old  word and one for the word returned.
Returns: nothing
****************************************/

void clean_entry( const string& s, string& newS)
{
string tempS;
//cout << s << endl;
//cout << "This happens";

//Runs a for loop for each letter in the string
for (unsigned int x = 0; x < s.length(); x++)
{
//If its a number or letter add it to the  temp variable
if (isalnum(s[x]))
{
//cout << "This ran";
   

//cout << "this also ran " << endl;
    
//cout << s[x] << endl;    
    tempS += s[x];

}
else
{
//If its the first letter do nothing and continue
if (x == 0)
{
continue;
}
else
//Do nothing and break
{
break;
}

}
}

//Set the new word to the temp
newS = tempS;
//cout  << newS << ":" << endl;

//Trransform it to lowercase
transform(newS.begin(), newS.end(), newS.begin(), ::tolower);
}


/*****************************************
Name: Caleb Ugent
Date Due: 10/21/2015
Assignment: 4
Goal: To get the words from a text file
and run it through the clean method
Takes in: a map to add the words to, and an ifstream to get the words from
Returns: nothing
****************************************/

void get_words( map<string, int>& m, ifstream& io)
{
    string s;
    string newS;
//While not end of file and you can read in more from the ifstream
while (io >> s)
{
	//cout << s << endl;
//Clean the word taken in
    clean_entry(s, newS);
//if what is returned has same data
if (newS.length() != 0)
{
//Add it to the map and increment the counter
   num1++;
    m[newS]++;
}
 
}

}


int main(int argc, char** argv) {
    if ( argc < 2 ) {
    cerr << "command line argument: input-file-name" << endl;
	return 0;
    }
    ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m, infile );

    infile.close();
    print_words( m );

    return 0;
}

