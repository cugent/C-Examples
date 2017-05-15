/*********************************************************************
PROGRAM:    CSCI 241 Assignment 3
PROGRAMMER: Caleb Ugent
LOGON ID:   z1729481
DUE DATE:   2/27/2015

FUNCTION:  This is the verifier class. This will take the sudoko from a file. Print it and than 
verify that each part of the grid is correct.
*********************************************************************/
#include "Verifier.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//This method is the default constructor which is used to set all the members in the grid to 0 it takes 0 arguements.
Verifier::Verifier()
{
	for (int column = 0; column < 9; column++)
	{

		for (int row = 0; row < 9; row++)
		{

			sudokuBoard[column][row] = 0;
		}	
	}
}

//This method loops through the sudoko grid array and adds numbers to each of them.
void Verifier::readGrid(const char* fileName)
{
	ifstream inFile;
	inFile.open((char*)fileName);
	for (int column = 0; column < 9; column++)
	{

		for (int row = 0; row < 9; row++)
		{
			inFile >> sudokuBoard[column][row];
		}
	}
}
//This method prints out the grid correctly
void Verifier::printGrid()
{
	for (int column = 0; column < 9; column++)
	{
	

		for (int row = 0; row < 9; row++)
		{
			cout << sudokuBoard[column][row] << " ";
		}
		cout << endl;
	}
}
//This method checks the grid to see if its correct, and if it passes then returns true, else it will return false when it fails.
bool Verifier::verifySolution()
{
	int tempNum;
	int counter = 3;
	int gridColumn = 0;
	int gridRow = 0;
	//Row Check
	for (int column = 0; column < 9; column++)
	{

		for (int row = 0; row < 9; row++)
		{
			tempNum = sudokuBoard[column][row];
			sudokuCheck[tempNum] = true;
		}
		for (int x = 1; x < 10; x++)
		{
			if (sudokuCheck[x] == false)
			{
				return false;
			}
		}
		for (int x = 1; x < 10; x++)
		{
			if (sudokuCheck[x] == false)
			{
				return false;
			}
		}
	}
	

	
	cout << "Row Check" << endl;

	//Column Check
	for (int row = 0; row < 9; row++)
	{

		for (int column = 0; column < 9; column++)
		{
			tempNum = sudokuBoard[column][row];
			sudokuCheck[tempNum] = true;

		}
		for (int x = 1; x < 10; x++)
		{
			if (sudokuCheck[x] == false)
			{
				return false;
			}
		}

		for (int x = 1; x < 10; x++)
		{
			sudokuCheck[x] = false;
		}
	}
	
	cout << "Column Check" << endl;
	//Cell check
	

	for (int x = 1; x < 10; x++)
	{
		sudokuCheck[x] = false;
	}
	cout << "Column Check" << endl;
	
		for (int x = 0; x < 9; x+=3)
		{
			for (int y = 0; y < 9; y += 3)
			{
				for (int row = x; row < x + 3; row++)
				{

					for (int column = y; column < y + 3; column++)
					{
						tempNum = sudokuBoard[column][row];
						sudokuCheck[tempNum] = true;
					}
				}
				for (int x = 1; x < 10; x++)
				{
					if (sudokuCheck[x] == false)
					{
						return false;
					}
				}

				for (int x = 1; x < 10; x++)
				{
					sudokuCheck[x] = false;
				}
			}
		}
	
	cout << "Cell Check" << endl;
	return true;
}


