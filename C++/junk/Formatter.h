#ifndef _FORMATTER_H_
#define _FORMATTER_H_

#include <vector>
#include <string>
#include "data_type.h"

using namespace std;

bool is_binary_connective(const string&);

bool is_unary_connective(const string&);

void format(string&, vector<string>&);

void build_tree(vector<string>& , Node*);

void build_tree(vector<string>&, Id_Node*);

#endif 
