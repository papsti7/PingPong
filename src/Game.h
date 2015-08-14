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

#include <random>
#include <chrono>


class Game
{

  private:
  //bool start_game_;
	  unsigned score_player_left_;
	  unsigned score_player_right_;

  public:

    Game();

    Game(const Game& origin) = delete;

    void run();

	void checkPlayerMovement(Player& player_left, Player& player_right, const InitWindow& window);

	void increaseScorePlayerLeft();

	void increaseScorePlayerRight();

	void resetScore();

};
#endif GAME_H