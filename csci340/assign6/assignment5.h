/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: To program a binary tree using a class and a struct that can insert and use 
pre order post order in order traversal
***************************************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>

#ifndef ASSIGNMENT5
#define ASSIGNMENT5

using namespace std;
//--------------------------
// You need to add definition of the Node class
//--------------------------
struct Node
{
	friend class BST;
	friend class binTree;
public:
	Node(int);
private:
	int data;
	Node* left;
	Node* right;
};

/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:To create the node and assign the passed in val
Takes: Val to insert into data
Returns: Nothing
***************************************************/

Node::Node(int val)
{
	data = val;
	left = NULL;
	right = NULL;
}

class binTree {
	friend class Node;
public:
	binTree();
	virtual void insert(int);
	unsigned height() const;
	unsigned size() const;
	void inorder(void(*)(int));
	void preorder(void(*)(int));
	void postorder(void(*)(int));

protected:
	Node* root;
private:
	void insert(Node*&, int);
	unsigned height(Node*) const;
	unsigned size(Node*) const;
	void inorder(Node*, void(*)(int));
	void preorder(Node*, void(*)(int));
	void postorder(Node*, void(*)(int));
};

/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: To set the root value to Null
Takes: nothing
Returns: nothing
***************************************************/

binTree::binTree()
{
	root = NULL;
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:Be the public function that calls the private
Takes:a void function
Returns:nothing
***************************************************/

void binTree::inorder(void(*display)(int))
{
	inorder(root,  display);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:Take in a node and display the tree using inorder
Takes:take in a node to display and a void function
Returns:nothing
***************************************************/

void binTree::inorder(Node* ptr, void(*display)(int))
{
	if (ptr != NULL)
	{
		inorder(ptr->left, display);
		display(ptr->data);
		inorder(ptr->right, display);
	}
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: call the private function
Takes:a void function
Returns:nothing
***************************************************/

void binTree::preorder(void(*display)(int))
{
	preorder(root, display);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: displays the tree using preorder techniques
Takes: a ptr and a void function
Returns:nothing
***************************************************/

void binTree::preorder(Node* ptr, void(*display)(int))
{
	if (ptr != NULL)
	{
		display(ptr->data);
		preorder(ptr->left, display);
		preorder(ptr->right, display);
	}
}
/***************************************************
Name: Caleb Ugent
Date Due 10/14/15
Assignment:Public function that calls the private function 
Takes:a void function
Returns:nothing
***************************************************/

void binTree::postorder(void(*display)(int))
{
	postorder(root, display);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:print the tree out using post order techniques
Takes:a node and a void function
Returns:nothing
***************************************************/

void binTree::postorder(Node* ptr, void(*display)(int))
{
	if (ptr != NULL)
	{
		postorder(ptr->left, display);
		postorder(ptr->right, display);
		display(ptr->data);
		
	}
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:public function that calls private function insert
Takes: a val to insert
Returns:nothing
***************************************************/

void binTree::insert(int val)
{
	insert(root, val);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: to insert a new node into the tree based on whether its largr or smaller
Takes:a node and an int
Returns:nothing
***************************************************/

void binTree::insert(Node*& ptr, int val)
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
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment:The public function used to call the private
Takes:Nothing
Returns:returns a call to the private function
***************************************************/

unsigned binTree::height() const
{
	return height(root);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: To count the hiehgto f the tree
Takes:a node
Returns: an unsigned 
***************************************************/

unsigned binTree::height(Node* ptr) const
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
		return 1 + max(height(ptr->left), height(ptr->right));

}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: public function that calls the private
Takes:nothing
Returns: returns a call to the private
***************************************************/

unsigned binTree::size() const
{
	return size(root);
}
/***************************************************
Name: Caleb Ugent
Date Due: 10/14/15
Assignment: calculates the size of the tree
Takes: a node
Returns: returns a unsigned
***************************************************/

unsigned binTree::size(Node* ptr) const
{
	if (ptr == NULL)
	{
		return 0;
	}
	else
		return size(ptr->left) + size(ptr->right) + 1;
}
#endif

