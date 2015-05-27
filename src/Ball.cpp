//------------------------------------------------------------------------------
// ball.cpp
// Description : all things, which happend with the ball
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------      

#include "Ball.h"

void Ball::loadTextureToSprite()
{
  
  if (!smiley_.loadFromFile("smiley.png"))
  {
    std::cout << "Loading File not possible!" << std::endl;
    std::cin.get();
    //TODO: return or rect Texture
  }

  smiley_.setSmooth(true);
  //put texture in ball
  ball_.setTexture(smiley_);
  ball_.setTextureRect(sf::IntRect(0, 0, smiley_.getSize().x, smiley_.getSize().y));
  ball_.setScale(.5f, .5f);
  
}

sf::Sprite& Ball::getBall()
{
  return ball_;
}