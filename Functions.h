#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Tree.h"
#include <map>

// Tree
void build_tree(tree & m);
void decode(tree m, string x);
void find_letter(node *n, string x, queue <string> & letter_q);
//void find_symbol(node *n, string x, queue <string> &symbol_q); 
void print(queue<string> q);
void input_fromfile(queue <string> &q);

void user_input(tree m_tree, map<string, string> m_map);

// Map
void build_map(map<string, string>& m_map);
void print_map(map<string, string>& m_map);
void encode(map<string, string> m_map, string x);





#endif
