#include "player.h"
#include "game.h"
#include <iostream>
//simple testing harness
using namespace std;
int main() {
  int turn = 1;
  Player::getP1Instance()->setIn(&cin);
  Player::getP2Instance()->setIn(&cin);
  while (true) {
    if (turn == 1) {
      cout << "P1's move (enter the column)" << endl;
      Player::getP1Instance()->makeMove();
      Game::getInstance()->printBoard();
      if (Game::getInstance()->win(1)) {
        cout << "Game over, P1 won!" << endl;
        break;
      }
      turn = 2;
    }
    if (turn == 2){ 
      cout << "P2's move (enter the column)" << endl;
      Player::getP2Instance()->makeMove();
      Game::getInstance()->printBoard();
      if (Game::getInstance()->win(2)) {
        cout << "Game over, P2 won!" << endl;
        break;
      }
      turn = 1;
    }
  }
}
