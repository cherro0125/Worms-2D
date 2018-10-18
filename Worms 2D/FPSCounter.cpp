#include "FPSCounter.h"
#include <iostream>
#include "GameWindow.h"


FPSCounter::FPSCounter(unsigned int fontSize) : fontSize(fontSize), fps_f(0.0f), fps_i(0)
{
	this->window = GameWindow::GetGameWindowInstance()->GetInstance();
	if (!this->font.loadFromFile(fontPath))
		return;
	txt.setFont(font);
	txt.setFillColor(fpsColor);
	txt.setCharacterSize(fontSize);
	txt.setPosition(font.getLineSpacing(txt.getCharacterSize()), font.getLineSpacing(txt.getCharacterSize()));
	txt.setString("FPS:" + std::to_string(fps_i));


}

void FPSCounter::start()
{
	this->time = this->clock.getElapsedTime();
}

void FPSCounter::stop()
{

	fps_f = (1.0f / time.asSeconds());
	fps_i = (int)fps_f;
	clock.restart().asSeconds();
	txt.setString("FPS:" + std::to_string(fps_i));
}

void FPSCounter::drawFPS()
{
	stop();
	if (fps_i <= 20) setColor(sf::Color::Red);
	else setColor(sf::Color::Green);
	this->window->draw(txt);
}

void FPSCounter::setColor(sf::Color color)
{

	if (this->txt.getFillColor() != color)
	{
		this->fpsColor = color;
		this->txt.setFillColor(color);
	}
}



