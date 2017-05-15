/************************
Name: Caleb Ugent
Date: 11/16/2015
Program 8
Desciription: Create and implement a hashtable
************************/



#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//Create a struct entry that will contain all the data
struct Entry {
	std::string key;
	std::string description;
	Entry() { key = "---"; }
};


class HT {
private:
	std::vector<Entry>* hTable;
	int table_size;
	int item_count;
	int hashing(const std::string&);
public:
	HT(int size);
	~HT();
	bool insert(const Entry&);
	int search(const std::string&);
	bool remove(const std::string&);
	void print();
};

/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: a size s
Returns nothing
Does: Initializes the hash
********************/
HT::HT(int s = 11)
{
	table_size = s;
	hTable = new vector<Entry>(s);
	item_count = 0;
}

/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: nothing
Returns nothing
Does: deletes the hash
********************/

HT :: ~HT()
{
	delete hTable;
}

/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: a string key
Returns an int
Does: searches the hash for a value if it finds it returns the spot else it returns -1 if it cant find it
********************/

int HT::search(const string& key)
{

for (int x = 0; x < table_size; x++)
{
if (x == table_size)
{
return -1;
}
else if  (hTable->at(x).key == key)
{
return x;
}
}
return -1;
}


/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: an entry
Returns: a bool
Does: inserts a new item into the hash
********************/

bool HT::insert(const Entry& e)
{
	//cout << "E's key: " << e.key << endl;
//Get the hash
	int hashLocation = hashing(e.key);
	//cout <<  "Hashing finished succesfully " << hashNum << endl;
//If its to full exit
	if(item_count > table_size)
	{
	return false;
	}
//if the location is bigger then the vector get out
	if(hashLocation > table_size)
	{
	return false;
	}
//if its already there exit
	if (search(e.key) != -1 )
	{
		cerr <<  "Duplicate description for entry";
		return false;
	}
//Loop to find the place to insert
for (; hashLocation < table_size; hashLocation++)
{

//Increment back to 0
if (hashLocation == table_size)
{
hashLocation = 0;
}
//insert it
if (hTable->at(hashLocation).key == "+++" || hTable->at(hashLocation).key == "---")
{
hTable->at(hashLocation) = e;
item_count++;
return true;
}

}
return false;
}


/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: a string s
Returns a bool
Does: removes an item
********************/


bool HT::remove(const string& s)
{
//Search to find it
if (search(s) == -1)
{
return false;
}
else
{
//It found it and it should delete it
hTable->at(search(s)).key = "+++";
item_count--;
return true;
}

return false;

}

/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: nothing
Returns nothing
Does: Prints the hash
********************/

void HT::print()
{
	int x = 0;

//Print
cout << endl <<  "----Hash Table-----" << endl;
	while (x < table_size)
	{
		if (hTable->at(x).key == "---" || hTable->at(x).key == "+++")
		{
			x++;
			continue;
		}
		else
		{
			cout << setw(2) << x << ": " << hTable->at(x).key << ": " << hTable->at(x).description << endl;
		x++;
		}
	}
cout << "-------------------" << endl << endl << endl; 
}

#endif

