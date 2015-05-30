//------------------------------------------------------------------------------
// InitWindow.cpp
// Description : all things, which happend with the ball
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                


#include "InitWindow.h"

InitWindow::InitWindow() : window_height_(500), window_width_(500), window_name_("PingPong")
{
	font_.loadFromFile("arial.ttf");
}

InitWindow::InitWindow(unsigned window_width, unsigned window_height, std::string window_name) :
  window_width_(window_width),
  window_height_(window_height),
  window_name_(window_name)
{ font_.loadFromFile("arial.ttf"); }

void InitWindow::setBackgroundColor(sf::Color color)
{
  background_.setFillColor(color);

}

void InitWindow::createGamePanel(sf::RenderWindow& window)
{
  window.create(sf::VideoMode(window_height_, window_width_), window_name_);
  window.setVerticalSyncEnabled(true);
  //create background with color "white
  background_.setSize(sf::Vector2f(static_cast<float>(window_height_), static_cast<float>(window_width_)));
  background_.setFillColor(sf::Color::White);
  //design
  sf::RectangleShape middle_line;
  middle_line.setSize(sf::Vector2f(window_width_ / 100.f, window_height_));
  middle_line.setPosition(window_width_ / 2.f - middle_line.getSize().x / 2.f, 0.f);
  middle_line.setFillColor(sf::Color::Black);
  design_rect_.push_back(middle_line);
    
}

void InitWindow::pushbackDesignRect(sf::RectangleShape& new_design_detail)
{
	design_rect_.push_back(new_design_detail);
}

void InitWindow::pushbackDesignText(std::string& new_design_detail)
{
	design_text_.push_back(new_design_detail);
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

std::vector<sf::RectangleShape>& InitWindow::getDesignRect()
{
	return design_rect_;
}
std::vector<std::string>& InitWindow::getDesignText()
{
	return design_text_;
}

sf::Font& InitWindow::getFont()
{
	return font_;
}