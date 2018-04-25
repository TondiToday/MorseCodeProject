# include "Header.h"

void encode(tree m, string x);
void decode(tree m, string x);
void find_symbol(node *n, string x, queue <string> &symbol_q);
void find_letter(node *n, string x, queue <string> & letter_q);
void load_tree(tree & m);
void user_input(tree m);
void print(queue<string> q);
void input_fromfile(queue <string> &q);

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

}

void load_tree(tree & m)
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
		m.creatLeaf(x.substr(0, 1), x.substr(1, x.length()), nptr.front()->left);
		nptr.push(nptr.front()->left);
		q.pop();
		x = q.front();
		m.creatLeaf(x.substr(0, 1), x.substr(1, x.length()), nptr.front()->right);
		nptr.push(nptr.front()->right);
		q.pop();
		nptr.pop();
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

void find_symbol(node *n, string x, queue <string> &symbol_q)
/*Traverse the tree pre order to find the symbol and store the corresponding letter to a queue*/
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

void encode(tree m, string x)

{
	queue <string> symbol_q;
	int i = 0;

	while (i < x.length())
	{
		find_symbol(m.get_root(), x.substr(i, 1), symbol_q);
		i++;
	}
	print(symbol_q);
}

void decode(tree m, string x)
{
	queue <string> letter_q;
	int i = 0;
	int j = 0;
	while ( i< x.length () || j <= x.length())
	
	{
		j = x.find_first_of(" ", i);

		find_letter(m.get_root(), x.substr(i, j), letter_q);
	
		
		i += (j+1);
	}
	print(letter_q);
}

void user_input(tree m)
{
	cout << "choose Encoding(1) or Decoding(2)" << endl;
	string x;
	getline(cin, x);
	if (x == "1")
	{
		cout << "please enter the word to be encoded" << endl;
		string enc;
		getline(cin, enc);
		encode(m, enc);
	}
	if (x == "2")
	{
		cout << "Please enter the symbols to be decoded" << endl;
		string decod;
		getline(cin, decod);
		decode(m, decod);
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