#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "FPSCounter.h"
#include "Worm.h"
class GameWindow
{
public:
	GameWindow() = delete;
	GameWindow(unsigned int width, unsigned int height, std::string name);
	sf::RenderWindow* GetInstance() const;
	void ChangeFrameLimit(unsigned int limit = 60) const;
	void MainLoop();
	void UpdateWorm();
	Worm GetWorm();
	void SetBackgroundColor(sf::Color color);


private:
	std::string windowName;
	unsigned int widht;
	unsigned int height;
	sf::RenderWindow* window;
	Worm worm{ (float)widht, (float)height };
	sf::Color bgColor;
	FPSCounter *fpsCounter;
};
