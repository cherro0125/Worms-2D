#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 1024), "Worms 2D");

	while(window.isOpen())
	{
		//test22
		sf::Event ev;
		while(window.pollEvent(ev))
		{
			if(ev.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	return 0;
}