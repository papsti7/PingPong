//------------------------------------------------------------------------------
// Events.h
// Description : handles events
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------      

#include "Ball.h"
#include "InitWindow.h"

class Events
{

  public:
    Events(){ };
    Events(const Events& original) = delete;

    void keyPressHandling(Ball& ball);
    void clampingBall(sf::Sprite& ball, const InitWindow& window);
    void startGameEvent(sf::Sprite& ball);
};