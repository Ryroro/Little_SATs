#include <iostream>
using namespace std;

void Sodoku_Encoder::get_problem() {

  grid = new int[num_row][num_col][num_var];

  for (int r = 0; r < num_row; r++) {
    for (int c = 0; c < num_col; c++) {
      for (int v = 0; v < num_var; v++) {
	grid[r][c][v] = 0;
      }
    }
  }

  for (int r = 0; r < num_row; r++) {
    for (int c = 0; c < num_col; c++) {
      int i = 0;
      cin >> i;
      if (i != 0) {
	grid[r][c][i-1] = 1;
      }
    }
  }
  

}

void Sodoku_Encoder::encode() {

  for (int r = 0; r < num_row; r++) {
    for (int c = 0; c < num_col; c++) {
      for (int v = 0; v < num_var; v++) {
	
	int var = (r+1)*100 + (c+1)*10 + (v+1);
	variable_list.push_back(var);
	
	if (grid[r][c][v] == 1) {
	  decision_table.push_back(make_pair(var, true));
	}

      }
    }
  }
  
}

void Sodoku_Encoder::transform() {

  vector<Clause> temp_f1;

  for (int r = 0; r < num_row; r++) {
    for (int c = 0; c < num_col; c++) {
      for (int v = 0; v < num_var; v++) {
	for (int _v = v+1; _v < num_var; _v++) {
	  Clause clause;
	  Lit lit1;
	  Lit lit2;
	  lit1.id = (r+1)*100 + (c+1)*10 + (v+1);
	  lit2.id = (r+1)*100 + (c+1)*10 + (_v+1);
	  clause.push_back(-lit1);
	  clause.push_back(-lit2);
	  temp_f1.push_back(clause);
	}
      }
    }
  }

  vector<Clause> temp_f2;
  for (int r = 0; r < num_row; r++) {
    for (int v = 0; v < num_var; v++) {
      for (int c = 0; c < num_col; c++) {
	for (int _c = c+1; c < num_col; c++) {
	  Clause clause;
	  Lit lit1;
	  Lit lit2;
	  lit1.id = (r+1)*100 + (c+1)*10 + (v+1);
	  lit2.id = (r+1)*100 + (_c+1)*10 + (v+1);
	  clause.push_back(-lit1);
	  clause.push_back(-lit2);
	  temp_f2.push_back(clause);
	}
      }
    }
  }

  vector<Clause> temp_f3;
  for (int c = 0; c < num_col; c++) {
    for (int v = 0; v < num_var; v++) {
      for (int r = 0; r < num_row; r++) {
	for (int _r = 0; _r < num_row; _r++) {
	  Clause clause;
	  Lit lit1;
	  Lit lit2;
	  lit1.id = (r+1)*100 + (c+1)*10 + v;
	  lit2.id = (_r+1)*100 + (c+1)*10 + v;
	  temp_f3.push_back(clause);
	}
      }
    }
  }

  vector<Clause> temp_f4;
  for (int y_grid = 0; y_grid < 3; y_grid++) {
    for (int x_grid = 0; x_grid < 3; x_grid++) {
      for (int r_grid = 0; r_grid < 3; r_grid++) {
	for (int c_grid = 0; c_grid < 3; c_grid++) {
	  for (int v = 0; v < num_var; v++) {
	    Lit lit1;
	    Lit lit2;
	    
	  

  
  

}
