#include "chessboard.h"
#include "node.h"
#include <string>

#ifndef FIVEDCHESS_H_
#define FIVEDCHESS_H_

#define MAX_MULTIVERSE 32
#define MAX_TIME 64

struct Position
{
  int row;
  int column;
  int time;
  int multiverse;
};

struct Action
{
  Piece piece_to_move;
  Position start_position;
  Position end_position;
  Color player;
};

class FiveDChess {
public:
  bool is_valid(Action action);
  Piece get_piece(Position position);
  Chessboard get_board(int time, int multiverse);
  void move(Action action); // every move create at least one node
  void print(); // print the whole playground
  FiveDChess(std::string w_name = "white",
             std::string b_name = "black");
private:
  std::string white_name_;
  std::string black_name_;
  int turn_;
  bool is_check_;
  
  Node root_;
};

#endif