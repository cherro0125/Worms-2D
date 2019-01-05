#include "Water.h"
Water::Water()
{
	
	texture.loadFromFile("resources/images/water.png");
	layer0.setTexture(texture, true);
	layer1.setTexture(texture, true);
	layer2.setTexture(texture, true);
	layer3.setTexture(texture, true);
	
	layer0.setScale(-0.6,0.4);
	layer1.setScale(0.7,0.5);
	layer2.setScale(-0.8,0.6);

	layer0.setPosition(800, 460);
	layer1.setPosition(0, 490);
	layer2.setPosition(800, 520);
	layer3.setPosition(0, 550);

	layer0.setColor(sf::Color(135, 155, 165));
	layer1.setColor(sf::Color(165, 185, 195));
	layer2.setColor(sf::Color(195, 215, 225));

	bg.setPosition(0, 455);
	bg.setFillColor(sf::Color(30,60, 120));
	bg.setSize(sf::Vector2f(800, 150));

	offset.x = 0.5f;
	offset.y = 0;
	change_direction_x = false;;
	change_direction_y=false;

}

void Water::update()
{
	if (offset.x >= 0)
		change_direction_x = false;
	if (offset.x <= -40)
		change_direction_x = true;

	if (offset.y >= 10)
		change_direction_y = false;
	if (offset.y <= -10)
		change_direction_y = true;

	if (change_direction_x)
		offset.x += 0.4f;
	else
		offset.x -= 0.4f;

	if (change_direction_y)
		offset.y += 0.2f;
	else
		offset.y -= 0.2f;
	
	bg.setPosition(bg.getPosition().x, 455+offset.y*0.2f);
	layer0.setPosition(800+offset.x*layer0.getScale().x,460+offset.y*layer0.getScale().y);
	layer1.setPosition(offset.x*layer1.getScale().x,490+offset.y*layer1.getScale().y);
	layer2.setPosition(800+offset.x*layer2.getScale().x,520+offset.y*layer2.getScale().y);
	layer3.setPosition(offset.x,550+offset.y);
}

void Water::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->bg, states);
	target.draw(this->layer0, states);
	target.draw(this->layer1, states);
	target.draw(this->layer2, states);
	target.draw(this->layer3, states);
	

}