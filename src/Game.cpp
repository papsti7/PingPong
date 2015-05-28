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
  settings.createWindow(window);
  Ball ball;
  ball.loadTextureToSprite();

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
    Events events;
    if (!start_game_)
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        events.startGameEvent(ball.getBall());
        start_game_ = true;
      }
    }
    else
    {
      events.keyPressHandling(ball.getBall());
      events.clampingBall(ball.getBall(), settings);
    }
    


    window.clear();
    window.draw(settings.getBackground());
    window.draw(ball.getBall());
    window.display();
  }

}
