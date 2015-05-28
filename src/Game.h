//------------------------------------------------------------------------------
// Game.h
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "Events.h"


class Game
{

  private:
  bool start_game_;

  public:

    Game();

    Game(const Game& origin) = delete;

    void run();
};