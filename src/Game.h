#ifndef GAME_H
#define GAME_H
//------------------------------------------------------------------------------
// Game.h
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "InitWindow.h"
#include "Player.h"
#include "Ball.h"

class Game
{

  private:
  bool start_game_;

  public:

    Game();

    Game(const Game& origin) = delete;

    void run();

	void checkPlayerMovement(Player& player_left, Player& player_right, const InitWindow& window);

};
#endif GAME_H