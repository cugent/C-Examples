// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "assignment8.h"
using namespace std;

int HT::hashing(const string& key) {
//cout << "The Key that is passsed :" << key;
return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}
/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: a size line
Returns a pointer of entry
Does: gets an entry to implement
********************/

Entry* get_entry(const string& line)
{
//cout << "get entry has run" << endl;

	Entry*  myEntry = new Entry;
	//cout << line.substr(2, 3) << endl;
//Get the key using subs operation
	myEntry->key = line.substr(2,3);
//cout << "meEntry key value: " << myEntry->key << endl;
	//cout << line.substr(6,	line.length()) << endl;
//get description with substr operation
	myEntry->description = line.substr(6, line.length());
	return myEntry;
}
/********************
Name: Caleb Ugent
Date: 11/16/2015
Takes: a string
Returns a string
Does: returns the key
********************/

string get_key(const string& line)
{

	return line.substr(2, line.length());

}



int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "argument: file-name\n";
		return 1;
	}

	HT ht;
	ifstream infile(argv[1], ios::in);
	string line;
	infile >> line;
	while (!infile.eof()) {
		if (line[0] == 'A') {
			Entry* e = get_entry(line);
//cout << "inserting" << endl;
			ht.insert(*e);
			delete e;
		}
		else {
			string key = get_key(line);
			if (line[0] == 'D') {
				cout << "Removing " << key << "...\n";
				bool removed = ht.remove(key);
				if (removed)
					cout << key << " is removed successfully...\n\n";
				else
					cout << key << " does not exist, no key is removed...\n\n";
			}
			else if (line[0] == 'S') {
				int found = ht.search(key);
				if (found < 0)
					cout << key << " does not exit in the hash table ..." << endl << endl;
				else
					cout << key << " is found at table position " << found << endl << endl;
			}
			else if (line[0] == 'P') {
				cout << "\nDisplaying the table: " << endl;
				ht.print();
			}
			else
				cerr << "wrong input: " << line << endl;
		}
		infile >> line;

	}

	infile.close();
	return 0;
}
