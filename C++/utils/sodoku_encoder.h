#include <iostream>


using namespace std;

class Sodoku_Encoder{
 public:
  Sodoku_Encoder() {}
  void get_problem();
  void encode();
  // encode the situation into variables
  // and record the result in the decision table
  void transform();
  
  int num_row = 9;
  int num_col = 9;
  int num_var = 9;
  int*** grid;
  //Formula formula;
  VariableList variable_list;
  DecisionTable decision_table;

};

