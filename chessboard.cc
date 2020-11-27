#include "chessboard.h"

Chessboard::Chessboard(){
  time_ = 0;
  multiverse_ = 0;

  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      board_[i][j] = empty;
    }
  }
}

Chessboard::Chessboard(int time, int multiverse){
  time_ = time;
  multiverse_ = multiverse;

  // initialize the board
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      board_[i][j] = empty;
    }
  }
  for(int i = 0; i < 8; ++i){
    board_[1][i] = w_pawn;
  }
  for(int i = 0; i < 8; ++i){
    board_[6][i] = b_pawn;
  }
  board_[0][0] = w_rook;
  board_[0][1] = w_knight;
  board_[0][2] = w_bishop;
  board_[0][3] = w_queen;
  board_[0][4] = w_king;
  board_[0][5] = w_bishop;
  board_[0][6] = w_knight;
  board_[0][7] = w_rook;

  board_[7][0] = b_rook;
  board_[7][1] = b_knight;
  board_[7][2] = b_bishop;
  board_[7][3] = b_queen;
  board_[7][4] = b_king;
  board_[7][5] = b_bishop;
  board_[7][6] = b_knight;
  board_[7][7] = b_rook;
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
  std::cout << "╔" << time_ << "," << multiverse_ << "═════╗" << std::endl;
  for(int i = 7; i >= 0; --i){
    std::cout << "║";
    for(int j = 0; j < 8; ++j){
      std::cout << print_piece(board_[i][j]);
    }
    std::cout << "║" << std::endl;
  }
  std::cout << "╚════════╝" << std::endl;
}

void Chessboard::print_row(int row_number){
  for(int i = 0; i < 8; ++i){
      std::cout << print_piece(board_[row_number][i]);
  }
}

char Chessboard::print_piece(Piece p){
  switch (p)
  {
  case empty:
    return ' ';
    break;
  
  case b_pawn:
    return 'p';
    break;
  
  case b_bishop:
    return 'b';
    break;
  
  case b_knight:
    return 'n';
    break;
  
  case b_rook:
    return 'r';
    break;
  
  case b_queen:
    return 'q';
    break;
  
  case b_king:
    return 'k';
    break;
  
  case w_pawn:
    return 'P';
    break;
  
  case w_bishop:
    return 'B';
    break;
  
  case w_knight:
    return 'N';
    break;
  
  case w_rook:
    return 'R';
    break;
  
  case w_queen:
    return 'Q';
    break;

  case w_king:
    return 'K';
    break;

  default:
    return '=';
    break;
  }
}