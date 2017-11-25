#include <iostream>
#include "parser.h"
#include "data_type.h"
using namespace std;
int main() {
  Parser parser;
  Formula* formula = parser.start_parser();
  formula->print_formula();
  return 0;
}
