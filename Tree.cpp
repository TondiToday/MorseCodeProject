#include "Tree.h"


node * tree::get_root()
{
	return root;
}


tree::tree()
{
	root = new node;
	root->letter = " ";
	root->left = NULL;
	root->right = NULL;
}


// adds the letter from file and calls create_new_node to store it
void tree::add_letter(string line, node* root)
{
	node* current = root;

	for (int i = 1; i < line.length(); i++)
	{
		if (line[i] == '.') // go left
		{
			if (current->left == NULL) // if there isn't a node to the left, create one
			{
				current->left = create_new_node(current->left);
			}
			current = current->left;
		}

		else if (line[i] == '_') // go right
		{
			if (current->right == NULL) // if there isn't a node to the right, create one
			{
				current->right = create_new_node(current->right);
			}
			current = current->right;
		}
	}
	current->letter = line[0]; // adds letter (the first character of the line from the txt) to the node
}


// creates the node the store the letter and returns it
node* tree::create_new_node(node* newNode)
{
	newNode = new node;
	newNode->letter = " ";
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}