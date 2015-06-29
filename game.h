#ifndef __GAME_H__
#define __GAME_H__
#include <cstdlib>

extern const int X_DIMENSION;
extern const int Y_DIMENSION;

class Game {
  Game();
  private:
  bool checkLinear(int x, int y, int xOffset, int yOffset, char piece);
  bool p1Win;
  bool p2Win;
  bool checkSquare(int x, int y, char c);
  public:
  static Game * instance;
  static Game * getInstance();
  char **board;
  void printBoard();
  void clearBoard();
  bool win(int player);
  void makeMove(int player, int x, char piece);
};

static void cleanUp();

#endif
