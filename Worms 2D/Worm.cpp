#include "Worm.h"
#include <string>
#include <iostream>
#include "GameWindow.h"
#include "GameEvent.h"


Worm::Worm()
{
	this->windowWidth = 800;
	this->windowHeight = 600;
	this->posX = 100 + rand() % 500;
	this->posY = 100 + rand() % 500;
	this->sprite.setPosition(this->posX, this->posY);
	//this->sprite.setRadius(wormRadius);
	//this->sprite.setFillColor(sf::Color::White);
	
	if (!texture.loadFromFile(textureImagePath))
		return;
	if (!texture2.loadFromFile(textureImagePath2))
		return;


	this->sprite.setTexture(texture);
	this->sprite.setOrigin(this->wormRadius, this->wormRadius);
	this->sprite.setScale(wormScale, wormScale);
	this->isMoving = true;

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



	if(bottom() < windowHeight)
	{
		this->velocity.y += 1;
		if (this->velocity.y > 20)
			this->velocity.y = 20;

	}
	else
	{
		sprite.setPosition(sprite.getPosition().x, windowHeight - sprite.getLocalBounds().height*wormScale);
		this->velocity.y = 0;
		isJumping = false;
	}

}




void Worm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);

}

float Worm::left() const
{
	return sprite.getPosition().x - sprite.getLocalBounds().width / 2;
}
float Worm::right() const
{
	return sprite.getPosition().x + sprite.getLocalBounds().width / 2;
}
float Worm::top() const
{
	return sprite.getPosition().y;
}
float Worm::bottom() const
{
	return sprite.getPosition().y + sprite.getLocalBounds().height*wormScale;
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
	//this->isMoving = false;
	if (this->velocity.x != 0.0f)
	{
		this->velocity.x = 0;
	}
	sprite.setTexture(texture);
	
}

void Worm::moveUp()
{
	this->isMoving = true;
	this->velocity.y += -baseVelocity;
	//this->velocity.x = 0;
}

void Worm::moveDown()
{
	
	this->isMoving = true;
	this->velocity.y += baseVelocity;
	//this->velocity.x = 0;
}

void Worm::moveLeft()
{
	sprite.setTexture(texture2);
	if (this->velocity.x > 0.0f)
		this->velocity.x = 0;
	this->isMoving = true;
	//this->velocity.y = 0;
	this->velocity.x += -baseVelocity;
	if (this->velocity.x < -10)
		this->velocity.x = -10;

	sprite.setScale({ -wormScale, wormScale });
	std::cout << "LEFT\n";
}

void Worm::moveRight()
{
	sprite.setTexture(texture2);
	if (this->velocity.x < 0.0f)
		this->velocity.x = 0;
	this->isMoving = true;
	//this->velocity.y = 0;
	this->velocity.x += baseVelocity;
	if (this->velocity.x > 10)
		this->velocity.x = 10;

	sprite.setScale({ wormScale, wormScale });
	std::cout << "RIGHT\n";
}

void Worm::jump()
{
	if (!isJumping)
	{
		isJumping = true;
		GameWindow::GetGameWindowInstance()->GetGameSound()->StartSample();
		this->velocity.y = -20;
		sprite.move(velocity);
	}
}

sf::Text Worm::getDebugTxt()
{
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
	return debugTxt;
}




