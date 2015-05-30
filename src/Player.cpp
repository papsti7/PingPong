

#include "Player.h"

void Player::createPlayerLeft(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  std::string player_name("Player Left");
  window.pushbackDesignText(player_name);
}
void Player::createPlayerRight(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(window.getWindowWidth() - bat_.getSize().x - 5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  std::string player_name("Player Right");
  window.pushbackDesignText(player_name);
}

sf::RectangleShape& Player::getPlayerBat()
{
  return bat_;
}