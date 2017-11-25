#include <iostream>
#include <sstream>
#include "parser.h"
#include "data_type.h"
using namespace std;

Formula Parser::start_parser() {
  int n_var; // the maximum number of literals in a clause
  int n_clause; // the number of clause
  cout << "input the maximum number of literals in a clause and the maximum number of literals" << endl;
  cin >> n_var >> n_clause;
  cout << "n_var is " << n_var << endl;
  cout << "n_clause is " << n_clause << endl;
  cout << "input the literals, 0 signature getting a new clause" << endl;
  

  Formula formula = Formula();
  formula.variable_list = VariableList();
  formula.decision_table = DecisionTable();
  
  for (int i = 0; i < n_clause; i++) {
    Clause clause = Clause();
    for (int j = 0; j < n_var; j++) {
      int l;
      cin >> l;
      if (l == 0) {
	break;
      }
      Lit lit = Lit(l);
      clause.push_back(lit);
      
      auto clause_begin = clause.begin();
      auto clause_end = clause.end();
      
      while (clause_begin != clause_end) {
	cout << (*clause_begin).id << " ";
	clause_begin++;
      }
      cout << endl;
      
      formula.variable_list.push_back(l);
    }
    formula.push_back(clause);
    cout << "size of this clause is " << clause.size() << endl;
  }

  auto fbegin = formula.begin();
  auto fend = formula.end();
  while (fbegin != fend) {
    auto cbegin = (*fbegin).begin();
    auto cend = (*fbegin).end();
    while (cbegin != cend) {
      cout << (*cbegin).id << " ";
      cbegin++;
    }
    cout << endl;
    fbegin++;
  }

  return formula;
}

Formula Parser::start_parser(istringstream& input) {
  int n_var; // the maximum number of literals in a clause
  int n_clause; // the number of clause
  cout << "input the maximum number of literals in a clause and the maximum number of literals" << endl;
  input >> n_var >> n_clause;
  cout << "n_var is " << n_var << endl;
  cout << "n_clause is " << n_clause << endl;
  cout << "input the literals, 0 signature getting a new clause" << endl;
  

  Formula formula = Formula();
  formula.variable_list = VariableList();
  formula.decision_table = DecisionTable();
  
  for (int i = 0; i < n_clause; i++) {
    Clause clause = Clause();
    for (int j = 0; j < n_var; j++) {
      int l;
      input >> l;
      if (l == 0) {
	break;
      }
      Lit lit = Lit(l);
      clause.push_back(lit);
      
      auto clause_begin = clause.begin();
      auto clause_end = clause.end();
      
      while (clause_begin != clause_end) {
	cout << (*clause_begin).id << " ";
	clause_begin++;
      }
      cout << endl;
      
      formula.variable_list.push_back(l);
    }
    formula.push_back(clause);
    cout << "size of this clause is " << clause.size() << endl;
  }

  auto fbegin = formula.begin();
  auto fend = formula.end();
  while (fbegin != fend) {
    auto cbegin = (*fbegin).begin();
    auto cend = (*fbegin).end();
    while (cbegin != cend) {
      cout << (*cbegin).id << " ";
      cbegin++;
    }
    cout << endl;
    fbegin++;
  }

  return formula;
}
