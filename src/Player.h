#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
#include "InitWindow.h"

class Player
{
  private:
  //int speed_x_;
  //int speed_y_;
  sf::RectangleShape bat_;
  float middle_point_;


  public:

    Player() = delete;
    Player(const Player& original) = delete;

    Player(InitWindow& window)// : speed_x_(0), speed_y_(0) 
    {  
      middle_point_ = window.getWindowHeight() / 2.f - window.getWindowHeight() / 20.f;
    }
    
    void createPlayerLeft(InitWindow& window);
    void createPlayerRight(InitWindow& window);

	void addUpSpeed();
	void addDownSpeed(const InitWindow& window);
        
	void resetPlayerLeftBat();
	void resetPlayerRightBat(const InitWindow& window);

    sf::RectangleShape& getPlayerBat();

};
#endif PLAYER_H