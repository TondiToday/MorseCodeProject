#include "Functions.h"
#include <iostream>

int main()
{
	tree morseTree; // tree to store the letters based on underscores and periods (decoding)
	map<string, string> morseMap; // map to store Morse code and letter equivalences (encoding)
	queue<string> q = input_from_file(); // queue to store each line of the input txt

	build_tree(morseTree, q); // builds dichotomous-style tree of the letters based on dots and dashes
	build_map(morseMap, q); // builds map of letters and Morse code equivalent
	print_map(morseMap); // displays map
	user_input(morseTree, morseMap); // gets user input and calls encode/decode functions
	cout << endl;

	system("pause");
	return 0;
}




