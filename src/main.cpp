//------------------------------------------------------------------------------
// main.cpp
// Description : Main programm, were everything starts
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  //Init the win
  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML PingPong");
  window.setVerticalSyncEnabled(true);
  //create background with color "white
  sf::RectangleShape background(sf::Vector2f(600.f, 600.f));
  background.setFillColor(sf::Color::White);

  //load texture
  sf::Texture smiley;
  if (!smiley.loadFromFile("smiley.png"))
  {
    std::cout << "Loading File not possible!" << std::endl;
    std::cin.get();
    return 1;
  }
  //put texture in sprite
  smiley.setSmooth(true);
  sf::Sprite sprite;
  sprite.setTexture(smiley);
  sprite.setPosition(275.f, 275.f);
  sprite.setScale(.5f,.5f);

  //while running loop
  while (window.isOpen())
  {

  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::Closed: 
        window.close();
        break;
    }
    
  }
   //smooth movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      sprite.move(0.f, -5.f);
      //std::cout << "notized key W" << std::endl;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      sprite.move(0.f, 5.f);
        //std::cout << "notized key S" << std::endl;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      sprite.move(-5.f, 0.f);
      //std::cout << "notized key A" << std::endl;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      sprite.move(5.f, 0.f);
      //std::cout << "notized key D" << std::endl;
     
    
  

  window.clear();
  window.draw(background);
  window.draw(sprite);
  window.display();
  }
  return 0;
}