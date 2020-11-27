#include "fiveDchess.h"

#include <iostream>

int main(){
  std::cout << "Initializing 5D Chess\n";

  FiveDChess chess = FiveDChess();
  chess.move(chess.action_parser("asdf"));
  chess.move(chess.action_parser("asdf"));
  chess.move(chess.action_parser("asdf"));
  chess.move(chess.action_parser("asdf"));
  chess.move(chess.action_parser("asdf"));
  chess.print();

  return 0;
}