//------------------------------------------------------------------------------
// Game.cpp
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "Game.h"

Game::Game(){   };

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
    events.keyPressHandling(ball.getBall());
    events.clampingBall(ball.getBall(), settings);


    window.clear();
    window.draw(settings.getBackground());
    window.draw(ball.getBall());
    window.display();
  }

}
