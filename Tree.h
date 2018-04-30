#ifndef TREE_H
#define TREE_H

#include <string>
#include <queue>


using namespace std;

struct node
{
	string letter;
	node * left;
	node * right;
};

class tree
{
	node *root;

public:
	tree();

	node* get_root(); // returns the root node
	void addLetter(string line, node* start); // adds the letter from file and calls createNewNode to store it
	node* createNewNode(node* newNode); // creates the node the store the letter and returns it
};


#endif