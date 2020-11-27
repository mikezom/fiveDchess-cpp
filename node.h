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
  bool is_null() {return is_null_;}

  void set_null() {is_null_ = true;}
  void add_child(Node new_node);
private:
  Chessboard board_;
  std::vector<Node>child_;
  bool is_null_;
};

#endif