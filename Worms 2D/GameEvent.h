#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
class GameEvent
{
public:

	GameEvent(GameWindow window);
	virtual ~GameEvent();
	sf::Event GetInstance();
	void handleEvents();



private:
	sf::Event event{};
	sf::RenderWindow* window;


};
