/*
Programmer: Caleb Ugent
Date: 4/10/15
Assignment: 6
ZID: z1729481
Program description:
To implement all the code needed for the queue class
*/


#include "QueueADT.h"

//Default Constructor
QueueADT::QueueADT()
{
	rear = -1;
	front = 0;
	currentQueueSize = 0;
	maxArraySize = 1;
	queueAR = new int[maxArraySize];
}
//Deletes the dynamic memory and returns nothing
QueueADT::~QueueADT()
{
	delete[] queueAR;
}

//Checks to see if the queue is empty. If is return true else return false
bool QueueADT::isEmpty()
{
	if (currentQueueSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Copy constructor Copies from one instance of a class into a new instance of the class
QueueADT::QueueADT(const QueueADT & existingQueue)
{
	rear = existingQueue.rear;
	front = existingQueue.front;
	currentQueueSize = existingQueue.maxArraySize;
	maxArraySize = existingQueue.maxArraySize;
	queueAR = new int[maxArraySize];
	for (int x = 0; x < maxArraySize; x++)
	{
		queueAR[x] = existingQueue.queueAR[x];
	}


}



//Overloads the assignment operators gets passed an existing objet and creates a brand new object
QueueADT & QueueADT::operator=(const QueueADT &rightObj)
{
	if (this != &rightObj)
	{
		rear = rightObj.rear;
		front = rightObj.front;
		currentQueueSize = rightObj.currentQueueSize;
		maxArraySize = rightObj.maxArraySize;

		delete[] queueAR;
		queueAR = new int[maxArraySize];

		for (int sub = 0; sub < maxArraySize; sub++)
			queueAR[sub] = rightObj.queueAR[sub];
	}

	return *this;
}
//This creates and ostream object and a right object and outputs the righObj data. returns the ostream
ostream & operator<<(ostream & leftObj, const QueueADT & rightObj)
{

	int current, i;

	for (current = rightObj.front, i = 0; i < (int)rightObj.currentQueueSize; ++i)
	{
		// Print queue element at subscript i
		leftObj << rightObj.queueAR[current] << ' ';

		// Increment i, wrapping around to front of queue array if necessary     
		current = (current + 1) % rightObj.maxArraySize;
	}

	return leftObj;

}

//Clears the entire array
void QueueADT::clear()
{

	currentQueueSize = 0;
	front = 0;
	rear = -1;
}

//Returns the size of the queue takes nothing
int QueueADT::size()
{

	return currentQueueSize;
}

//Returns the capacity, and takes in no arguements
int QueueADT::capacity()
{



	return maxArraySize;
}

//Returns the front number in the queue, if its undefined it throws an error
int QueueADT::getfront()
{
	if (rear == -1)
	{
		throw ("underflow_error");
	}
	else
	{
		return queueAR[front];
	}
	return 0;
}

//Returns the rear number in the queue and if that is undefined it throws an error
int QueueADT::back()
{
	if (rear == -1)
	{
		throw ("underflow_error");
	}
	else
	{
		return queueAR[rear];
	}

}

//Pushes a number onto the queue, takes an integer and returns nothing
void QueueADT::push(int newElement)
{

	if (currentQueueSize == maxArraySize)
	{
		reserve(maxArraySize * 2);
	}

	if (rear >= maxArraySize - 1)
	{
		rear = -1;
	}

	rear++;
	queueAR[rear] = newElement;
	currentQueueSize++;
}


//Remove a number form the queue takes nothing and returns nothing
void QueueADT::pop()
{
	if (isEmpty())
	{
		throw ("underflow_error");
	}
	else
	{
		if (front >= maxArraySize - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
		currentQueueSize--;
	}

}

//If the queue is full this called and it make the queue larger. Takes a new size and returns nothing.
void QueueADT::reserve(int newSize)
{
	int *ptr;
	maxArraySize = newSize;
	ptr = new int[maxArraySize];
	for (int x = 0; x < maxArraySize; x++)
	{

		ptr[x] = queueAR[x];
	}
	delete[] queueAR;
	queueAR = new int[maxArraySize];
	queueAR = ptr;
}

