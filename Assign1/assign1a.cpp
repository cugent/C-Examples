#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>


using namespace std;
//Prototyping the function
int convertNumeric(string result);
int main()
{
//Declaring an array to store all the categories of strings
	string nameAR[23] = { ("emptiness, nothingness, blank"), ("independence, loneliness, creativity, originality, dominance, leadership, impatience"),
		("quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient"), ("charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud"),
		(" harmony, truth, justice, order discipline, practicality"), ("new directions, excitement, change, adventure"), ("love, harmony, perfection, marriage, tolerance, public service"), ("spirituality, completeness, isolation, introspection"),
		("organization, business, commerce, new beginnings"), ("romantic, rebellious, determined, passionate, compassionate"), "nothing", ("idealism, visionary, inspirational"), ("perfectionist, discriminating"), "nothing", "nothing", "nothing", "nothing", "nothing", "nothing", "nothing","nothing", "nothing", ("builder, leader, humanitarian, practical, honest") };
//Creating the other arrays
	string userName = "";
	string runProgram = "Y";
	int totalValue = 0;
//Loop to determine if the person wants to run the program again
	while (runProgram == "Y" || runProgram == "y")
	{
		cout << "Please enter your name: ";
		getline(cin, userName);


	
		totalValue = convertNumeric(userName);
		
		
			if (totalValue <= 22)
			{
				cout << "That name has the traits of " << nameAR[totalValue] << endl;
			}
			else
			{
				ostringstream convToString;
				string result;
				convToString << totalValue;
				result = convToString.str();

				totalValue = convertNumeric(result);
				while (nameAR[totalValue] == "nothing")
				{
				ostringstream convToString;
				string result;
				convToString << totalValue;
				result = convToString.str();

				totalValue = convertNumeric(result);
				}
				cout << "That name has the traits of " << nameAR[totalValue] << endl;
			}
			
		
		

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


int convertNumeric(string result)
{

	int totalValue = 0;
	int tempValue = 0;
	
	for (int sub = 0; sub < result.length(); sub++)
	{
		char temp = result[sub];

		temp = toupper(temp);
		if (isalpha(temp))
		{
			tempValue = temp - 64;
			totalValue += tempValue;
			cout << totalValue << endl;
		}
		else if (isdigit(temp))
		{
			
			tempValue = temp - 48;
			totalValue += tempValue;
		}
	}



	return totalValue;
}


