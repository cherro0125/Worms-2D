#include "GameEvent.h"
#include <iostream>


GameEvent::GameEvent()
{
	this->gWindow = GameWindow::GetGameWindowInstance();
	this->window = gWindow->GetInstance();
	
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
