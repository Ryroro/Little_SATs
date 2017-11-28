#include <iostream>
#include <sstream>
#include "data_type.h"
#include "dpll.h"
#include "parser.h"
using namespace std;

Formula bcp(Formula formula) {
 
  auto formula_begin = formula.begin();
  auto formula_end = formula.end();

  int count = 0;

  while (formula_begin != formula_end) {

    bool exist = false;
    Clause clause;
    int id;
    bool top_formula_being_changed = false;

    if ((*formula_begin).size() == 1) {
      id = -((*formula_begin).get_id(0));
      cout << "The id being examined is " << id << endl;
      formula_end = formula.end();

      // remove the literals with the id in all formula

      auto temp_begin = formula.begin();
      auto temp_end = formula.end();

      while (temp_begin != temp_end) {
	bool update = false; // whether temp_begin is changed in other condition
	if ((*temp_begin).is_elem(id)) {
	  clause = *temp_begin;
	  (*temp_begin).erase_elem(id); // remove the id from the  clause
	  top_formula_being_changed = true;

	  if ((*temp_begin).size() == 0) {
	    temp_begin = formula.erase(temp_begin);
	    temp_end = formula.end();
	    update = true;
	  }

	  exist = true;

	}

	if ((*temp_begin).size() == 1 && ((*temp_begin).get_id(0) == -id ||
					(*temp_begin).get_id(0) == id)) {
	  temp_begin = formula.erase(temp_begin);
	  temp_end = formula.end();
	  update = true;
	}

	if (!update) {
	  temp_begin++;

	}
      }
        if (!exist) {
	  Lit lit = Lit(-id);
	  Clause c = Clause();
	  c.push_back(lit);
	  cout << "id of this one " << id << " doesn't exist" << endl;
	  formula.push_back(c);
	  formula.print_formula();
	  formula_end = formula.end();
	}
    }

    if (!formula.elem_exist(id)) {
      formula.delete_var(id);
    }

    
    if (!top_formula_being_changed) {
      formula_begin++;
    } else {
      formula_begin = formula.begin();
    }
    cout << "step " << count << endl;
    formula.print_formula();
    count++;
    
  }

  cout << "BCP ENDS" << endl;

  return formula;

  
	    

}

Formula plp(Formula f) {

  map<int, int> track_map;
			
  auto v_begin = f.variable_list.begin();
  auto v_end = f.variable_list.end();

  while (v_begin != v_end) {
    track_map.push_back(make_pair(*v_begin,0));
    track_map.push_back(make_pair(-(*v_begin), 0));
    v_begin++;
  }

  while (f_begin != f_end) {

    auto clause_begin = (*f_begin).variable_list.begin();
    auto clause_end = (*f_end).variable_list.end();

    VariableList vars;

    while (clause_begin != clause_end) {
      vars.push_back(*clause_begin);
      clause_begin++:
    }

    auto n_vars_begin = vars.begin();
    auto n_vars_end = vars.end();

    while (n_vars_begin != n_vars_end) {
      track_map[*n_vars_begin]++;
      n_vars_begin++:
    }

    f_begin++;
  }

  v_begin = f.variable_list.begin();
  v_end = f.variable_list.end();

  while (v_begin != v_end) {
    if (track_map[*v_begin] >= min_occur) {
      auto d_iter = f.decision_table.get(*v_begin);

      if (*v_begin > 0) {
        (*d_iter).second = true;
      } else {
	(*d_iter).second = false;
      }
    
    }
    if (track_map[-(*v_begin)] >= min_occur) {

      if (*v_begin > 0) {
	(*d_iter).second = false;
      } else {
	(*d_iter).second = true;
      }
  
    }
    v_begin++;
  }
}

      



int simple_choose_var(Formula& formula) {
  cout << "in SIMPLE_CHOOSE_VAR" << endl;
  
  int i = *(formula.variable_list.iter);
  formula.variable_list.iter++;
  cout << "VARIABLE CHOSEN IS " << i << endl;
  cout << "SIMPLE-CHOOSE_VAR ENDS" << endl;
  return i;
}
  
  

Formula dpll(Formula formula) {
  cout << "in DPLL" << endl;
  Formula updated_formula = bcp(formula);
  updated_formula.update_variable_list();
  updated_formula.variable_list.update_iter();
  updated_formula.eval();

  if (updated_formula.result == 1) {
    return updated_formula;
  } else if (updated_formula.result == 0) {
    return updated_formula;
  }
  int p = simple_choose_var(updated_formula);
  Formula p_true_f = updated_formula;
  p_true_f.decision_table.push_back(make_pair(p,true));
  p_true_f = dpll(p_true_f);
  p_true_f.eval();
  if (p_true_f.result == 1) {
    return p_true_f;
  } else {
    Formula p_false_f = updated_formula;
    p_false_f.decision_table.push_back(make_pair(p,false));
    p_false_f = dpll(p_false_f);
    p_false_f.eval();
    return p_false_f;
  }
}


// test bcp
void test_case1() {
  
  Parser parser;
  Formula formula;
  string test = "4 3 1 0 -1 2 0 -1 -2 3 0";
  int exp_result = 1;
  istringstream input(test);
  formula = parser.start_parser(input);
  //formula = bcp(formula);
  formula.variable_list.update_iter();
  formula.print_formula();
  formula = dpll(formula);

  if (formula.result == exp_result) {
    
  if (formula.result == 1) {
    cout << "SAT" << endl;
  } else {
    cout << "UNSAT" << endl;
  }
  
  }
}

void test_bcp() {
  Parser parser;
  Formula formula;
  vector<string> test_cases =
    { "4 3 1 0 -1 2 0 -1 -2 3 0"};
  auto begin = test_cases.begin();
  auto end = test_cases.end();

}
  
  

int main() {


  test_case1();
  return 0;
  


}
