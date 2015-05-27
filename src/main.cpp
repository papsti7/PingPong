//------------------------------------------------------------------------------
// main.cpp
// Description : Main programm, were everything starts
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                

#include <SFML/Graphics.hpp>
#include <iostream>

static const unsigned window_height = 600;
static const unsigned window_width = 600;


int main()
{
  //Init the win
  sf::RenderWindow window(sf::VideoMode(window_height, window_width), "SFML PingPong");
  //window.setFramerateLimit(55);
  window.setVerticalSyncEnabled(true);
  //create background with color "white
  sf::RectangleShape background(sf::Vector2f(static_cast<float>(window_height), static_cast<float>(window_width)));
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
  sf::Sprite sprite(smiley, sf::IntRect(0,0,76,72));
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
     
   //clamping
  if (sprite.getPosition().x < 0)
    sprite.setPosition(0.f, sprite.getPosition().y);
  //left edge
  else if (sprite.getPosition().x + sprite.getGlobalBounds().width >= window_width)
    sprite.setPosition(window_width - sprite.getGlobalBounds().width, sprite.getPosition().y);
  //right edge
  else if (sprite.getPosition().y < 0)
    sprite.setPosition(sprite.getPosition().x, 0.f);
  //top edge
  else if (sprite.getPosition().y + sprite.getGlobalBounds().height >= window_height)
    sprite.setPosition(sprite.getPosition().x, window_height - sprite.getGlobalBounds().height);
  //bottom edge
  
  

  window.clear();
  window.draw(background);
  window.draw(sprite);
  window.display();
  }
  return 0;
}