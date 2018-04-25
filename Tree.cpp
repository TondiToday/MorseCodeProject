#include "Tree.h"


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
void tree::createLeaf(string let, string sy, node *ptr)
{
	ptr->symbol = sy;
	ptr->letter = let;
	ptr->left = NULL;
	ptr->right = NULL;
}