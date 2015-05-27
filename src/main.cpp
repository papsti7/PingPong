//------------------------------------------------------------------------------
// main.cpp
// Description : Main programm, were everything starts
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                

#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML PingPong");
  sf::RectangleShape background(sf::Vector2f(600.f, 600.f));
  background.setFillColor(sf::Color::White);

  sf::RectangleShape shape(sf::Vector2f(20.f,20.f));
  shape.setPosition(290.f,290.f);
  sf::Color Color(sf::Color::Red);
  shape.setFillColor(Color);
  shape.setOutlineColor(sf::Color::Black);
  shape.setOutlineThickness(2.f);
  

  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(background);
    window.draw(shape);
    window.display();
  }
  return 0;
}