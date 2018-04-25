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
	void creatLeaf(string letter, string symbol, node *ptr);
};
node * tree::get_root()
{
	return root;
}
tree::tree()
{
	root = new node;
	root->letter = " ";
	root->symbol = " ";
	root->left = NULL;
	root->right = NULL;
}
void tree::creatLeaf(string let, string sy, node *ptr)
{
	ptr->symbol = sy;
	ptr->letter = let;
	ptr->left = NULL;
	ptr->right = NULL;
}
