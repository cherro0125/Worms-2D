#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "FPSCounter.h"
#include "Worm.h"
#include "GameSound.h"

class GameWindow
{
public:
	GameWindow() = delete;
	GameWindow(unsigned int width, unsigned int height, std::string name);
	sf::RenderWindow* GetInstance() const;
	static GameWindow* GetGameWindowInstance(unsigned int width = 1280, unsigned int height = 1024, std::string name = "Worms 2D");
	void ChangeFrameLimit(unsigned int limit = 60) const;
	void MainLoop();
	void UpdateWorm();
	Worm GetWorm();
	void SetBackgroundColor(sf::Color color);


private:
	static GameWindow *gw;
	std::string windowName;
	unsigned int widht;
	unsigned int height;
	static sf::RenderWindow* window;
	Worm worm{ (float)widht, (float)height };
	sf::Color bgColor;
	FPSCounter *fpsCounter;
	static GameSound* gs;
};

