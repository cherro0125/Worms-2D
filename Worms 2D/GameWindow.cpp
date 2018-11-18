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
	}

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
	this->window->draw(worm);
	this->UpdateWorm();
	this->fpsCounter->drawFPS();
	this->window->draw(this->GetWorm().getDebugTxt());
	this->window->display();




}


void GameWindow::UpdateWorm()
{
	this->worm.update();
	


	

}

Worm GameWindow::GetWorm()
{
	return this->worm;
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