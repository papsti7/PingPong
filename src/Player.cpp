

#include "Player.h"

void Player::createPlayerLeft(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  sf::Font font;
  if (font.loadFromFile("arial.ttf"))
	  std::cout << "Font loaded" << std::endl;
  sf::Text player_name("Player Left", font);
  player_name.setColor(sf::Color::Black);
  player_name.setPosition(50.f, 50.f);
  window.pushbackDesignText(player_name);
}
void Player::createPlayerRight(InitWindow& window)
{
  bat_.setSize(sf::Vector2f(window.getWindowWidth() / 50.f, window.getWindowHeight() / 10.f));
  bat_.setPosition(window.getWindowWidth() - bat_.getSize().x - 5.f, middle_point_);
  bat_.setFillColor(sf::Color::Black);
  //create name design
  sf::Font font;
  font.loadFromFile("arial.ttf");
  sf::Text player_name("Player Left", font);
  player_name.setColor(sf::Color::Black);
  player_name.setPosition(window.getWindowWidth() - 100.f, 50.f);
  window.pushbackDesignText(player_name);
}

sf::RectangleShape& Player::getPlayerBat()
{
  return bat_;
}