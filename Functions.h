#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Tree.h"
#include <map>


// Misc functions
queue<string> input_from_file(); // reads txt and adds each line to a queue
void user_input(tree m_tree, map<string, string> m_map); // gets user input and calls encode/decode functions
void lowercase(string& input); // converts user input to lowercase


// Tree functions
void build_tree(tree& m_tree, queue<string> q); // builds tree from queue for decoding
void decode(tree& m, string x); // uses tree to efficiently convert Morse code to letters
void delete_tree(node* root); // deletes dynamic nodes of the tree


// Map functions
void build_map(map<string,string>& m_map, queue <string> q); // builds map from queue for encoding
void print_map(map<string, string>& m_map); // prints map of Morse code and letters
void encode(map<string, string> m_map, string x); // uses the map to encode


// Debug
void printPreorder(node* root); // prints the tree with preorder traversal
void printInorder(node* root); // prints the tree with inorder traversal


#endif
