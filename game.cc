#include "game.h"
#include <iostream>

Game *Game::instance = 0;

const int X_DIMENSION = 7;
const int Y_DIMENSION = 6;

Game *Game::getInstance() {
  if (!instance) {
    instance = new Game();
    atexit(cleanUp);
  }
  return instance;
}
//2d array of characters
Game::Game() {
  this->board = new char*[X_DIMENSION];
  for (int i = 0 ; i < X_DIMENSION; i++) {
    this->board[i] = new char[Y_DIMENSION];
  }
  this->p1Win = false;
  this->p2Win = false;
  clearBoard();
}

void Game::clearBoard() {
  for (int x = 0 ; x < X_DIMENSION; x++) {
    for (int y = 0; y < Y_DIMENSION; y++) {
      this->board[x][y] = '*';
    }
  }
}

void Game::printBoard() {
  for (int y = 0; y < Y_DIMENSION; y++) {
    for (int x = 0; x < X_DIMENSION; x++) {
      std::cout << this->board[x][y];
    }
    std::cout << std::endl;
  }
}
//checks a square if anything around it is a Connect-4
bool Game::checkSquare(int x, int y, char c) {
  if (x >= 3) {
    if (checkLinear(x, y, -1, 0, c)) { return true; }
  }
  if (x <= 3) {
    if (checkLinear(x, y, 1, 0, c)) { return true; } 
  }
  if (y >= 2) {
    if (checkLinear(x, y, 0, 1, c)) {return true; }
  }
  if (y >= 3 && x <= 3) {
    if (checkLinear(x,y, 1, -1, c)) {return true; }
  }
  if (y >=3 && x >= 3) {
    if (checkLinear(x, y, -1, -1, c)) {return true; }
  }
  if (y <= 2 && x <= 3) {
    if (checkLinear(x, y, 1, 1, c)) {return true; }
  }
  if (y <= 2 && x >= 3) {
    if (checkLinear(x, y, -1, 1, c)) {return true;}
  }
}
//Generic checking function to check in one direction
bool Game::checkLinear(int x, int y, int xOffset, int yOffset, char c) {
  for (int i = 1; i < 4; i++) {
    if (this->board[x+i*xOffset][y+i*yOffset] != c) {
      return false;
    }
  }
  return true;
}

void Game::makeMove(int player, int x, char c) {
  int y;
  for (int i = Y_DIMENSION-1; i >=0 ; i--) {
    if (this->board[x][i] == '*') {
      y = i;
      break;
    }
  }
  this->board[x][y] = c;
  bool win = checkSquare(x, y, c);
  if (player == 1) {
    p1Win = win;
  }
  else {
    p2Win = win;
  }
}

bool Game::win(int player) {
  if (player==1) {
    return p1Win;
  }
  return p2Win;
}
//prevent memory leaks
static void cleanUp() {
  for (int x = 0 ; x < X_DIMENSION; x++) {
    delete[] Game::getInstance()->board[x];
  }
  delete[] Game::getInstance()->board;
  delete[] Game::getInstance();
}

