

#include "Events.h"

void Events::keyPressHandling(sf::Sprite& ball)
{
  //smooth movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    ball.move(0.f, -5.f);
  //std::cout << "notized key W" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    ball.move(0.f, 5.f);
  //std::cout << "notized key S" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    ball.move(-5.f, 0.f);
  //std::cout << "notized key A" << std::endl;
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    ball.move(5.f, 0.f);
  //std::cout << "notized key D" << std::endl;
}

void Events::clampingBall(sf::Sprite& ball, const InitWindow& window)
{
  //clamping
  if (ball.getPosition().x < 0)
    ball.setPosition(0.f, ball.getPosition().y);
  //left edge
  else if (ball.getPosition().x + ball.getGlobalBounds().width > window.getWindowWidth())
    ball.setPosition(window.getWindowWidth() - ball.getGlobalBounds().width, ball.getPosition().y);
  //right edge
  else if (ball.getPosition().y < 0)
    ball.setPosition(ball.getPosition().x, 0.f);
  //top edge
  else if (ball.getPosition().y + ball.getGlobalBounds().height > window.getWindowHeight())
    ball.setPosition(ball.getPosition().x, window.getWindowHeight() - ball.getGlobalBounds().height);
  //bottom edge
}