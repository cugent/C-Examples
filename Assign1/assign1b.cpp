#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <cstdio>


using namespace std;

int convertNumeric(char result [80]);
int main()
{
	//Creating an array of the possible outcomes
	string nameAR[23] = { ("emptiness, nothingness, blank"), ("independence, loneliness, creativity, originality, dominance, leadership, impatience"),
		("quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient"), ("charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud"),
		(" harmony, truth, justice, order discipline, practicality"), ("new directions, excitement, change, adventure"), ("love, harmony, perfection, marriage, tolerance, public service"), ("spirituality, completeness, isolation, introspection"),
		("organization, business, commerce, new beginnings"), ("romantic, rebellious, determined, passionate, compassionate"), "nothing", ("idealism, visionary, inspirational"), ("perfectionist, discriminating"), "nothing", "nothing", "nothing", "nothing", "nothing", "nothing", "nothing","nothing", "nothing", ("builder, leader, humanitarian, practical, honest") };

	//Creating Variables
	string userName = "";
	char user[80] = {};
	string runProgram = "Y";
	int totalValue = 0;
	//Determining if the user wants to run the program
	while (runProgram == "Y" || runProgram == "y")
	{
		cout << "Please enter your name: ";
		getline(cin, userName);

		strcpy(user, userName.c_str());
		
		

		


	//Running the function to get the value
		totalValue = convertNumeric(user);
		
		//Determining if the value is valid
			if (totalValue <= 22)
			{
				while (nameAR[totalValue] == "nothing")
				{
					sprintf(user, "%d", totalValue);
					totalValue = convertNumeric(user);
				}
				cout << "That name has the traits of " << nameAR[totalValue] << endl;
			}
			else
			{
				while (totalValue >= 23 || nameAR[totalValue] == "nothing")
				{
				 sprintf(user, "%d", totalValue);
			
				totalValue = convertNumeric(user);
				}
				cout << "That name has the traits of " << nameAR[totalValue] << endl;
			}
		
			
		
		
//Getting the users input on whether to run again
		cout << "Enter another name Y/N";
		cin >> runProgram;
		cin.ignore(1);

	}



	//for (int x = 0; x < 22; x++)
	//{


		//cout << nameAR[x] << endl;
	//}







	return 0;
}


//This function will take an array and determine if the char in the slot is either numeric or an alpha character.
//Once its done it returns the number to main.
int convertNumeric(char result[])
{
	
	int totalValue = 0;
	int tempValue = 0;
	
	//Running a loop to check each char in the array
	for (int sub = 0; sub < strlen(result); sub++)
	{
		char temp = result[sub];

		temp = toupper(temp);
		if (isalpha(temp))
		{
			tempValue = temp - 64;
			totalValue += tempValue;
		}
		else if (isdigit(temp))
		{
			
			
			tempValue = temp - 48;
			totalValue += tempValue;
		}
	}



	return totalValue;
}


