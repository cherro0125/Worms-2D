#include "Worm.h"
#include <string>
#include <iostream>


Worm::Worm(float width, float height) : windowWidth(width), windowHeight(height)
{
	this->posX = width / 2;
	this->posY = height / 2;
	this->sprite.setPosition(this->posX, this->posY);
	//this->sprite.setRadius(wormRadius);
	//this->sprite.setFillColor(sf::Color::White);
	
	if (!texture.loadFromFile(textureImagePath))
		return;

	this->sprite.setTexture(texture);
	this->sprite.setOrigin(this->wormRadius, this->wormRadius);
	this->isMoving = false;


	if (!this->font.loadFromFile(fontPath))
		return;
	debugTxt.setFont(font);
	debugTxt.setFillColor(sf::Color::White);
	debugTxt.setCharacterSize(12);
	debugTxt.setPosition(font.getLineSpacing(debugTxt.getCharacterSize()), font.getLineSpacing(debugTxt.getCharacterSize() * 2));
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
}

Worm::~Worm()
{

}

void Worm::update()
{
	if(isMoving)
		this->sprite.move(velocity);
	this->posX = this->sprite.getPosition().x;
	this->posY = this->sprite.getPosition().y;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp();
		this->sprite.move(velocity);
		std::cout << "UP\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown();
		this->sprite.move(velocity);
		std::cout << "DOWN\n";
	}
	else
	{
		stopMove();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveLeft();
		this->sprite.move(velocity);
		std::cout << "LEFT\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveRight();
		this->sprite.move(velocity);
		std::cout << "RIGHT\n";
	}
	else
	{
		stopMove();
	}
	if (this->left() < 5)
	{
		stopMove();
		std::cout << "LEFT BORDER\n";
	}
	else if (this->right() > this->windowWidth)
	{
		stopMove();
	}

	if (this->top() < 0)
	{
		stopMove();
	}
	else if (this->bottom() > this->windowHeight)
	{
		stopMove();
	}
}



void Worm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);

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

void Worm::stopMove()
{
	this->isMoving = false;
}

void Worm::moveUp()
{
	this->isMoving = true;
	this->velocity.y = -baseVelocity;
	this->velocity.x = 0;
}

void Worm::moveDown()
{
	this->isMoving = true;
	this->velocity.y = baseVelocity;
	this->velocity.x = 0;
}

void Worm::moveLeft()
{
	this->isMoving = true;
	this->velocity.y = 0;
	this->velocity.x = -baseVelocity;
}

void Worm::moveRight()
{
	this->isMoving = true;
	this->velocity.y = 0;
	this->velocity.x = baseVelocity;
}

sf::Text Worm::getDebugTxt()
{
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
	return debugTxt;
}




