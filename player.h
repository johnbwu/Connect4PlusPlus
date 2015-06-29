#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <cstdlib>
#include <iostream>
#include "game.h"

class Player {
  public:
  static Player *p1Instance;
  static Player *p2Instance;
  static Player *getP1Instance();
  static Player *getP2Instance();
  Game *game;
  Player(Game *g);
  std::istream *in;
  void makeMove();
  void setIn(std::istream * in);
};

static void cleanUpP1();
static void cleanUpP2();
#endif
