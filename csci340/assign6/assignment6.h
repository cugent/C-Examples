/*********************************************************
Name: Caleb Ugent
Due Date 10/27/2015
Program Number: 6
Description: To remove search and add and displayo nly the left leaves of a binary tree
**********************************************************/
#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.h"
 
class BST : public binTree {
public:
	BST() : binTree() {}
	void insert(int);
	bool search(int);
	bool remove(int);

	void printLeftLeaves();
	void sumAncestors(int, int&);

private:
	void insert(Node*&, int);
	bool search(Node*&, int);
	bool remove(Node*&, int);

	void printLeftLeaves(Node*);
	bool sumAncestors(Node*, int, int&);
};


/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val
returns: nothing
**************************************************/
void BST::insert(int val)
{
	insert(root, val);
}
/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val and a node
returns: nothing
Does: Inserts a new node into the tree
**************************************************/

void BST::insert(Node*& ptr, int val)
{

	if (ptr == NULL)
	{
		ptr = new Node(val);
	}
	else
	{
		if (ptr->data > val)
		{
			insert(ptr->left, val);
		}
		else
		{
			insert(ptr->right, val);
		}
	}
}
/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val
returns: bool
Does: calls public search
**************************************************/

bool BST::search(int val)
{
	return search(root, val);
}
/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val and a node
returns: bool
Does: Searches the tree and if it finds it it returns true
**************************************************/


bool BST::search(Node*& n, int val)
{


if (n == NULL)
{
	return false;
}

if (n->data == val)
{
	return true;
}
else if (n->data > val)
{
	return search(n->left, val);
}
else
{
	return search(n->right, val);
}


	


	
/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val
returns: bool
Does: calls private funciton
**************************************************/


}
bool BST::remove(int val)
{
	return remove(root, val);
}
/**************************************************
Name: Caleb Ugent
Date: 10/27/2015
Takes in: val and a node
returns: bool
Does: removes a given node determines if its got children
**************************************************/

bool BST::remove(Node*& n, int val)
{
	if (n == NULL)
	{
		return false;
	}
	else if (n->data > val)
	{
		return remove(n->left, val);
	}
	else if (n->data < val)
	{
		return remove(n->right, val);
	}
	else if (n->left != NULL && n->right != NULL)
	{
	
		Node *predNode = n->left;
		while (predNode->right != NULL)
		{
			predNode = predNode->right;
		}
		n->data = predNode->data;
		return remove(n->left, predNode->data);
	}
	else if (n->left == NULL && n->right == NULL)
	{
		delete n;
		n = NULL;
		return true;
	}
	else
	{
		Node *Temp = n;
		if (n->left != NULL)
		{
			n = n->left;
		}
		else
		{
			n = n->right;
		}
		delete Temp;
		return true;

	}
}

void BST::printLeftLeaves()
{
	printLeftLeaves(root);
}
void BST::printLeftLeaves(Node* n)
{
return;
}

void BST::sumAncestors(int val, int& newVal)
{
	sumAncestors(root , val, newVal);
}

bool BST::sumAncestors(Node* n, int val, int& newVal)
{

return true;


}

#endif 

