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
	static GameEvent* GetEventInstance();
	void moveHandle();



private:
	static GameEvent *ev;
	GameWindow *gWindow;
	sf::Event event{};
	sf::RenderWindow* window;
	Worm **current_worm;
	Worm *worms;
	int worm_count;
	int *current_worm_id;
	


};
