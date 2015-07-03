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




public:

  Ball() { }

  void create(const InitWindow& Window);


  sf::CircleShape& getBall();


};











#endif BALL_H