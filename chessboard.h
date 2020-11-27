#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

enum Piece{empty, b_pawn, b_bishop, b_knight, b_rook, b_queen, b_king,
                  w_pawn, w_bishop, w_knight, w_rook, w_queen, w_king};
enum Color{white, black};

class Chessboard{
public:
  Chessboard();
  Chessboard(int time, int multiverse);
  Chessboard(int time, int multiverse, Piece board[8][8]);

  Chessboard& operator=(const Chessboard& lhs){
    time_ = lhs.time_;
    multiverse_ = lhs.multiverse_;
    is_active_ = lhs.is_active_;
    now_playing_ = lhs.now_playing_;

    memcpy((void *)board_, (void *)lhs.board_, sizeof(Piece) * 8 * 8);

    return *this;
  }

  // ~Chessboard();
  void print(); // print a board
  void print_row(int row_number); // print a row
  char print_piece(Piece p);

  int get_time() {return time_;}
  int get_multiverse() {return multiverse_;}
  Color get_now_playing() {return now_playing_;}
  bool get_active() {return is_active_;}
  Piece get_piece(int row, int column) {return board_[row][column];}

  void set_time(int time) {time_ = time;}
  void set_multiverse(int multiverse) {multiverse_ = multiverse;}
  void set_color(Color player) {now_playing_ = player;}
  void set_active(bool is_active) {is_active_ = is_active;}

  // using two function to implement moving
  void add_piece(Piece piece, int row, int column);
  void remove_piece(int row, int column);
  void change_player();
private:
  int time_;
  int multiverse_;
  bool is_active_;
  Color now_playing_;
  Piece board_[8][8];
};

#endif // CHESSBOARD_H_