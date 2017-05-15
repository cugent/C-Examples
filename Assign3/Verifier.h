#ifndef VERIFIER_H
#define VERIFIER_H

class Verifier
{

public:
	Verifier();

	void readGrid(const char*);
	void printGrid();
	bool verifySolution();


private:
	int sudokuBoard[9][9];
        int  sudokuCheck[10];
};
#endif
