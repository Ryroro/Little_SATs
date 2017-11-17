#include <iostream>
#include "Transformation.h"
#include "data_type.h"
using namespace std;


// the node passed in is the node with the
// id of imply
void eliminate_imply(Id_Node* id_node) {

  Id_Node* not_node = new Id_Node();
  not_node->id = -1;

  add_node_left_left_on_new(id_node, not_node);

  id_node->id = -3;

}

void eliminate_iff(Id_Node* id_node) {

  Id_Node* and_node1 = new Id_Node();
  and_node1->id = -2;
  Id_Node* and_node2 = new Id_Node();
  and_node2->id = -2;

  Id_Node* left_node_copy = new Id_Node();
  copy_create(id_node->left, left_node_copy);
  Id_Node* right_node_copy = new Id_Node();
  copy_create(id_node->right, right_node_copy);

  Id_Node* not_node1 = new Id_Node();
  not_node1->id = -1;
  Id_Node* not_node2 = new Id_Node();
  not_node2->id = -1;

  // Add to left hand side
  add_node_left_left_on_new(id_node, and_node1);

  add_node_right_right_on_new(id_node->left, right_node_copy);

  // Add to right hand node

  add_node_right_right_on_new(id_node, and_node2);

  add_node_left_left_on_new(id_node->right, not_node1);
  add_node_left_left_on_new(id_node->right->left, left_node_copy);
  add_node_right_left_on_new(id_node->right, not_node2);

  id_node->id = -3;

}

void eliminate_not(Id_Node*& id_node) {

  // For a correctly structured formula,
  // this formula should always be
  // evaluated true
  if ( id_node->left != nullptr ) {

    if ( id_node->left->id == -1 ) {

      auto sub_node = id_node->left->left;

      remove_not_node(id_node->left);

      remove_not_node(id_node);

      id_node = sub_node;


    } else if ( id_node->left->id == -2 ) {

      Id_Node* not_node1 = new Id_Node();
      not_node1->id = -1;
      Id_Node* not_node2 = new Id_Node();
      not_node2->id = -1;

      add_node_left_left_on_new(id_node->left, not_node1);
      add_node_right_left_on_new(id_node->left, not_node2);

      auto new_node = id_node->left;

      remove_not_node(id_node);

      id_node = new_node;
      id_node->id = -3;
      

    } else if ( id_node->right->id == -3 ) {

      Id_Node* not_node1 = new Id_Node();
      not_node1->id = -1;
      Id_Node* not_node2 = new Id_Node();
      not_node2->id = -1;

      add_node_left_left_on_new(id_node->left, not_node1);
      add_node_right_left_on_new(id_node->left, not_node2);

      auto new_node = id_node->left;

      remove_not_node(id_node);

      id_node = new_node;
      id_node->id = -3;
      

    } else {

      return;

    }

  }

}


void eliminate_not(Node*& id_node) {

  // For a correctly structured formula,
  // this formula should always be
  // evaluated true
  if ( id_node->left != nullptr ) {

    if ( id_node->left->id == "not" ) {

      auto sub_node = id_node->left->left;

      remove_not_node(id_node->left);

      remove_not_node(id_node);

      id_node = sub_node;


    } else if ( id_node->left->id == "and" ) {

      Node* not_node1 = new Node();
      not_node1->id = "not";
      Node* not_node2 = new Node();
      not_node2->id = "not";

      add_node_left_left_on_new(id_node->left, not_node1);
      add_node_right_left_on_new(id_node->left, not_node2);

      auto new_node = id_node->left;

      remove_not_node(id_node);

      id_node = new_node;
      id_node->id ="or";
      

    } else if ( id_node->right->id == "or" ) {

      Node* not_node1 = new Node();
      not_node1->id = "not";
      Node* not_node2 = new Node();
      not_node2->id = "not";

      add_node_left_left_on_new(id_node->left, not_node1);
      add_node_right_left_on_new(id_node->left, not_node2);

      auto new_node = id_node->left;

      remove_not_node(id_node);

      id_node = new_node;
      id_node->id = "or";
      

    } else {

      return;

    }

  }

}



// The id of the given node should be --or--

void push_or_below_and(Node* id_node) {

  if ( id_node->left->id == "and" ) {

    Node* copy1 = new Node();
    copy_create(id_node->left->left, copy1);
    Node* copy2 = new Node();
    copy_create(id_node->left->right, copy2);
    Node* copy3 = new Node();
    copy_create(id_node->right, copy3);

    Node* or_node = new Node();
    or_node->id = "or";

    id_node->id = "and";
    id_node->left->id = "or";

    id_node->left->right = copy3;
    copy3->parent = id_node->left;

    add_node_right_right_on_new(id_node, or_node);
    id_node->right->left = copy2;
    copy2->parent = id_node->right;
    // possibly a memory leak



  } else if ( id_node->right->id == "and" ) {

    Node* copy1 = new Node();
    copy_create(id_node->left, copy1);
    Node* copy2 = new Node();
    copy_create(id_node->right->left, copy2);
    Node* copy3 = new Node();
    copy_create(id_node->right->right, copy3);

    Node* or_node = new Node();
    or_node->id = "or";

    id_node->id = "and";
    id_node->right->id = "or";

    id_node->right->left = copy1;
    copy1->parent = id_node->right;

    add_node_left_left_on_new(id_node, or_node);
    id_node->left->right = copy2;
    copy2->parent = id_node->left;

  }


}


void push_or_below_and(Id_Node* id_node) {

  if ( id_node->left->id == -2 ) {

    Id_Node* copy1 = new Id_Node();
    copy_create(id_node->left->left, copy1);
    Id_Node* copy2 = new Id_Node();
    copy_create(id_node->left->right, copy2);
    Id_Node* copy3 = new Id_Node();
    copy_create(id_node->right, copy3);

    Id_Node* or_node = new Id_Node();
    or_node->id = -3;

    id_node->id = -2;
    id_node->left->id = -3;

    id_node->left->id = -3;

    id_node->left->right = copy3;
    copy3->parent = id_node->left;

    add_node_right_right_on_new(id_node->right, or_node);
    id_node->right->left = copy2;
    copy2->parent = id_node->right;
    // possibly a memory leak



  } else if ( id_node->right->id == -2 ) {

    Id_Node* copy1 = new Id_Node();
    copy_create(id_node->left, copy1);
    Id_Node* copy2 = new Id_Node();
    copy_create(id_node->right->left, copy2);
    Id_Node* copy3 = new Id_Node();
    copy_create(id_node->right->right, copy3);

    Id_Node* or_node = new Id_Node();
    or_node->id = -3;

    id_node->id = -2;
    id_node->right->id = -3;

    id_node->right->left = copy1;
    copy1->parent = id_node->right;

    add_node_left_left_on_new(id_node->left, or_node);
    id_node->left->right = copy2;
    copy2->parent = id_node->left;

  }


}

  
