#include "chessboard.h"
#include <vector>

#ifndef NODE_H_
#define NODE_H_

class Node{
public:
  Node();
  Node(Chessboard chessboard);

  int get_time() {return board_.get_time();}
  int get_multiverse() {return board_.get_multiverse();}
  Chessboard get_chessboard() {return board_;}
  std::vector<Node*> get_child() {return child_;}

  void add_child(Node* new_node);
private:
  Chessboard board_;
  std::vector<Node*>child_;
};

#endif