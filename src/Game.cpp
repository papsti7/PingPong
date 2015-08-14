//------------------------------------------------------------------------------
// Game.cpp
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "Game.h"

using namespace std::chrono;

Game::Game() : score_player_left_(0), score_player_right_(0) {   };

void Game::run()
{
  InitWindow settings(600, 600, "SFML PingPong");
  sf::RenderWindow window;
  settings.createGamePanel(window);
  //create players
  Player player_left(settings);
  Player player_right(settings);
  player_left.createPlayerLeft(settings);
  player_right.createPlayerRight(settings);
  //set up names
  sf::Text player_left_name(settings.getDesignText().at(0), settings.getFont());
  player_left_name.setColor(sf::Color::Black);
  player_left_name.setPosition(50.f, 50.f);
  sf::Text player_right_name(settings.getDesignText().at(1), settings.getFont());
  player_right_name.setColor(sf::Color::Black);
  player_right_name.setPosition(settings.getWindowWidth() - 240.f, 50.f);

  //create Ball
  Ball ball;
  ball.create(settings);

  int state = 0;


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
	// Use time for the random seed, nanoseconds should be enough precision
	auto time = duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
	//Init random engine with the time as seed (fixed value during debugging to have the same value
	//each run)
	std::default_random_engine engine(time);
	//Real distribution for floating numbers
	std::uniform_real_distribution<float> float_dist_x(-8.0f, 8.0f);
	std::uniform_real_distribution<float> float_dist_y(-8.0f, 8.0f);


	int change;

	switch (state)
	{
	case 0:
		
		window.clear();
		window.draw(settings.getBackground());

		//gamepanel and names
		for (auto& design : settings.getDesignRect())
			window.draw(design);
		window.draw(player_left_name);
		window.draw(player_right_name);

		//bats
		player_left.resetPlayerLeftBat();
		player_right.resetPlayerRightBat(settings);
		window.draw(player_left.getPlayerBat());
		window.draw(player_right.getPlayerBat());


		


		//ball
		ball.resetBallPos(settings);
		ball.setSpeed(float_dist_x(engine) + 2.f, float_dist_y(engine) + 2.f);
		window.draw(ball.getBall());

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			state = 1;
		break;

	case 1:
		checkPlayerMovement(player_left, player_right, settings);

		//movePosition() --> move() + reduceSpeed()
		window.clear();
		window.draw(settings.getBackground());

		//gamepanel and names
		for (auto& design : settings.getDesignRect())
			window.draw(design);
		window.draw(player_left_name);
		window.draw(player_right_name);

		//bats
		window.draw(player_left.getPlayerBat());
		window.draw(player_right.getPlayerBat());


		//ball

		change = ball.update(settings, player_left, player_right, state);

		if(change = LEFT_WON)
			increaseScorePlayerLeft();
		else if (change = RIGHT_WON)
			increaseScorePlayerRight();
		std::cout << score_player_left_ << ":" << score_player_right_ << std::endl;
		if (score_player_left_ >= 5)
		{
			std::cout << "Player Left won!!" << std::endl;
			state = 0;
			resetScore();
		}
		else if (score_player_right_ >= 5)
		{
			std::cout << "Player Right won!!" << std::endl;
			state = 0;
			resetScore();
		}
		
		window.draw(ball.getBall());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			state = 0;
		break;


	default:
		break;
	}
	    

    window.display();
  }
  
    
	
}

void Game::checkPlayerMovement(Player& player_left, Player& player_right, const InitWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player_left.addUpSpeed();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player_left.addDownSpeed(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player_right.addUpSpeed();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player_right.addDownSpeed(window);
}

void Game::increaseScorePlayerLeft()
{
	score_player_left_++;
}

void Game::increaseScorePlayerRight()
{
	score_player_right_++;
}

void Game::resetScore()
{
	score_player_left_ = 0;
	score_player_right_ = 0;
}