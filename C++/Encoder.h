#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Encoder {
 public:
  Encoder();
  int encode(const string&);

 private:
  int id_count;
  map<string, int> connectives_encoding_map =
    { make_pair ("not", -1),
      make_pair ("and", -2),
      make_pair ("or", -3),
      make_pair ("imply", -4),
      make_pair ("iff", -5)
    };

  map<int, string> atom_encoding_map;
  

};

#endif
