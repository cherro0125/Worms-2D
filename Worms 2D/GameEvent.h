#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include<vector>
class GameEvent
{
public:

	GameEvent();
	virtual ~GameEvent();
	sf::Event GetInstance();
	void handleEvents();
	static GameEvent* GetEventInstance();




private:
	static GameEvent *ev;
	GameWindow *gWindow;
	sf::Event event{};
	sf::RenderWindow* window;
	Worm **current_worm;
	std::vector<Worm*> *worms = new std::vector<Worm*>;
	std::vector<Worm*> *worms_b = new std::vector<Worm*>;
	int worm_count;
	int worm_count_b;
	int *current_worm_id;
	int *current_team;
	


};
