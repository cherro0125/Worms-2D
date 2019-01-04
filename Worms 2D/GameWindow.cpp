#include "GameWindow.h"

GameWindow::GameWindow(unsigned int width, unsigned int height, std::string name) : width(width), height(height), windowName(name)
{
	if(this->window == nullptr)
	{
		this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
		this->window->setFramerateLimit(60);
		this->fpsCounter = new FPSCounter();
		this->gs = new GameSound();
		this->gs->PlayMainMusic();
		
		this->worm_count = 3;
		this->worms = new Worm[worm_count];
		this->current_worm_id = 0;
		this->current_worm = &(worms[this->current_worm_id]);
		for (int i = 0; i < worm_count; ++i)
		{
			worms[i].setColMap(&(terrain.map));
		}
		
		
	}

}

GameWindow::~GameWindow()
{
	delete[] worms;
}

sf::RenderWindow* GameWindow::GetInstance() const
{
	return this->window;
}

void GameWindow::ChangeFrameLimit(unsigned int limit) const
{
	this->window->setFramerateLimit(limit);
}

void GameWindow::MainLoop()
{
	sf::RectangleShape cpoints[8];
	for (int i = 0; i < 8; ++i)
	{
		cpoints[i].setSize(sf::Vector2f(2.f, 2.f));
	}
	cpoints[0].setPosition(current_worm->collisionPoints[UP]);
	cpoints[1].setPosition(current_worm->collisionPoints[UP_LEFT]);
	cpoints[2].setPosition(current_worm->collisionPoints[UP_RIGHT]);
	cpoints[3].setPosition(current_worm->collisionPoints[DOWN]);
	cpoints[4].setPosition(current_worm->collisionPoints[DOWN_LEFT]);
	cpoints[5].setPosition(current_worm->collisionPoints[DOWN_RIGHT]);
	cpoints[6].setPosition(current_worm->collisionPoints[LEFT]);
	cpoints[7].setPosition(current_worm->collisionPoints[RIGHT]);


	this->fpsCounter->start();
	
	this->window->clear(sf::Color(71,71,71));
	this->window->draw(terrain);
	for (int i = 0; i < worm_count; ++i)
	{
		this->window->draw(worms[i]);
		this->UpdateWorms(i);
		
	}
	for (int i = 0; i < 8; ++i)
	{
		if((*current_worm).isAlive())
			this->window->draw(cpoints[i]);
	}
	this->fpsCounter->drawFPS();
	this->window->draw((**(this->GetCurrentWorm())).getDebugTxt());
	this->window->display();



}


void GameWindow::UpdateWorms(int i)
{

	this->worms[i].update();
	

	

}

Worm **GameWindow::GetCurrentWorm()
{
	return &(this->current_worm);
}

Worm *GameWindow::GetWormsArray()
{
	return this->worms;
}

int GameWindow::GetWormCount()
{
	return this->worm_count;
}

int *GameWindow::GetCurrentWormID()
{
	return &(this->current_worm_id);
}

void GameWindow::SetBackgroundColor(sf::Color color)
{
	this->bgColor = color;
}

GameSound* GameWindow::GetGameSound() const
{
	return this->gs;
}

//Static variables and methods

GameWindow* GameWindow::gw = nullptr;
sf::RenderWindow* GameWindow::window = nullptr;
GameSound* GameWindow::gs = nullptr;


GameWindow* GameWindow::GetGameWindowInstance(unsigned int width, unsigned int height, std::string name)
{
	if (gw == nullptr) 
		gw = new GameWindow(width, height, name);
	return gw;
}