#ifndef _PARSER_H_
#define _PARSER_H_
#include <iostream>
#include <sstream>
#include "data_type.h"

using namespace std;
class Parser {
 public:
  Parser() {}
  Formula start_parser(); // get formula
  Formula start_parser(istringstream&);

};

#endif
