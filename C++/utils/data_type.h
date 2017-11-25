#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class VariableList {
 public:
  VariableList() {iter = vars.begin();}
  vector<int> vars;
  vector<int>::iterator iter;
  void push_back(int);
  void delete_var(int);
  void update_iter();

};

class DecisionTable {
 public:
  DecisionTable() {iter = decision_table.begin();}
  vector<pair<int,bool>>::iterator iter;
  bool empty();
  vector<pair<int, bool>> decision_table;
  void push_back(pair<int, bool>);
  vector<pair<int,bool>>::iterator get(int);
  

};

class Lit {
 public:
  Lit() {}
  Lit(int);
  int id;
  
};

class Clause {
 public:
  Clause() {}
  vector<Lit> clause;
  void push_back(Lit);
  void pop_back();
  int size();
  int get_id(int);
  bool is_elem(int);
  bool is_elem(Lit);
  void erase_elem(int);
  void erase_elem(Lit);
  vector<Lit>::iterator begin();
  vector<Lit>::iterator end();
  

};

class Formula {
 public:
  Formula() {}
  vector<Clause> formula;
  VariableList variable_list;
  DecisionTable decision_table;
  int result = -1;
  // -1 represents undetermined
  // 1 represents true
  // 0 represents false
  void push_back(Clause);
  void pop_back();
  void print_formula();
  int size();
  void erase_elem(vector<Clause>::iterator);
  vector<Clause>::iterator erase(vector<Clause>::iterator);
  bool elem_exist(int);
  void eval();
  void delete_var(int i);
  vector<Clause>::iterator begin();
  vector<Clause>::iterator end();
  vector<Clause>::iterator insert(vector<Clause>::iterator, Clause);

  void update_variable_list();
  
  
};

#endif
