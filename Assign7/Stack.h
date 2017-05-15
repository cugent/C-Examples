//Programmer: Caleb Ugent
//Date: 4/15/15
//ZID: z1729481
//Descriptiom:
//Declare and implement the methods needed to work the Node structure and the Stack Class
#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
struct Node
{
//Delcaring Data Members
	T data;
	Node *next;
//constructor for Node class. Takes a member to insert into data and sets next = null;
	Node(const T& insert )
	{
		data = insert;
		next = NULL;
	}

};

// Method definitions for the Node class

// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

using namespace std;
template <class T>
class Stack
{
	// friend declaration for the template function - note the
	// special syntax
	
	
public:

	friend std::ostream& operator<< <> (std::ostream& leftObj, const Stack& rightObj);
	
//Overloaded assignment operator takes in an existing stack and returns a this pointer
	Stack<T> operator=(const Stack<T> & existingStack)
	{
		if (this != &existingStack)
		{	
			clear();
			copyList(existingStack);
			
		}

		return *this;
	}
//Constructor sets everything to 0 or NULL
	Stack<T>()
	{
		stackSize = 0;
		stkTop = NULL;
	}
//Deconstructor deletes. calls clear
	~Stack<T>()
	{
		clear();
	}
//Copy Constructor Takes a reference to a stack object  returns nothing
	Stack<T>(const Stack<T> & newStack)
	{
		stackSize = 0;
		stkTop = NULL;
		
		copyList(newStack);
		
	}
//Clears the stack takes in nothing and returns nothing
	void clear()
	{
		while (stackSize != 0)
		{
			pop();
		}
		stkTop = NULL;
	}
//Returns a bool and takes in nothing. Determines if the stack is empty or not true if it is
	bool empty() const
	{
		if (stackSize > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
//Returns the size of the list takes in nothing
	int size() const
	{

		return stackSize;
	}
//This method takes nothing and returns a class T template returns the top data of the List
    T top() const
	{

		return stkTop->data;
	}
//This method takes in a new data member to be stored. It creates a node at the stkTop ptr and returns nothing
	void push(const T insertedItem)
	{
		Node<T> *tmp = new Node<T>(insertedItem);
		tmp->next = stkTop;
		stkTop = tmp;
		stackSize++;
		
		
	}
//This method deletes a node it takes in nothing and returns nothing
	void pop()
	{
		Node<T> *temp = stkTop;
		stkTop = stkTop->next;

		delete temp;
		stackSize--;
	}

private:
//Declaring  data members
	int stackSize;
	Node<T> *stkTop;
	//This function takes in an existing stackObject and returns nothing
	void copyList(const Stack<T> & existingStack)
	{
		//cout <<"Existing Size: " << existingStack.stackSize<< endl;
		int x = 0;
		int tempInt = existingStack.stackSize;
		T *ar;
		ar = new T[tempInt];
		Node<T> *temp;
		temp = existingStack.stkTop;
		while (temp != NULL)
		{	//cout << existingStack.stackSize << endl;
			ar[x] = temp->data;
			//cout << ar[x] <<  " ";
			temp = temp->next;

			x++;
		}
	
	//	cout << "THE SIZE OF AR IS : " << sizeof(ar) << endl;
		for (int i = tempInt - 1 ; i >= 0; i--)
		{
            
			push(ar[i]);
		}
		delete[] ar;
	}


};
//This function takes two arguements a reference to an ostream object and a reference to an instance of the class Stack
//It returns an ostream object
template <class T>
std::ostream& operator <<(std::ostream& leftObj, const Stack<T>& rightObj)
{
	Node <T> *temp;
	temp = rightObj.stkTop;
	while (temp != NULL)
	{
		leftObj << temp->data << " ";
		temp = temp->next;
	}
	return leftObj;
}

#endif
