#include "Functions.h"



int main()
{

	tree morse; // tree to store the moris code
	load_tree(morse);// to store the data in the file to the tree
	user_input(morse);// to get the input from the user, decode/encode and the data to be encoded or decoded
	cout << endl;

	build_map(); // wrong place, needs to built if the user wants to encode, not before

	system("pause");
	return 0;
}




