

#include "Player.h"

void Player::createPlayerLeft(const InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
}
void Player::createPlayerRight(const InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(window.getWindowWidth() - bat_.getSize().x - 5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
}

sf::RectangleShape& Player::getPlayerBat()
{
  return bat_;
}