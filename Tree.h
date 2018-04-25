#ifndef TREE_H
#define TREE_H





#include <iostream>
#include <fstream>
#include <string>
#include <queue>




using namespace std;

struct node
{
	string letter;
	string symbol;
	node * left;
	node * right;
};

class tree
{
	node *root;

public:
	tree();

	node* get_root();
	void createLeaf(string letter, string symbol, node *ptr);
};


#endif