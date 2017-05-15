/*
Programmer: Caleb Ugent
Date: 4/10/15
Assignment: 6
ZID: z1729481
Program description:
To implement the class definition
*/
#include <iostream>

using namespace std;
class QueueADT
{
public:
	QueueADT();
	~QueueADT();
	QueueADT(const QueueADT &);
	QueueADT & operator=(const QueueADT &);
	friend ostream & operator<<(ostream &out, const QueueADT &);
	void clear();
	bool isEmpty();
	int getfront();
	int size();
	int capacity();
	int back();
	void push(int);
	void pop();
	void reserve(int);





private:
	int maxArraySize;
	int *queueAR;
	int currentQueueSize;
	int front;
	int rear;
};
