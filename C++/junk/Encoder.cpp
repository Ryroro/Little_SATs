#include <iostream>
#include "Encoder.h"
#include "Formatter.h"
#include "data_type.h"

using namespace std;

Encoder::Encoder(): id_count(0) {}


int Encoder::encode(const string& s) {

  if ( is_binary_connective(s) ) {

    return connectives_encoding_map[s];

  } else if ( is_unary_connective(s) ) {

    return connectives_encoding_map[s];

  } else {

    int index = 2*id_count;

    atom_encoding_map.insert(make_pair (index, s));

    id_count += 2;

    return index;

  }

}
