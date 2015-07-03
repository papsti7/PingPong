
#include "Ball.h"



void Ball::create(const InitWindow& Window)
{
  ball.setPosition(float(Window.getWindowWidth() / 2.f + ball.getGlobalBounds().width / 2.f), float(Window.getWindowHeight() / 2.f + ball.getGlobalBounds().height / 2.f));
  ball.setFillColor(sf::Color::Black);
  ball.setRadius(20.f);
  
}

void Ball::move()
{
  ball.move(speed_up);

}


sf::CircleShape& Ball::getBall()
{
  return ball;
}