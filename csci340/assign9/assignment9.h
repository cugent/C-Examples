/****************************************************

Programmer: Caleb Ugent
Date: 11/27/2015
ZID: z1729481
Goal: To create a graph and move through it using the depth first search algorithm
*******************************************************/

#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class graph {
private:
	int size;
	std::vector< std::list <int> > adj_list;
	std::vector< char > labels;
	void depth_first(int) const;
public:
	graph(const char* filename);
	~graph();
	int get_size() const;
	void traverse() const;
	void print() const;
};

bool visited[7];
vector <char> start;
vector<char> end;


/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes:a filename
Returns:nothing 
Goal:creates the graph thats going to be used and sets all the default values
*****************************************/
graph::graph(const char* filename)
{
//cout << "this runs" << endl;
	string ignorechar;
	string item;
	ifstream myfile;


//Have to push a bunch of lists onto the vector
	list<int> ListA;
	list<int> ListB;
	list<int> ListC;
	list<int> ListD;
	list<int> ListE;
	list<int> ListF;
	list<int> ListG;
	adj_list.push_back(ListA);
	adj_list.push_back(ListB);
	adj_list.push_back(ListC);
	adj_list.push_back(ListD);
	adj_list.push_back(ListE);
	adj_list.push_back(ListF);
	adj_list.push_back(ListG);
	myfile.open(filename, ios::in);
	myfile >> size;
//	cout << size << ":" << endl;
//	cout << "got past open" << endl;

//                 cout << "this runs";
		//The first number is the size so read it in this is the number if edges

		//Read the top row to get the labels
		for (int x = 0; x < 7; x++)
		{
//cout << "for lop attempted" << endl;
			myfile >> item;
			labels.push_back(item[0]);
			
                        //cout << "..." ;
//			cout << labels[x] << endl;;
		}

		//there is going to be 7 rows down so start here
		for (int y = 0; y < size ; y++)
		{
			myfile >> ignorechar;
			//adj_list.push_back(ignorechar);
			//Since the label is counted read 8 numbers in 
			for (int z = 0; z < size; z++)
			{
				//Read an item in from the file
				myfile >> item;
//cout << item << endl;
				//If it doesnt == 1 it means its not there so continue the loop
				if (item != "1")
				{
					continue;
				}
				//Else it is there so you need to push the item onto that lists specific spot and the way to do that is usign the vector of labels spot if its 1 then its there
				else
				{
                                   //     cout << "1 ran" << "z = " << z<< "y = " << y << endl;
					adj_list[y].push_back(z);
				}
			}

		}
	
//cout << "skipped loop" << endl;
	myfile.close();
	//print();
}
/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes: nothing
Returns: nothing
Goal: deconstructs the variables
*****************************************/

graph::~graph()
{
adj_list.clear();
labels.clear();

size = 0;


}


/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes:an int v
Returns:nothing
Goal:To search through the graph using the depth first search algorithm
*****************************************/

void graph::depth_first(int v) const
{

//Set the current vertice to true
visited[v] = true;

//Output that Label
cout << labels[v] << " ";

//Iterate through the list
list<int>::const_iterator graphit;

for (graphit = adj_list[v].begin(); graphit != adj_list[v].end(); ++graphit)
{
int w = *graphit;
 
//If that has not been visited 
if (!visited[w])
{
//Push where we started and where we are onto two seperate vectors
end.push_back(labels[w]);
start.push_back(labels[v]);
//Call itself
depth_first(w);
}

}
}

/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes: nothing
Returns: an int
Goal: returns the size of the graph in vertices
*****************************************/

int graph::get_size() const
{

	return size;
}

/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes:nothing
Returns:nothing
Goal: prints teh contents of the graph
*****************************************/

void graph::print() const
{
	//cout << "this ran";
cout << "Number of vertices: " << get_size() << endl << endl;

cout << "-------- graph -------" << endl;
	//This creates an iterator
	list<int>::const_iterator it;

	//This starts at each row of the list table and prints whatever x is in the label vector
	for (int x = 0; x < size; x++)
	{
		cout << labels[x] << ": ";

		//This iterates through that specific row and prints the contents.
		for (it = adj_list[x].begin(); it != adj_list[x].end(); ++it)
		{
			cout << labels[*it] << ", ";
		}
		cout << endl;
	}
cout << "------- end of graph ------" << endl << endl;

}
/****************************************
Programmer: Caleb Ugent
Date: 11/27/2015
Takes: nothing
Returns: nothing
Goal: to guide depth first into going through the graph properly
*****************************************/

void graph::traverse() const
{

cout << "------- traverse of graph ------" << endl;

//Go through and see if each are visited if not start there
for (int x = 0; x < size; x++)
{
if (visited[x] != true)
{
//Call depth first
depth_first(x);
}
}
cout << endl;

//Print out all the edges the depth first has taken 
for (unsigned int x = 0; x < end.size(); x++)
{

cout << "(" << start[x] << ", " << end[x] << ")  ";

}
cout << endl << "--------- end of traverse -------" << endl;
}






#endif

