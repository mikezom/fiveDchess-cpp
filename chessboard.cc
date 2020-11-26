#include "chessboard.h"

Chessboard::Chessboard(int time, int multiverse){
  time_ = time;
  multiverse_ = multiverse;

  // initialize the board
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      board_[i][j] = empty;
    }
  }
}

Chessboard::Chessboard(int time, int multiverse, Piece board[8][8]){
  time_ = time;
  multiverse_ = multiverse;

  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      board_[i][j] = board[i][j];
    }
  }
}

void Chessboard::print(){
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      std::cout << board_[i][j];
    }
    std::cout << std::endl;
  }
}

void Chessboard::print_row(int row_number){
  for(int i = 0; i < 8; ++i){
      std::cout << board_[row_number][i];
  }
}