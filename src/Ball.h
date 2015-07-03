#ifndef BALL_H
#define BALL_H
//------------------------------------------------------------------------------
// Ball.h
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "InitWindow.h"



class Ball
{
private:
  sf::CircleShape ball;
  float speed_x;
  float speed_y;
  sf::Vector2f speed_up;



public:

  Ball() : speed_x(0.f), speed_y(0.f) , speed_up(5.f, 5.f) { }

  void create(const InitWindow& Window);
  void move();


  sf::CircleShape& getBall();


};











#endif BALL_H