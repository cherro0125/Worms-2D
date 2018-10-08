#include "GameEvent.h"




GameEvent::GameEvent(GameWindow window)
{
	this->window = window.GetInstance();
}

GameEvent::~GameEvent()
{
}

sf::Event GameEvent::GetInstance()
{
	return this->event;
}

void GameEvent::handleEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}
