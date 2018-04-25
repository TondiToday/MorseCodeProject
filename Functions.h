#ifndef FUNCTIONS_H
#define FUNCTIONS_H



#include "Tree.h"
#include <map>

void encode(tree m, string x);
void decode(tree m, string x);
void find_symbol(node *n, string x, queue <string> &symbol_q);
void find_letter(node *n, string x, queue <string> & letter_q);
void load_tree(tree & m);
void user_input(tree m);
void print(queue<string> q);
void input_fromfile(queue <string> &q);
void build_map();
void print_map(map<string, string>& m_map);



#endif
