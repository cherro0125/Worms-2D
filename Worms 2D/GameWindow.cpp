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
		
		this->worm_count = 5;
		this->worms = new Worm[worm_count];
		this->current_worm_id = 0;
		this->current_worm = &(worms[this->current_worm_id]);
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
	this->fpsCounter->start();
	this->window->clear(sf::Color(71,71,71));
	for (int i = 0; i < worm_count; ++i)
	{
		this->window->draw(worms[i]);
		this->UpdateWorms(i);
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