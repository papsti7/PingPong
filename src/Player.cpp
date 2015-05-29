

#include "Player.h"

void Player::createPlayerLeft(const InitWindow& window)
{
  bat_.setSize(sf::Vector2f(float(window.getWindowWidth()/25), float(window.getWindowHeight()/8)));
  bat_.setPosition(5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
}
void Player::createPlayerRight(const InitWindow& window)
{
  bat_.setSize(sf::Vector2f(float(window.getWindowWidth() / 25), float(window.getWindowHeight() / 8)));
  bat_.setPosition(window.getWindowWidth() - 5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
}

sf::RectangleShape& Player::getPlayerBat()
{
  return bat_;
}