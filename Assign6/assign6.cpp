/*
Programmer: Caleb Ugent
Date: 4/10/15
Assignment: 6
ZID: z1729481
Program description:
To implement the driver program for the class
*/
#include <iostream>
#include <stdexcept>
#include "QueueADT.h"

using std::cout;
using std::endl;
using std::underflow_error;

int main()
{
	cout << "Testing default constructor\n\n";

	QueueADT q1;

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing push()\n\n";

	for (int i = 10; i < 80; i += 10)
		q1.push(i);

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing pop()\n\n";

	for (int i = 0; i < 3; ++i)
	{
		q1.pop();
	}

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing wrap-around on push()\n\n";

	for (int i = 2; i <= 8; i += 2)
		q1.push(i);

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing wrap-around on pop()\n\n";

	for (int i = 0; i < 6; ++i)
	{
		q1.pop();
	}

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing queue resize on push()\n\n";

	for (int i = 5; i < 70; i += 5)
		q1.push(i);

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing copy constructor()\n\n";

	QueueADT q2 = q1;

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "q2: " << q2 << endl;
	cout << "q2 size: " << q2.size() << endl;
	cout << "q2 capacity: " << q2.capacity() << endl;
	cout << "q2 is " << ((q2.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing front() and back()\n\n";

	cout << "Front item of q1: " << q1.getfront() << endl;
	cout << "Front item of q2: " << q2.getfront() << endl << endl;

	cout << "Rear item of q1: " << q1.back() << endl;
	cout << "Rear item of q2: " << q2.back() << endl << endl;

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "q2: " << q2 << endl;
	cout << "q2 size: " << q2.size() << endl;
	cout << "q2 capacity: " << q2.capacity() << endl;
	cout << "q2 is " << ((q2.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing pop() to empty\n\n";

	while (!q1.isEmpty())
	{
		cout << q1.getfront() << ' ';
		q1.pop();
	}

	cout << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 capacity: " << q1.capacity() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	cout << "Testing assignment operator\n\n";

	QueueADT q3;

	q3 = q2;

	cout << "q2 (size " << q2.size() << "): " << q2 << endl;
	cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;

	cout << "Testing clear()\n\n";

	q2.clear();

	cout << "q2 (size " << q2.size() << "): " << q2 << endl;
	cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;

	cout << "Testing assignment to self and swap\n\n";

	q3 = q3;
	q2 = q3;
	q3.clear();

	cout << "q2 (size " << q2.size() << "): " << q2 << endl;
	cout << "q3 (size " << q3.size() << "): " << q3 << endl << endl;

	cout << "Testing chained assignment\n\n";

	QueueADT q4;

	q4 = q3 = q2;

	cout << "q2 (size " << q2.size() << "): " << q2 << endl;
	cout << "q3 (size " << q3.size() << "): " << q3 << endl;
	cout << "q4 (size " << q4.size() << "): " << q4 << endl << endl;

	cout << "Testing const correctness\n\n";

	QueueADT & r4 = q4;

	cout << "q4: " << r4 << endl;
	cout << "q4 size: " << r4.size() << endl;
	cout << "q4 capacity: " << r4.capacity() << endl;
	cout << "q4 is " << ((r4.isEmpty()) ? "empty\n" : "not empty\n");
	cout << "Front item of q4: " << r4.getfront() << endl;
	cout << "Rear item of q4: " << r4.back() << endl << endl;

	q1 = r4;

	cout << "q1: " << q1 << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q1 is " << ((q1.isEmpty()) ? "empty\n" : "not empty\n");
	cout << endl;

	q1.clear();

	cout << "Testing front() with empty queue\n\n";

	try
	{
		cout << q1.getfront() << endl;
	}
	catch (underflow_error e)
	{
		cout << "Caught " << e.what() << endl << endl;
	}

	cout << "Testing back() with empty queue\n\n";

	try
	{
		cout << q1.back() << endl;
	}
	catch (underflow_error e)
	{
		cout << "Caught " << e.what() << endl << endl;
	}

	cout << "Testing pop() with empty queue\n\n";

	try
	{
		q1.pop();
	}
	catch (underflow_error e)
	{
		cout << "Caught " << e.what() << endl;
	}

	return 0;
}
