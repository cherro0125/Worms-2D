#pragma once
#include <SFML/Graphics.hpp>
class Water : public sf::Drawable
{
public:
	Water();
	void update();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite layer0;
	sf::Sprite layer1;
	sf::Sprite layer2;
	sf::Sprite layer3;
	sf::Texture texture;
	sf::RectangleShape bg;
	sf::Vector2f offset;
	bool change_direction_x;
	bool change_direction_y;
};
