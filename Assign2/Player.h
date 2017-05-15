#ifndef PLAYER_H
#define PLAYER_H
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

//*****************************************************************
// FILE:      Player.h
// AUTHOR:    Caleb Ugent
// LOGON ID:  z1729481
// DUE DATE:  2/12/15
// 
// PURPOSE:   Contains the declaration for the Player class.
//*****************************************************************

class Player
{
	// Data members and method prototypes for the Player class go here
public:
	Player();
	Player(int, char[], char[], int, int);
	int getNumber();
	char* getName();
	char* getPosition();
	int getHits();
	int getAtBats();
	void setHits(int);
	void setAtBats(int);
	double battingAverage();
	void print();

private:
	int playerNum;
	char playerName[26];
	char playerPos[3];
	int numberOfHits;
	int numberAtBats;

};

#endif
