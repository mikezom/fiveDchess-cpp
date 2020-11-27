#include "fiveDchess.h"

FiveDChess::FiveDChess(std::string w_name, std::string b_name){
  white_name_ = w_name;
  black_name_ = b_name;
}

Chessboard FiveDChess::get_board(int time, int multiverse){
  // search the whole tree to find correct chessboard
}

Piece FiveDChess::get_piece(Position position){
  return get_board(position.time, position.multiverse).get_piece(position.row, position.column);
}

bool FiveDChess::is_valid(Action action){
  // Check if the piece is correct
  if(get_piece(action.start_position) != action.piece_to_move)
    return false;

  // Check if start position and end position are in bound
  if(action.start_position.column > 7 || action.start_position.column < 0)
    return false;
  if(action.start_position.row > 7 || action.start_position.row < 0)
    return false;
  if(action.end_position.column > 7 || action.end_position.column < 0)
    return false;
  if(action.end_position.row > 7 || action.end_position.row < 0)
    return false;

  // Check if the color is correct
  if(action.player == white){
    if(action.piece_to_move < 7)
      return false;
  } else {
    if(action.piece_to_move > 6 || action.piece_to_move == 0)
      return false;
  }

  // TODO: rules of each pieces

  return true;
}

void FiveDChess::move(Action action){

}

void FiveDChess::print(){

}