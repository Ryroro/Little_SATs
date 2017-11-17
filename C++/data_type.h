#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

#include <iostream>
#include <string>
#include <vector>


using namespace std;

extern vector<string> binary_connectives;
extern vector<string> unary_connectives;


class Node {
 public:
  Node(){}
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  string id;

};

class Id_Node {
 public:
  Id_Node() {}
  Id_Node* left = nullptr;
  Id_Node* right = nullptr;
  Id_Node* parent = nullptr;
  int id;
};

class Clause {
 public:
  Clause() {}
  Clause(int n);
  int* data = nullptr;
  int p = 0;
  int size = 0;
  void pop();
  void push(int);
};

class Fomula {
 public:
  Formula() {}
  Formula(int, int) {}
  int p = 0;
  int size = 0;
  Clause** formula = nullptr;
  void pop();
  void push(Clause*);
  int max_lit;
  int n_clauses;
};

void copy_create(Node*, Node*);
void copy_create(Id_Node*, Id_Node*);

void walk_print_tree(Node*);
void walk_print_tree(Id_Node*);

void walk_print_tree_helper(Node*);
void walk_print_tree_helper(Id_Node*);

void add_node_left_left_on_new(Id_Node*, Id_Node*);
void add_node_left_left_on_new(Node*, Node*);

void add_node_right_left_on_new(Id_Node*, Id_Node*);
void add_node_right_left_on_new(Node*, Node*);

void add_node_right_right_on_new(Id_Node*, Id_Node*);
void add_node_right_right_on_new(Node*, Node*);

void remove_not_node(Id_Node*);
void remove_not_node(Node*);

void push_or_below_and(Id_Node*);
void push_or_below_and(Node*);
#endif
