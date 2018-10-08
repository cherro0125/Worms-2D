#include "Worm.h"
#include <string>



Worm::Worm(float width, float height) : windowWidth(width), windowHeight(height)
{
	this->posX = width / 2;
	this->posY = height / 2;
	this->shape.setPosition(this->posX, this->posY);
	this->shape.setRadius(wormRadius);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOrigin(this->wormRadius, this->wormRadius);


	if (!this->font.loadFromFile(fontPath))
		return;
	debugTxt.setFont(font);
	debugTxt.setFillColor(sf::Color::White);
	debugTxt.setCharacterSize(12);
	debugTxt.setPosition(font.getLineSpacing(debugTxt.getCharacterSize()), font.getLineSpacing(debugTxt.getCharacterSize() * 2));
	debugTxt.setString("Ball X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
}

Worm::~Worm()
{

}

void Worm::update()
{
	this->shape.move(velocity);
	this->posX = this->shape.getPosition().x;
	this->posY = this->shape.getPosition().y;

	if (this->left() < 0)
	{
		this->velocity.x = wormVelocity;
	}
	else if (this->right() > this->windowWidth)
	{
		this->velocity.x = -wormVelocity;
	}

	if (this->top() < 0)
	{
		this->velocity.y = wormVelocity;
	}
	else if (this->bottom() > this->windowHeight)
	{
		this->velocity.y = -wormVelocity;
	}
}

void Worm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->shape, states);

}

float Worm::left() const
{
	return this->posX - this->wormRadius;
}
float Worm::right() const
{
	return this->posX + this->wormRadius;
}
float Worm::top() const
{
	return this->posY - this->wormRadius;
}
float Worm::bottom() const
{
	return this->posY + this->wormRadius;
}

float Worm::getWormX() const
{
	return this->posX;
}

float Worm::getWormY() const
{
	return this->posY;
}

sf::Text Worm::getDebugTxt()
{
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
	return debugTxt;
}




