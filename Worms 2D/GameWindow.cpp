#include "GameWindow.h"

GameWindow::GameWindow(unsigned int width, unsigned int height, std::string name) : widht(width), height(height), windowName(name)
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), name);
	this->window->setFramerateLimit(60);
	this->fpsCounter = new FPSCounter(this->window);


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
	this->window->clear(sf::Color::Black);
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
