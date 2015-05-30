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
  //set up names
  sf::Text player_left_name(settings.getDesignText().at(0), settings.getFont());
  player_left_name.setColor(sf::Color::Black);
  player_left_name.setPosition(50.f, 50.f);
  sf::Text player_right_name(settings.getDesignText().at(1), settings.getFont());
  player_right_name.setColor(sf::Color::Black);
  player_right_name.setPosition(settings.getWindowWidth() - 240.f, 50.f);

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

	//gamepanel and names
	for (auto& design : settings.getDesignRect())
		window.draw(design);
	window.draw(player_left_name);
	window.draw(player_right_name);
	//dsfdf
	//bats
	window.draw(player_left.getPlayerBat());
	window.draw(player_right.getPlayerBat());
	window.display();
  }
  
    
	
}


