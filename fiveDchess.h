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
  FiveDChess(std::string w_name = "white",
             std::string b_name = "black");

  Piece get_piece(Position position);
  Node get_node(int time, int multiverse);
  Chessboard get_board(int time, int multiverse);
  bool get_check() {return is_check_;}
  int get_furthest_time() {return furthest_time_;}
  int get_furthest_multiverse() {return furthest_multiverse_;}

  void increment_furthest_time() {furthest_time_++;}
  void increment_furthest_multiverse() {furthest_multiverse_++;}

  Action action_parser(std::string ac);
  bool is_valid(Action action);
  void move(Action action);
  void submit(); // change player
  void print(); // print the whole playground
private:
  std::string white_name_;
  std::string black_name_;
  int turn_;
  bool is_check_;
  Color now_playing_;
  int furthest_time_;
  int furthest_multiverse_;

  Node root_;
};

#endif