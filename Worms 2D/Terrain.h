#pragma once
#include <SFML/Graphics.hpp>
class Terrain : public sf::Drawable
{
public:
	Terrain();
	void erase(const sf::Drawable &eraser);
	sf::Image map;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite sprite;
	sf::RenderTexture rTexture;
	sf::Texture texture;

};