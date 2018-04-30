#include "Functions.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>


// reads txt and adds each line to a queue
queue<string> input_from_file()
{
	queue<string> q;
	string in;
	ifstream fin("morse.txt"); // object to input from the file

	while (fin.good())
	{
		fin >> in;
		q.push(in);
	}
	fin.close();

	return q; // returns queue for to be read by the tree and map
}


// gets user input and calls encode/decode functions
void user_input(tree m_tree, map<string, string> m_map)
{
	while (true)
	{
		cout << "Choose Encoding(1), Decoding(2), or Exit(3): ";
		string x;
		getline(cin, x);

		if (x == "1")
		{
			cout << "Please enter the word to encode:" << endl;
			string to_encode;
			getline(cin, to_encode);
			lowercase(to_encode);
			encode(m_map, to_encode);
		}
		if (x == "2")
		{
			cout << "Please enter the Morse code to decode (use a space between letters):" << endl;
			string to_decode;
			getline(cin, to_decode);
			lowercase(to_decode);
			decode(m_tree, to_decode);
		}
		if (x == "3")
		{
			delete_tree(m_tree.get_root()); // traverse Morse Tree and delete each node
			exit(0);
		}
		else
		{
			continue;
		}
	}
}

// converts user input to lowercase
void lowercase(string& input)
{
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = tolower(input[i]);
	}
}


// builds tree from queue for decoding
void build_tree(tree& morseTree, queue<string> q)
{
	node* root = morseTree.get_root();
	int size = q.size();

	for (int i = 0; i < size; i++)
	{
		string text = q.front();
		morseTree.add_letter(text, root); // creates node for letter
		q.pop();
	}
	//printInorder(root);
}


// uses tree to efficiently convert Morse code to letters
void decode(tree& m_tree, string x)
{
	node* p = m_tree.get_root();
	queue <node*> n_pt;
	n_pt.push(p);

	int i = 0;
	while (i < x.length())
	{
		if (x[i] == '.')
		{
			n_pt.push(n_pt.front()->left);
			n_pt.pop();
			i++;
		}
		else if (x[i] == '_')
		{
			n_pt.push(n_pt.front()->right);
			n_pt.pop();
			i++;
		}
		else if (x[i] == ' ')
		{
			n_pt.push(p);
			cout << n_pt.front()->letter;
			n_pt.pop();
			i++;
		}

		else if (isalpha(x[i]))
		{
			cout << endl << "Error: '" << x[i] << "' is a letter, not Morse code." << endl;
			break;
		}
		
		else
		{
			cout << "Error: " << x[i] << " is not defined." << endl;
			break;
		}

	}
	cout << n_pt.front()->letter << endl;
}


// deletes dynamic nodes of the tree
void delete_tree(node* root)
{
	if (root == NULL)
	{
		return;
	}

	delete_tree(root->left);
	delete_tree(root->right);
	//cout << "Deleting " << root->letter << endl;
	delete root;
}


// builds map from queue for encoding
void build_map(map<string, string>& m_map, queue <string> q)
{
	int size = q.size();

	for (int i = 0; i < size; i++)
	{
		string input = q.front();
		m_map.insert(pair<string, string>(input.substr(0, 1), input.substr(1, input.length())));
		q.pop();
	}
}


// prints map of Morse code and letters
void print_map(map<string, string>& m_map)
{
	cout << endl << "Morse Code Table" << endl;
	int count = 0;

	for (map<string, string>::iterator iter = m_map.begin(); iter != m_map.end(); ++iter)
	{
		cout << iter->first << "= " << iter->second << "\t";
		count++;
		if (count == 13)
		{
			cout << endl;
		}
	}
	cout << endl << endl;
}


// uses the map to encode
void encode(map<string, string> m_map, string word)
{
	string encoded = "";
	string space = " ";

	for (int i = 0; i < word.length(); i++)
	{
		bool found = false; // toggle to display errors

		for (map<string, string>::iterator iter = m_map.begin(); iter != m_map.end(); ++iter)
		{
			if (iter->first == word.substr(i, 1))
			{
				encoded.append(iter->second);
				encoded += space;
				found = true;
				break;
			}
		}

		if (found == false) // if the letter is not found, display the appropriate error
		{
			if ((word.substr(i, 1) == "." || word.substr(i, 1) == "_"))
			{
				cout << endl << "Error: '" << word.substr(i, 1) << "' is Morse code, not a letter." << endl;
				break;
			}

			else
			{
				cout << endl << "Error: '" << word.substr(i, 1) << "' is not defined." << endl;
				break;
			}
		}
	}
	cout << encoded << endl;
}


// prints the tree with preorder traversal
void printPreorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->letter << endl;
	printPreorder(root->left);
	printPreorder(root->right);
}

// prints the tree with inorder traversal
void printInorder(node* root)
{
	if (root == NULL)
	{
		return;
	}

	printInorder(root->left);
	cout << root->letter << endl;
	printInorder(root->right);
}