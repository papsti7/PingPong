//------------------------------------------------------------------------------
// InitWindow.h
// Description : all things, which happend with the ball
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                

#include <SFML\Graphics.hpp>
#include <iostream>

class InitWindow
{
  private:
  
  unsigned window_height_;
  unsigned window_width_;
  std::string window_name_;
  sf::RectangleShape background_;
  

  public:

    InitWindow();

    InitWindow(unsigned window_width, unsigned window_height, std::string window_name);

    InitWindow(const InitWindow& orignal) = delete;

    void createWindow(sf::RenderWindow&);

    //-----------------Setter---------------------------------------------------
    void setBackgroundColor(sf::Color color);

    //-----------------Getter---------------------------------------------------
    unsigned getWindowHeight() const;
    unsigned getWindowWidth() const;
    sf::RectangleShape getBackground() const;



};