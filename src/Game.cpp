//------------------------------------------------------------------------------
// Game.cpp
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "Game.h"

Game::Game() : start_game_(false) {   };

void Game::run()
{
  //InitWindow settings(600, 600, "SFML PingPong");
  sf::RenderWindow window;
  //settings.createWindow(window);
  

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;
      }
    }
  }
  /*
    Player player_one(settings);
    player_one.createPlayerLeft(settings);
    Player player_two(settings);
    player_two.createPlayerRight(settings);
  */



    window.clear();
    //window.draw(settings.getBackground());
    //window.draw(player_one.getPlayerBat());
    //window.draw(player_two.getPlayerBat());
    window.display();
  }


