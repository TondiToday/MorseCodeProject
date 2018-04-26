#include "Functions.h"




void input_fromfile(queue <string> &q)
{
	string in;
	ifstream fin("input.txt"); // object to input from the file

	while (fin.good())
	{
		fin >> in;
		if (in == "Null") // Null is added to the text file to make the tree a full tree
		{
			q.push(" ");
		}
		else
		{
			q.push(in);
		}
	}
	fin.close();
}

void build_tree(tree & m)
{
	queue <string> q;// to store the data from the file
	input_fromfile(q);
	node *p = m.get_root();
	queue <node*> nptr; //queue to store pointers to the node of the tree
	nptr.push(p);
	string x;
	for (int i = 0; i < 14; i++)
	{
		x = q.front();
		nptr.front()->left = new node;
		nptr.front()->right = new node;
		m.createLeaf(x.substr(0, 1), x.substr(1, x.length()), nptr.front()->left);
		nptr.push(nptr.front()->left);
		q.pop();
		x = q.front();
		m.createLeaf(x.substr(0, 1), x.substr(1, x.length()), nptr.front()->right);
		nptr.push(nptr.front()->right);
		q.pop();
		nptr.pop();
	}
}


void build_map(map<string, string>& m_map)
{
	string input;
	ifstream fin("input.txt");
	
	while (fin.good())
	{
		fin >> input;
		m_map.insert(pair<string, string>(input.substr(0, 1), input.substr(1, input.length())));
	}
	fin.close();

	// debug
	print_map(m_map);
}


void print_map(map<string, string>& m_map)
{
	cout << "Morse Code Table" << endl;

	for (map<string, string>::iterator iter = next(m_map.begin(),1); iter != m_map.end(); ++iter)
	{
		cout << iter->first << " = " << iter->second << endl;
	}
}


void find_letter(node *n, string x, queue <string> & letter_q)
/*Traverse the tree in order to find the letter and store the corresponding code to a queue*/
{
	if (n == NULL)
	{
		return;
	}
	if (n->left != NULL)
	{
		find_letter(n->left, x, letter_q);
	}
	if (x == n->symbol)
	{
		letter_q.push(n->letter);
	}
	if (n->right != NULL)
	{
		find_letter(n->right, x, letter_q);
	}
}

/*
void find_symbol(node *n, string x, queue <string> &symbol_q)
/Traverse the tree pre order to find the symbol and store the corresponding letter to a queue
{
	if (n == NULL)
	{
		return;
	}
	if (x == n->letter)
	{
		symbol_q.push(n->symbol);
	}
	if (n->left != NULL)
	{
		find_symbol(n->left, x, symbol_q);
	}

	if (n->right != NULL)
	{
		find_symbol(n->right, x, symbol_q);
	}
}
*/

void encode(map<string, string> m_map, string word)
{
	string encoded = "";

	for (int i = 0; i <= word.length(); i++)
	{
		for (map<string, string>::iterator iter = next(m_map.begin(), 1); iter != m_map.end(); ++iter)
		{
			if (iter->first == word.substr(i, 1))
			{
				encoded.append(iter->second);
			}
		}
	}
	cout << encoded << endl;
}

void decode(tree m, string x)
{
	node* p = m.get_root();
	queue <node*> n_pt;
	n_pt.push(p);
	int i = 0;
	while (i < x.length())
	{
		if (x.substr(i, 1) == ".")
		{
			n_pt.push(n_pt.front()->left);
			n_pt.pop();
			i++;

		}
		if (x.substr(i, 1) == "_")
		{
			n_pt.push(n_pt.front()->right);
			n_pt.pop();
			i++;
		}
		if (x.substr(i, 1) == " ")
		{

			n_pt.push(p);
			cout << n_pt.front()->letter;
			n_pt.pop();
			i++;
		}

	}
	cout << n_pt.front()->letter;

}
/*queue <string> letter_q;
int i = 0;
int j = 0;
while ( i< x.length () || j <= x.length())

{
j = x.find_first_of(" ", i);

find_letter(m.get_root(), x.substr(i, j), letter_q);


i += (j+1);
}
print(letter_q);*/


void user_input(tree m_tree, map<string, string> m_map)
{
	while (true)
	{
		cout << "Choose Encoding(1) or Decoding(2)" << endl;
		string x;
		getline(cin, x);

		if (x == "1")
		{
			build_map(m_map);
			cout << "Please enter the word to be encoded:" << endl;
			string to_encode;
			getline(cin, to_encode);
			encode(m_map, to_encode); // this function doesn't work right now
		}
		if (x == "2")
		{
			cout << "Please enter the Morse code to be decoded:" << endl;
			string to_decode;
			getline(cin, to_decode);
			decode(m_tree, to_decode);
		}

		else
		{
			cout << "Invalid input" << endl;
			continue;
		}
	}
}

void print(queue<string> q)
{
	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}
}