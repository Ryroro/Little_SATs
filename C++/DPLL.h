#ifndef _DPLL_H_
#define _DPLL_H_
#include <iostream>
using namespace std;

void get_cnf_input() {
  
  cout << "Enter the number of clauses in the cnf" << endl;

  int n_clauses;
  cin >> n_clauses;

  cout << "Enter the maximum number of clauses contained in a literal" << endl;
  
  int max_lit;
  cin >> max_lit;

  Formula f;
  f.formula = new Clause[n_clauses];
  for (int i = 0; i < n_clauses; i++) {
    f.formula[i] = 
    

};
  

#endif
