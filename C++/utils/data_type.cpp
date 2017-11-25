#include <iostream>
#include <vector>
#include "data_type.h"
using namespace std;

bool operator==(const Lit& lit1, const Lit& lit2) {

  return lit1.id == lit2.id;

}


Lit::Lit(int n): id(n) {}


void Clause::push_back(Lit lit_p) {
  clause.push_back(lit_p);
}

void Clause::pop_back() {
  clause.pop_back();
}

int Clause::size() {
  return clause.size();
}

int Clause::get_id(int index) {
  return clause[index].id;
}

bool Clause::is_elem(int i) {
  auto begin = clause.begin();
  auto end = clause.end();
  while (begin != end) {
    if ((*begin).id == i) {
      return true;
    }
    begin++;
  }
  return false;
}

bool Clause::is_elem(Lit lit) {
  
  auto begin = clause.begin();
  auto end = clause.end();
  
  while (begin != end) {
    
    if (lit == *begin) {
      
      return true;
      
    }
    
    begin++;
  }
}

void Clause::erase_elem(int i) {
  
  auto begin = clause.begin();
  auto end = clause.end();

  while (begin != end) {
    if ((*begin).id == i) {
      begin = clause.erase(begin);
      end = clause.end();
    } else {
      begin++;
    }
  }
}

void Clause::erase_elem(Lit lit) {

  auto begin = clause.begin();
  auto end = clause.end();

  while (begin != end) {
    if (*begin == lit) {
      begin = clause.erase(begin);
      end = clause.end();
    } else {
      begin++;
    }
  }
}

vector<Lit>::iterator Clause::begin() {
  return clause.begin();
}

vector<Lit>::iterator Clause::end() {
  return clause.end();
}

/*
vector<Lit>::iterator Clause::erase(vector<Lit>::iterator it) {
  return clause.eras
*/


void Formula::push_back(Clause clause) {
  formula.push_back(clause);
}

void Formula::pop_back() {
  formula.pop_back();
}


void Formula::print_formula() {

  cout << "PRINTING FORMULA" << endl;
  auto formula_begin = formula.begin();
  auto formula_end = formula.end();
  int count = 1;
  
  while (formula_begin != formula_end) {
    
    auto clause_begin = (*formula_begin).begin();
    auto clause_end = (*formula_begin).end();

    cout << "clause " << count << endl;
    while ( clause_begin != clause_end) {
      cout << (*clause_begin).id << " ";
      clause_begin++;
    }
    cout << endl;
    
    formula_begin++;
    count++;
  }
      /*
  for (int i = 0; i < size; i++) {
    if (form
    int clause_size = formula[i]->size;
    formula[i]->reset();
    for (int j = 0; j < clause_size; j++) {
      if (formula[i]->clause[j] == nullptr) {
	break;
      }
      cout << formula[i]->clause[j]->id << " ";
    }
    cout << endl;
  }
      */
}

int Formula::size() {
  return formula.size();
}

void Formula::erase_elem(vector<Clause>::iterator iter) {
  formula.erase(iter);
}


vector<Clause>::iterator Formula::erase(vector<Clause>::iterator iter) {
  return formula.erase(iter);
}


bool Formula::elem_exist(int n) {
  auto formula_begin = formula.begin();
  auto formula_end = formula.end();
  while (formula_begin != formula_end) {
    if ((*formula_begin).is_elem(n)) {
      return true;
    }
    formula_begin++;
  }
  return false;
}

void Formula::eval() {
  cout << "EVALUATING FORMULA" << endl;
  auto formula_begin = formula.begin();
  auto formula_end = formula.end();

  bool is_eval_formula = false;
  bool formula_val = true;
  bool exist_undefined_clause = false;

  while (formula_begin != formula_end) {
    cout << "PART 1 " << endl;
    auto clause_begin = (*formula_begin).begin();
    auto clause_end = (*formula_begin).end();

    bool is_eval_clause = false;
    bool clause_val = false;
    bool exist_undefined_lit = false;
    
    while (clause_begin != clause_end) {
      cout << "PART 2" << endl;
      int id = (*clause_begin).id;
      cout << "PART 3" << endl;
      auto iter = decision_table.get(id);
      cout << "PART4 " << endl;
      if (iter != decision_table.decision_table.end()) {
	if ((*iter).second) {
	  is_eval_clause = true;
	  clause_val = true;
	  break;
	} else {
	  is_eval_clause = true;
	  clause_begin++;
	  continue;
	}
      } else {
	  exist_undefined_lit = true;
	  clause_begin++;
	continue;
      }
      clause_begin++;
      cout << "add clause_begin" << endl;
    }

    if (is_eval_clause) {
      is_eval_formula = true;
      if (clause_val) {
	formula_begin++;
	continue;
      } else {
	if (exist_undefined_lit) {
	  formula_begin++;
	  continue;
	} else {
	  formula_val = false;
	  break;
	}
      }
    } else {
      exist_undefined_clause = true;
      formula_begin++;
      continue;
    }
    formula_begin++;
    cout << "add formula_begin" << endl;

    
  }

  if (!formula_val) {
    result = 0;
  } else {
    if (is_eval_formula) {
    if (exist_undefined_clause) {
      result = -1;
    } else {
      result = 1;
    }
    } else {
      result = -1;
    }
  }
  cout << "EVALUATING FORMULA ENDS" << endl;
}


void Formula::delete_var(int id) {
  
  variable_list.delete_var(id);
  
}


vector<Clause>::iterator Formula::begin() {
  return formula.begin();
}

vector<Clause>::iterator Formula::end() {
  return formula.end();
}

vector<Clause>::iterator Formula::insert(vector<Clause>::iterator it, Clause clause) {
  return formula.insert(it, clause);
}

void Formula::update_variable_list() {
  cout << "UPDATE VARIABLE LIST" << endl;
  variable_list.vars.clear();
  auto formula_begin = formula.begin();
  auto formula_end = formula.end();
  while (formula_begin != formula_end) {
    auto clause_begin = (*formula_begin).begin();
    auto clause_end = (*formula_begin).end();
    while (clause_begin != clause_end) {
      variable_list.push_back((*clause_begin).id);
      clause_begin++;
    }
    formula_begin++;
  }
  cout << "UPDATE VARIABLE LIST ENDS" << endl;
}
      

void VariableList::push_back(int n) {
  if (find(vars.begin(), vars.end(), n) == vars.end()) {
    vars.push_back(n);
  }
}

void VariableList::delete_var(int n) {
  auto pos = find(vars.begin(), vars.end(), n);
  if ( pos != vars.end() ) {
    vars.erase(pos);
  }
}

void VariableList::update_iter() {
  cout << "UPDATE ITER" << endl;
  iter = vars.begin();
  cout << "UPDATE ITER" << endl;
}

void DecisionTable::push_back(pair<int,bool> p) {
  decision_table.push_back(p);
  
}


vector<pair<int, bool>>::iterator DecisionTable::get(int n) {
  auto begin = decision_table.begin();
  auto end = decision_table.end();
  while (begin != end) {
    if ((*begin).first == n) {
      return begin;
    }
    begin++;
  }
}

bool DecisionTable::empty() {
  return decision_table.empty();
}

/*
// temporary test
int main() {
  Formula* formula = new Formula(9);
  for (int i = 0; i < 9; i++) {
    Clause* clause = new Clause(9);
    for (int j = 0; j < 9; j++) {
      Lit* lit = new Lit(j);
      clause->push(lit);
    }
    formula->push(clause);
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << formula->formula[i]->clause[j]->id << " ";
    }
    cout << endl;
  }
  return 0;
}
    
*/
