#include "chessboard.h"
#include <string>

class FiveDChess {
public:
  void print(); // print the whole playground
  FiveDChess(std::string w_name,
             std::string b_name);
private:
  std::string white_name;
  std::string black_name;
  Chessboard** board;
};