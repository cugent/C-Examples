//*****************************************************************
// FILE:      Team.h
// AUTHOR:    Caleb Ugent
// LOGON ID:  z1729481
// DUE DATE:  2/12/15
// 
// PURPOSE:   Contains the declaration for the Team class.
//*****************************************************************
#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#include <fstream>
#include <cassert> 

class Team
{

public:
	Team();
	Team(const char*);
	void print();
        void sortByName();
	int searchForName( char[] );
	void updateStats(const char*);


private:
	Player playerArray[40];
	int numberOfPlayersStored;



};







#endif
