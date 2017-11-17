#include <iostream>
#include <vector>
#include <string>

#include "data_type.h"

using namespace std;

Clause::Clause(int n) {

  data = new int[n];

}


Clause::Clause():
void Clause::pop() {
  p--;
  size--;
  delete data[p+1];
}

void Clause::push(int i) {
  auto old_data = data;
  data = new int[(p+1)+1];
  for (int i = 0; i <= p; i++) {
    data[i] = old_data[i];
  }
  data[p+1] = i;
  delete old_data;
  size++;
}

Formula::Formula(int n, int m) {

  n_clauses = n;
  max_lit = m;
  formula = new Clause[n_clauses][max_lit1];
  
}

void Formula::pop() {

  p--;
  size--;
  delete formula[p+1];

}

void Formula::push() {

  auto old_formula = formula;
  new_formula = new Clause[n+1]

  



// Given a target Node* and
// a available Node*
// Create an exact copy of the target pointer
// to the available Node*

void copy_create(Node* target, Node* new_root) {
  if ( target != nullptr ) {
    
    new_root->id = target->id;

  }

  if ( target->left != nullptr ) {

    new_root->left = new Node();

    copy_create(target->left, new_root->left);

  }

  if ( target->right != nullptr ) {

    new_root->right = new Node();

    copy_create(target->right, new_root->right);

  }

}

void copy_create(Id_Node* target, Id_Node* new_root) {

  if ( target != nullptr ) {

    new_root->id = target->id;

  }

  if ( target->left != nullptr ) {

    new_root->left = new Id_Node();

    copy_create(target->left, new_root->left);

  }

  if ( target->right != nullptr ) {

    new_root->right = new Id_Node();

    copy_create(target->right, new_root->right);

  }

}


void walk_print_tree_helper(Node* root) {

  if ( root->left != nullptr ) {

    walk_print_tree_helper(root->left);

  }

  cout << root->id << endl;

  if ( root->right != nullptr ) {

    walk_print_tree_helper(root->right);

  }
}


void walk_print_tree_helper(Id_Node* root) {

  if ( root->left != nullptr ) {

    walk_print_tree_helper(root->left);

  }

  cout << root->id << endl;

  if ( root->right != nullptr ) {

    walk_print_tree_helper(root->right);

  }
}



void walk_print_tree(Node* root) {

  cout << "Printing tree" << endl;

  if ( root == nullptr ) {

    cout << "Tree is empty" << endl;

    return;

  }

  walk_print_tree_helper(root);

  cout << endl;

}



void walk_print_tree(Id_Node* root) {

  cout << "Printing tree" << endl;

  if ( root == nullptr ) {

    cout << "Tree is empty" << endl;

    return;

  }

  walk_print_tree_helper(root);

  cout << endl;

}

void add_node_left_left_on_new(Id_Node* root, Id_Node* new_node) {

  new_node->parent = root;

  new_node->left = root->left;

  if ( root->left != nullptr ) {

    root->left->parent = new_node;

  }

  root->left = new_node;

}

void add_node_left_left_on_new(Node* root, Node* new_node) {

  new_node->parent = root;

  new_node->left = root->left;

  if ( root->left != nullptr ) {

    root->left->parent = new_node;

  }

  root->left = new_node;

}


// Note: the next node of the root
// is still the added to the left side
// of the new node
void add_node_right_left_on_new(Id_Node* root, Id_Node* new_node) {

  new_node->parent = root;

  new_node->left = root->right;

  if ( root->right != nullptr ) {

    root->right->parent = new_node;

  }

  root->right = new_node;

}

void add_node_right_left_on_new(Node* root, Node* new_node) {

  new_node->parent = root;

  new_node->left = root->right;

  if ( root->right != nullptr ) {

    root->right->parent = new_node;

  }

  root->right = new_node;

}


void add_node_right_right_on_new(Id_Node* root, Id_Node* new_node) {

  new_node->parent = root;

  new_node->right = root->right;

  if ( root->right != nullptr ) {

    root->right->parent = new_node;

  }

  root->right = new_node;

}

void add_node_right_right_on_new(Node* root, Node* new_node) {

  new_node->parent = root;

  new_node->right = root->right;

  if ( root->right != nullptr ) {

    root->right->parent = new_node;

  }

  root->right = new_node;

}

void remove_not_node(Id_Node* not_node) {

  if ( not_node->parent != nullptr ) {

    if ( not_node == not_node->parent->left ) {

      not_node->left = not_node->parent;

      not_node->parent->left = not_node->left;

      not_node->left->parent = not_node->parent;

      delete not_node;

    } else {

      not_node->left = not_node->parent;

      not_node->parent->right = not_node->left;

      not_node->left->parent = not_node->parent;

      delete not_node;

    }

  } else {


    not_node->left->parent = nullptr;

    delete not_node;

  }

}



void remove_not_node(Node* not_node) {

  if ( not_node->parent != nullptr ) {

    if ( not_node == not_node->parent->left ) {

      not_node->left = not_node->parent;

      not_node->parent->left = not_node->left;

      not_node->left->parent = not_node->parent;

      delete not_node;

    } else {

      not_node->left = not_node->parent;

      not_node->parent->right = not_node->left;

      not_node->left->parent = not_node->parent;

      delete not_node;

    }

  } else {


    not_node->left->parent = nullptr;

    delete not_node;

  }

}
