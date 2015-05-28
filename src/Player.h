

#include <SFML\Graphics.hpp>
#include "InitWindow.h"

class Player
{
  private:
  int speed_x_;
  int speed_y_;
  sf::RectangleShape bat_;
  float middle_point_;


  public:

    Player() = delete;
    Player(const Player& original) = delete;

    Player(const InitWindow& window) : speed_x_(0), speed_y_(0) 
    {  
      middle_point_ = static_cast<float>(window.getWindowHeight() + window.getWindowHeight() / 16);
    }
    
    void createPlayerLeft(const InitWindow& window);
    void createPlayerRight(const InitWindow& window);
        
    sf::RectangleShape getPlayerBat() const;

};