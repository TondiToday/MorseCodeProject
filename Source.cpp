#include "Functions.h"



int main()
{
	tree morseTree; // tree to store the morse code
	map<string, string> morseMap;

	build_tree(morseTree);// to store the data in the file to the tree
	user_input(morseTree, morseMap);// to get the input from the user, decode/encode and the data to be encoded or decoded
	cout << endl;

	system("pause");
	return 0;
}




