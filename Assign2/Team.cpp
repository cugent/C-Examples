//Prgrammer Caleb Ugent
// Team.cpp
//Program Job: To manage an array of player objects into a team
// Date: 2/12/15
#include "Team.h"

//Default constructor to just set player number to 0
Team::Team()
{

	numberOfPlayersStored = 0;
}
//This constructor takes a name of an existing 
//file opens it and reads the data in the file
Team::Team(const char* existingDatabase)
{
	ifstream inFile;

	inFile.open(existingDatabase, ios::binary);
	assert(inFile);

	inFile.read((char*) this, sizeof(Team));

	inFile.close();

	sortByName();
}
//This method runs through each object in the player array and prints out
//the information for each. Take no arguements
void Team::print()
{
	cout << "Chicago White Sox Roster" << endl << endl;
	cout << "NO     Name                     Pos      H    AB    AVG " << endl;

	for (int x = 0; x < numberOfPlayersStored; x++)
	{
		playerArray[x].print();
	}

}

//This methods takes nothing and returns nothing but it sorts the player object
//array using an insertion sort.
void Team::sortByName()
{
	int i, j;
	Player bucket;

	for (i = 1; i < numberOfPlayersStored; i++)
	{
		bucket = playerArray[i];

		for (j = i; (j > 0) && (strcmp(playerArray[j - 1].getName(), bucket.getName()) > 0); j--)
			playerArray[j] = playerArray[j - 1];

		playerArray[j] = bucket;
	}
}

//Searches for a specific name using a  binary search
// then returns the position of the player object that shares the name
//if it fails it returns a -1
int Team::searchForName(char searchName[])
{
	int low = 0;
	int high = numberOfPlayersStored - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (strcmp(searchName, playerArray[mid].getName()) == 0)
                    {
			return mid;
                    }
         	else if (strcmp(searchName, playerArray[mid].getName()) < 0)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;

	
}
//This function takes a file and returns nothing
//This method is used to update the stats by searching for the name in the array
//then once it is found add your stats to it.
void Team::updateStats(const char* filename)
{
	ifstream inFile;

	inFile.open(filename);
	assert(inFile);
	string date = " ";
	char firstName [20] = " ";
	char lastName [40] = " ";
	int hits = 0;
	int bats = 0;
	inFile >> date;
	cout << "BOX SCORE FOR " << date << endl;
        cout << "Name                        H AB" << endl;

	inFile >> firstName;
	while (inFile)
	{
		inFile >> lastName;
		inFile >> hits;
		inFile >> bats;
		strcat(lastName, ", ");
		strcat(lastName, firstName);
		//cout <<lastName << endl;
		int x = searchForName(lastName);
		if (x == -1)
			cout << "Search Failed, Sorry" << endl;
		else
		{
			cout <<setw(27)<< left  << lastName;
			cout <<setw(2) << right << hits;
			cout <<setw(2) << right << bats << endl;
			playerArray[x].setHits(playerArray[x].getHits() + hits);
			playerArray[x].setAtBats(playerArray[x].getAtBats() + bats);
		}

		inFile >> firstName;
	}


}
