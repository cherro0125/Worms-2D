#include "GameEvent.h"
#include <iostream>


GameEvent::GameEvent()
{
	this->gWindow = GameWindow::GetGameWindowInstance();
	this->window = gWindow->GetInstance();
	current_worm = this->gWindow->GetCurrentWorm();
	worms = this->gWindow->GetWormsArray();
	worm_count = this->gWindow->GetWormCount();
	current_worm_id = this->gWindow->GetCurrentWormID();
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
		if (this->event.type == sf::Event::KeyPressed)
		{
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			if (this->event.key.code == sf::Keyboard::Tab)
			{
				*current_worm_id = (*current_worm_id + 1) % worm_count;
				(*current_worm)->stopMove();
				*current_worm = &(worms[*current_worm_id]);
			}
			if (this->event.key.code == sf::Keyboard::Space)
			{
				(*current_worm)->jump();
			}
		}
		

		
	

	
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (*current_worm)->left() > 0)
	{
		(*current_worm)->moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (*current_worm)->right() < this->window->getSize().x)
	{
		
		(*current_worm)->moveRight();
	}
	else
	{
		(*current_worm)->stopMove();
	}
}


GameEvent *GameEvent::ev = nullptr;

GameEvent* GameEvent::GetEventInstance()
{
	if (ev == nullptr) ev = new GameEvent();
	return ev;
}
