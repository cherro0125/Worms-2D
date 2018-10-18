#include "Worm.h"
#include <string>
#include <iostream>
#include "GameWindow.h"
#include "GameEvent.h"


Worm::Worm(float width, float height) : windowWidth(width), windowHeight(height)
{
	this->posX = width / 2;
	this->posY = height / 2;
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


	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top() > 0)
	//{
	//	moveUp();
	//	this->sprite.move(velocity);
	//	std::cout << "UP\n";
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom() < windowHeight)
	//{
	//	moveDown();
	//	this->sprite.move(velocity);
	//	std::cout << "DOWN\n";
	//}
	//else
	//{
	//	stopMove();
	//}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && left() > 0)
	//if (GameEvent::GetEventInstance()->GetInstance().type == sf::Event::EventType::KeyPressed &&  GameEvent::GetEventInstance()->GetInstance().key.code == sf::Keyboard::Left && left() > 0)
	{
		moveLeft();
		//this->sprite.move(velocity);

		sprite.setScale({ -wormScale, wormScale });
		std::cout << "LEFT\n";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && right() < windowWidth)
	//else if (GameEvent::GetEventInstance()->GetInstance().type == sf::Event::EventType::KeyPressed &&  GameEvent::GetEventInstance()->GetInstance().key.code == sf::Keyboard::Right && right() < windowWidth)
	{
		moveRight();
		
		//this->sprite.move(velocity);
		sprite.setScale({ wormScale, wormScale });
		std::cout << "RIGHT\n";
	}
	else
	{
		stopMove();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && top() > 0 )
	{
		sprite.setTexture(texture2);
		GameWindow::GetGameWindowInstance()->GetGameSound()->StartSample();
		spacePressed = true;
		this->velocity.y = -10;
		sprite.move(velocity);
	}

	if(GameEvent::GetEventInstance()->GetInstance().type == sf::Event::EventType::KeyReleased && GameEvent::GetEventInstance()->GetInstance().key.code == sf::Keyboard::Space)
	{
		spacePressed = false;
		sprite.setTexture(texture);
	}

	if(bottom() < windowHeight)
	{

		this->velocity.y += 1;

	}
	else
	{

		this->velocity.y = 0;
	}

	//if (this->left() < 0)
	//{
	//	stopMove();
	//	std::cout << "LEFT BORDER\n";
	//}
	//else if (this->right() > this->windowWidth)
	//{
	//	stopMove();
	//}

	//if (this->top() < 0)
	//{
	//	stopMove();
	//}
	//else if (this->bottom() > this->windowHeight)
	//{
	//	stopMove();
	//}
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
	return sprite.getPosition().y + sprite.getLocalBounds().height;
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
	
}

void Worm::moveRight()
{
	sprite.setTexture(texture2);
	if (this->velocity.x < 0.0f)
		this->velocity.x = 0;
	this->isMoving = true;
	//this->velocity.y = 0;
	this->velocity.x += baseVelocity;
}

sf::Text Worm::getDebugTxt()
{
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
	return debugTxt;
}




