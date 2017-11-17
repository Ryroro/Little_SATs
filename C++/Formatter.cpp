#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Formatter.h"
#include "data_type.h"
#include "Encoder.h"

using namespace std;

vector<string> binary_connectives = { "and",
				      "or",
				      "imply",
				      "iff" };

vector<string> unary_connectives = { "not" };

bool is_binary_connective(const string& s) {

  return find( binary_connectives.begin(),
	       binary_connectives.end(),
	       s ) != binary_connectives.end();
  
}

bool is_unary_connective(const string& s) {

  return find( unary_connectives.begin(),
	       unary_connectives.end(),
	       s ) != unary_connectives.end();
  

}

// Given input string, add spaces before and after the brackets
// for further parsing
void format(string& s, vector<string>& tokens) {

  auto begin = s.begin();
  auto end = s.end();

  while ( begin != end ) {

    string temp_s;

    if ( *begin == '(' || *begin == ')' ) {

      temp_s.push_back(*begin);

      begin++;

      tokens.push_back(temp_s);

    } else if ( isspace(*begin) ) {

      begin++;

    } else {

      while ( *begin != '(' && *begin != ')' && !isspace(*begin) && begin != end ) {

	temp_s.push_back(*begin);

	begin++;

      }

      tokens.push_back(temp_s);

    }

  }

}

void build_tree(vector<string>& tokens, Id_Node* root) {

  Encoder encoder;
  
  auto begin = tokens.begin();
  auto end = tokens.end();

  Id_Node* cur = root;

  while ( begin != end ) {

    if ( *begin == "(" ) {

      if ( *(begin+1) == "not" ) {

	cur->left = new Id_Node();
	cur->left->parent = cur;

      } else {

        cur->left = new Id_Node();
        cur->right = new Id_Node();
        cur->left->parent = cur;
        cur = cur->left;

      }
      
    } else if ( *begin == ")" ) {

      cur = cur->parent;

    } else if ( is_binary_connective(*begin) ) {

      cur->id = encoder.encode(*begin);
      cur->right->parent = cur;
      cur = cur->right;

    } else if ( is_unary_connective(*begin) ) {

      cur->id = encoder.encode(*begin);

      cur = cur->left;

     } else {


      cur->id = encoder.encode(*begin);

      cur = cur->parent;

     }

      begin++;

  }
}



void build_tree(vector<string>& tokens, Node* root) {

  auto begin = tokens.begin();
  auto end = tokens.end();

  Node* cur = root;

  while ( begin != end ) {

    if ( *begin == "(" ) {

      if ( *(begin+1) == "not" ) {

	cur->left = new Node();
	cur->left->parent = cur;

      } else {

        cur->left = new Node();
        cur->right = new Node();
        cur->left->parent = cur;
        cur = cur->left;

      }
      
    } else if ( *begin == ")" ) {

      cur = cur->parent;

    } else if ( is_binary_connective(*begin) ) {

      cur->id = *begin;
      cur->right->parent = cur;
      cur = cur->right;

    } else if ( is_unary_connective(*begin) ) {

      cur->id = *begin;

      cur = cur->left;

     } else {


        cur->id = *begin;

	cur = cur->parent;

     }

      begin++;

  }
}
