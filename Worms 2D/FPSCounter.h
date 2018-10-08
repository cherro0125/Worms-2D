#pragma once
#include <SFML/Graphics.hpp>
class FPSCounter
{
public:
	FPSCounter(sf::RenderWindow* window, unsigned int fontSize = 12);
	void start();
	void drawFPS();
	void setColor(sf::Color color);


private:
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text txt;
	sf::Clock clock;
	sf::Time time = sf::Time::Zero;
	sf::Color fpsColor = sf::Color::Green;
	std::string fontPath = "resources/fonts/sansation.ttf";
	unsigned int fontSize;
	float fps_f;
	int fps_i;
	void stop();

};
