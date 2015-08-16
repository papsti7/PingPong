

#include "Player.h"

void Player::createPlayerLeft(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  std::string player_name("Stefan");
  window.pushbackDesignText(player_name);
}
void Player::createPlayerRight(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(window.getWindowWidth() - bat_.getSize().x - 5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  std::string player_name("TestPlayer");
  window.pushbackDesignText(player_name);
}

sf::RectangleShape& Player::getPlayerBat()
{
  return bat_;
}

void Player::addUpSpeed()
{
  if (bat_.getPosition().y <= 0.f)
    bat_.setPosition(bat_.getPosition().x, 0.f);
  else
    bat_.move(0.f, -5.f);
}

void Player::addDownSpeed(const InitWindow& window)
{
  if (bat_.getPosition().y + bat_.getSize().y >= window.getWindowHeight())
    bat_.setPosition(bat_.getPosition().x, window.getWindowHeight() - bat_.getSize().y);
  else
    bat_.move(0.f, 5.f);
}

void Player::resetPlayerLeftBat()
{
	bat_.setPosition(5.f, middle_point_);
}

void Player::resetPlayerRightBat(const InitWindow& window)
{
	bat_.setPosition(window.getWindowWidth() - bat_.getSize().x - 5.f, middle_point_);
}