#include "player.h"

//Singleton pattern to ensure only 2 players
Player *Player::p1Instance=0;
Player *Player::p2Instance=0;

Player *Player::getP1Instance() {
  if (!p1Instance) {
    p1Instance= new Player(Game::getInstance());
    std::atexit(cleanUpP1); //prevent memory leaks
  }
  return p1Instance;
}

Player *Player::getP2Instance() {
  if (!p2Instance) {
    p2Instance = new Player (Game::getInstance());
    std::atexit(cleanUpP2);
  }
  return p2Instance;
}

Player::Player(Game * g) {
  this->game = g;
}
//set instream for forward compaibility with filestreams..etc
void Player::setIn(std::istream *in) {
  this->in = in;
}

void Player::makeMove() { 
  int x;
  *in >> x;
  if (in->eof()) {std::exit ;}
  if (in->fail() || x <= 0 || x > 7) {
    std::cout << "Invalid input. Please try again (1-7)" << std::endl;
    if (in->fail()) {
      in->clear();
      in->ignore();
    }
    *in >> x;
  }
  if (this == Player::getP1Instance()) {
    this->game->makeMove(1, x-1, 'O');
    if (game->win(1)) {
      std::cout << "Player 1 wins!" << std::endl;
    }
  }
  else {
    this->game->makeMove(2, x-1, 'X');
    if (game->win(2)) {
      std::cout << "Player 2 wins!" << std::endl;
    }
  }
}

static void cleanUpP1() {
  delete Player::getP1Instance();
}

static void cleanUpP2() {
  delete Player::getP2Instance();
}
