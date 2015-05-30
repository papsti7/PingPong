#ifndef INITWINDOW_H
#define INITWINDOW_H
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
  std::vector<sf::RectangleShape> design_rect_;
  std::vector<std::string> design_text_;
  sf::Font font_;


  public:

    InitWindow();

    InitWindow(unsigned window_width, unsigned window_height, std::string window_name);

    InitWindow(const InitWindow& orignal) = delete;

    void createGamePanel(sf::RenderWindow& window);
	void pushbackDesignRect(sf::RectangleShape& new_design_detail);
	void pushbackDesignText(std::string& new_design_detail);

    //-----------------Setter---------------------------------------------------
    void setBackgroundColor(sf::Color color);
	

    //-----------------Getter---------------------------------------------------
    unsigned getWindowHeight() const;
    unsigned getWindowWidth() const;
    sf::RectangleShape getBackground() const;
	std::vector<sf::RectangleShape>& getDesignRect(); 
	std::vector<std::string>& getDesignText();
	sf::Font& getFont();




};
#endif INITWINDOW_H