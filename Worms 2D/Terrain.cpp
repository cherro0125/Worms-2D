#include "Terrain.h"
#include <iostream>
Terrain::Terrain()
{
	map.loadFromFile("resources/images/map_test_01.png");

	texture.loadFromImage(this->map);
	sprite.setTexture(texture, true);
	rTexture.create(800, 600);
	rTexture.clear(sf::Color(0, 0, 0, 0));
	rTexture.draw(sprite);
	rTexture.display();
	texture = rTexture.getTexture();
	sprite.setTexture(texture, true);
	map=texture.copyToImage();

}
void Terrain::erase(const sf::Drawable &eraser)
{
	//rTexture.clear(sf::Color(0, 0, 0, 0));
	//rTexture.draw(sprite);
	rTexture.draw(eraser,sf::RenderStates(sf::BlendNone));
	rTexture.display();
	texture = rTexture.getTexture();
	sprite.setTexture(texture, true);
	map = texture.copyToImage();

}


void Terrain::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);

}
