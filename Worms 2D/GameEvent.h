#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
class GameEvent
{
public:

	GameEvent();
	virtual ~GameEvent();
	sf::Event GetInstance();
	void handleEvents();



private:
	GameWindow *gWindow;
	sf::Event event{};
	sf::RenderWindow* window;
	


};
