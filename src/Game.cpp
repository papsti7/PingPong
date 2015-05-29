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
  InitWindow settings(600, 600, "SFML PingPong");
  sf::RenderWindow window;
  settings.createGamePanel(window);
  //create players
  Player player_left(settings);
  Player player_right(settings);
  player_left.createPlayerLeft(settings);
  player_right.createPlayerRight(settings);

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
	
	
	window.clear();
	window.draw(settings.getBackground());

	for (auto& design : settings.getDesignRect())
		window.draw(design);

	//for (auto& design : settings.getDesignText())
		//window.draw(settings.getDesignText().at(1));
		
	window.draw(player_left.getPlayerBat());
	window.draw(player_right.getPlayerBat());
	window.display();
  }
  
    
	
  }


