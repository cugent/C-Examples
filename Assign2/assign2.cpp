//Programmer: Caleb Ugent
//Program Description: To start and manage the team class
//Date 2/12/15
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Team.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

//Method used to create the team object and print and control the classes team and player

int main()
   {
	Team team1("playerdata");
        team1.print();
        team1.updateStats("gamestats.txt");
        team1.print();

   return 0;
   }
