#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <iostream>
#include <string>

enum Piece{empty, b_pawn, b_bishop, b_knight, b_rook, b_queen, b_king,
                  w_pawn, w_bishop, w_knight, w_rook, w_queen, w_king};

class Chessboard{
public:
  Chessboard(int time, int multiverse);
  Chessboard(int time, int multiverse, Piece board[8][8]);
  // ~Chessboard();
  void print(); // print a board
  void print_row(int row_number); // print a row
  char print_piece(Piece p);

  int get_time() {return time_;}
  int get_multiverse() {return multiverse_;}

  void set_time(int time) {time_ = time;}
  void set_multiverse(int multiverse) {multiverse_ = multiverse;}

private:
  int time_;
  int multiverse_;
  bool is_active_;
  Piece board_[8][8];
};

#endif