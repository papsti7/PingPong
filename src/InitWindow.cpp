
#include "InitWindow.h"

InitWindow::InitWindow() : window_height_(500), window_width_(500), window_name_("PingPong")
{ }

InitWindow::InitWindow(unsigned window_width, unsigned window_height, std::string window_name) :
  window_width_(window_width),
  window_height_(window_height),
  window_name_(window_name)
{ }

void InitWindow::setBackgroundColor(sf::Color color)
{
  background_.setFillColor(color);
}

void InitWindow::createWindow(sf::RenderWindow& window)
{
  window.create(sf::VideoMode(window_height_, window_width_), window_name_);
  window.setVerticalSyncEnabled(true);
  //create background with color "white
  background_.setSize(sf::Vector2f(static_cast<float>(window_height_), static_cast<float>(window_width_)));
  background_.setFillColor(sf::Color::White);

  
}

unsigned InitWindow::getWindowHeight() const
{
  return window_height_;
}
unsigned InitWindow::getWindowWidth() const
{
  return window_width_;
}

sf::RectangleShape InitWindow::getBackground() const
{
  return background_;
}