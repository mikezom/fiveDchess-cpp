#include "node.h"

Node::Node(){
  // Initialize the tree
  board_ = Chessboard(0,0);
  //is_null_ = false;
}

Node::Node(Chessboard chessboard){
  // create a new node using an existing board
  board_ = chessboard;
  //is_null_ = false;
}

void Node::add_child(Node* new_node){
  child_.push_back(new_node);
}