#include "chessboard.h"

#include <iostream>

int main(){
  std::cout << "Initializing 5D Chess\n";

  Chessboard chess = Chessboard(0,0);
  chess.print();

  return 0;
}