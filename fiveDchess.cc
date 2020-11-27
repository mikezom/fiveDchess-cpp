#include "fiveDchess.h"

FiveDChess::FiveDChess(std::string w_name, std::string b_name){
  white_name_ = w_name;
  black_name_ = b_name;
  now_playing_ = white;
  furthest_time_ = 1;
  furthest_multiverse_ = 0;
}

Node FiveDChess::get_node(int time, int multiverse){
  // search the whole tree to find correct node
  // if unable to find node, return NULL
  return root_;
}

Chessboard FiveDChess::get_board(int time, int multiverse){
  // search the whole tree to find correct chessboard
  return root_.get_chessboard();
}

Piece FiveDChess::get_piece(Position position){
  return get_board(position.time, position.multiverse).get_piece(position.row, position.column);
}

Action FiveDChess::action_parser(std::string ac){
  struct Position new_start_position = {1, 1, 0, 0};
  struct Position new_end_position = {3, 1, 0, 0};
  struct Action new_action = {w_pawn, new_start_position, new_end_position, white};

  return new_action;
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

  // TODO: start position need to be valid

  return true;
}

void FiveDChess::move(Action action){
  if(is_valid(action)){
    // TODO: Check if is_check after the move

    // Create a new node
    int end_time = action.end_position.time;
    int end_multiverse = action.end_position.multiverse;

    Node new_node = Node(get_board(end_time,
                                   end_multiverse));

    // TODO: change the position of piece in new board

    // add the new node to the child
    get_node(end_time, end_multiverse).add_child(new_node);

    // TODO: check condition to increment max time and multiverse
    increment_furthest_time();                            
  } else {
    printf("Action invalid!\n");
  }
}

void FiveDChess::submit(){
  // TODO: already move necessary moves

  if(now_playing_ == white){
    now_playing_ = black;
  } else {
    now_playing_ = white;
  }
}

void FiveDChess::print(){
  // print the whole tree
  printf("white name: %s\n", white_name_.c_str());
  printf("black name: %s\n", black_name_.c_str());
  
  for(int multiverse = furthest_multiverse_; multiverse >= 0; --multiverse){
    for(int time = 0; time < furthest_time_; ++time){
      if(get_node(time, multiverse).is_null() != true){
        std::cout << "╔" << time << "," << multiverse << "═════╗";
      } else {
        std::cout << "          ";
      }
    }
    std::cout << std::endl;
    for(int row = 7; row >= 0; --row){
      for(int time = 0; time < furthest_time_; ++time){
        if(get_node(time, multiverse).is_null() != true){
          std::cout << "║";
          get_node(time, multiverse).get_chessboard().print_row(row);
          std::cout << "║";
        } else {
          std::cout << "          ";
        }
      }
      std::cout << std::endl;
    }
    for(int time = 0; time < furthest_time_; ++time){
      if(get_node(time, multiverse).is_null() != true){
        std::cout << "╚════════╝";
      } else {
        std::cout << "          ";
      }
    }
    std::cout << std::endl;
  }
}