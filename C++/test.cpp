#include <iostream>
#include <vector>
#include <string>
#include "data_type.h"
#include "Formatter.h"
#include "Transformation.h"
#include <assert.h>

using namespace std;

string input1 = "(a and b)";
string input2 = "((a and b) or c)";
string input3 = "(c or ((not a) or c)";
string input4 = "(c imply b)";
string input5 = "(c or (b imply d))";
string input6 = "(c iff d)";
string input7 = "(a and b)";
string input8 = "(not (not a))"; // test eliminate_not function 
string input9 = "((a and b) or c)"; // test push_or_below_and function
  

void test_case1() {

  cout << "------------TEST CASE 1-----------------" << endl;

  cout << endl;
  cout << "--TEST CASE INPUT-- : " << input1 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input1, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree(Node*) " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree(Node*)" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case2() {


  cout << "------------TEST CASE 2-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input2 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input2, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  
  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;


  cout << "---------------------------------------" << endl;

  cout << endl;

}


void test_case3() {


  cout << "------------TEST CASE 3-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input3 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input3, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case4() {


  cout << "------------TEST CASE 4-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input3 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input4, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  eliminate_imply(id_node);

  cout << "--TASK 6-- : Finish eliminate_imply(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 7-- : Finish walk_print_tree(Id_Node*)" << endl;


  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case5() {


  cout << "------------TEST CASE 5-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input5 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input5, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  eliminate_imply(id_node);

  cout << "--TASK 6-- : Finish eliminate_imply(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 7-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case6() {


  cout << "------------TEST CASE 6-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input3 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input6, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  eliminate_iff(id_node);

  cout << "--TASK 6-- : Finish eliminate_iff(id_node)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 7-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case7() {

   cout << "------------TEST CASE 7-----------------" << endl;

  cout << "--TEST CASE INPUT--: " << input7 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();
  Id_Node* id_node2 = new Id_Node();

  format(input7, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree() " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree()" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  copy_create(id_node, id_node2);

  cout << "--TASK 6-- : Finish copy_create(Id_Node*)" << endl;

  walk_print_tree(id_node2);

  cout << "--TASK 7-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "-----------------------------------" << endl;

}

void test_case8() {

  cout << "------------TEST CASE 8-----------------" << endl;

  cout << endl;
  cout << "--TEST CASE INPUT-- : " << input8 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input8, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree(Node*) " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree(Node*)" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  eliminate_not(id_node);

  cout << "--TASK 6-- : Finish eliminate_not(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 7-- : Finish walk_print_tree(Id_Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}

void test_case9() {

  cout << "------------TEST CASE 9-----------------" << endl;

  cout << endl;
  cout << "--TEST CASE INPUT-- : " << input9 << endl;

  vector<string> ts;

  Node* node = new Node();
  Id_Node* id_node = new Id_Node();

  format(input9, ts);

  cout << "--TASK 1-- : Finish format()" << endl;

  build_tree(ts, node);

  cout << "--TASK 2-- : Finish build_tree(Node*) " << endl;

  walk_print_tree(node);

  cout << "--TASK 3-- : Finish walk_print_tree(Node*)" << endl;

  build_tree(ts, id_node);

  cout << "--TASK 4-- : Finish build_tree(Id_Node*)" << endl;

  walk_print_tree(id_node);

  cout << "--TASK 5-- : Finish walk_print_tree(Id_Node*)" << endl;

  push_or_below_and(node);

  cout << "--TASK 6--: Finish push_or_below_(Node*)" << endl;

  walk_print_tree(node);

  cout << "--TASK 7--: Finish walk_print_tree(Node*)" << endl;

  cout << "---------------------------------------" << endl;

  cout << endl;

}


int main() {

  test_case1();
  test_case2();
  test_case3();
  test_case4();
  test_case5();
  test_case6();
  test_case7();
  test_case8();
  test_case9();
  return 0;


}


