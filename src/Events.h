

#include "Ball.h"
#include "InitWindow.h"

class Events
{
  public:
    Events(){ };
    Events(const Events& original) = delete;

    void keyPressHandling(sf::Sprite& ball);
    void clampingBall(sf::Sprite& ball, const InitWindow& window);
};