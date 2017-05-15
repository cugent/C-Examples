//Programmer: Caleb Ugent
//Player.cpp
//Program description: To manage each player object created and deal with the
//values inputtted and configure them.
//Date: 2/12/15
#include "Player.h"
//Default constructor that sets everything to null or 0
Player::Player()
{
	playerNum = 0;
	numberAtBats = 0;
	numberOfHits = 0;
	strcpy(playerName, "");
	strcpy(playerPos, "");
}
//Secondary constructor that sets everything to what is passed when creating the object

Player::Player(int newNum, char newName [], char newPosition[], int hits, int bats )
{
	playerNum = newNum;
	setAtBats(bats);
	setHits(hits);
	strcpy(playerName, newName);
	strcpy(playerPos, newPosition);
}

//Get method used to acces the playerNum private data member
int Player::getNumber()
{
	return playerNum;
}
//Get method used to access the playerName private data member
char* Player::getName()
{
	return playerName;
}
//Get method used to get playerPos private data member.
char* Player::getPosition()
{
	return playerPos;
}
//Get method used to get  numberOfHits private data member
int Player::getHits()
{
	return numberOfHits;
}
//get method used to get numberAtBats private data member
int Player::getAtBats()
{
	return numberAtBats;
}
//Set method used to set the number of hits, and error check to make sure its a valid number
void Player::setHits(int newHitNumber)
{

	if (newHitNumber > 0)
	{
		numberOfHits = newHitNumber;
	}
	else
	{
		numberOfHits = 0;
	}
}
//Set method used to set the number of at bats and error checks to make sure
//its not a wrong number.
void Player::setAtBats(int newAtBatNumber)
{

	if (newAtBatNumber > 0)
	{
		 numberAtBats = newAtBatNumber;
	}
	else
	{
		numberAtBats = 0;
	}
}
//Method used to calculate the batting average based on numberofhits/numberatbats
double Player::battingAverage()
{
	if (numberAtBats > 0)
	{
		return(double) numberOfHits / numberAtBats;
	}
	else
	{
		return -1;
	}
}
//Print method used to print out each member of the private data section of the class
//with proper format
void Player::print()
{

	cout << setw(4) << left << playerNum << " ";
	cout << setw(27) << left << playerName << " ";
	cout << setw(5) << left << playerPos << " ";
	cout << setw(3) << right << numberOfHits << " ";
	cout << setw(5) << right << numberAtBats << " ";

	if (battingAverage() == -1)
	{
		cout << setw(7) << right << "-" << endl;
	}
	else
	{
		cout << fixed << setprecision(3)<< setw(7) << right << battingAverage() << endl;
	}
}

