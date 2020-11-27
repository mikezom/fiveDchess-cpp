#include "chessboard.h"
#include <vector>

#ifndef NODE_H_
#define NODE_H_

class Node{
public:
  Node();
  Node(Chessboard board[8][8]);

  int get_time() {return board_.get_time();}
  int get_multiverse() {return board_.get_multiverse();}

private:
  Chessboard board_;
  std::vector<Node *>child_;
};

#endif