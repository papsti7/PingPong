//------------------------------------------------------------------------------
// ball.h
// Description : all things, which happend with the ball
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------                                                                                

#include <SFML/Graphics.hpp>
#include <iostream>

class Ball
{
  private:

  sf::Sprite ball_;
  sf::Texture smiley_;


  public:

    Ball(){  };

    Ball(const Ball& orginal) = delete;

    void loadTextureToSprite();

    sf::Sprite& getBall();


};