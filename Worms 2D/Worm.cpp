#include "Worm.h"
#include <string>
#include <iostream>
#include "GameWindow.h"
#include "GameEvent.h"


Worm::Worm()
{
	this->windowWidth = 800;
	this->windowHeight = 600;
	this->hp = 100.0f;
	this->posX = 100 + rand() % 500;
	this->posY = 0 + rand() % 20;
	this->sprite.setPosition(this->posX, this->posY);
	this->hpShape.setSize(sf::Vector2f(50, 5));
	this->hpShape.setOrigin(25.0f, 2.5f);
	this->hpShape.setFillColor(sf::Color::Red);
	this->hpShape.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 10);
	//this->sprite.setRadius(wormRadius);
	//this->sprite.setFillColor(sf::Color::White);
	
	if (!texture.loadFromFile(textureImagePath))
		return;
	if (!texture2.loadFromFile(textureImagePath2))
		return;


	this->sprite.setTexture(texture);
	this->sprite.setScale(wormScale, wormScale);
	this->sprite.setOrigin(((this->sprite.getLocalBounds().width)*wormScale), 0);
	

	this->collisionPoints[UP] = { getWormX(), getWormY() };
	this->collisionPoints[UP_LEFT] = { left(), getWormY() + ((sprite.getLocalBounds().height*wormScale)*1/5) };
	this->collisionPoints[UP_RIGHT] = { right(), getWormY() +((sprite.getLocalBounds().height*wormScale) * 1 / 5) };
	this->collisionPoints[DOWN] = { getWormX(), bottom() };
	this->collisionPoints[DOWN_LEFT] = { left(), bottom() };
	this->collisionPoints[DOWN_RIGHT] = { right(), bottom() };
	this->collisionPoints[LEFT] = { left(),sprite.getPosition().y + (sprite.getLocalBounds().height*wormScale / 2) };
	this->collisionPoints[RIGHT] = { right(),sprite.getPosition().y + (sprite.getLocalBounds().height*wormScale / 2) };


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
	if (this->velocity.y < 0 && (checkCollision(collisionPoints[UP])/*|| checkCollision(collisionPoints[UP_LEFT])|| checkCollision(collisionPoints[UP_RIGHT])*/))
	{
		this->velocity.y = 0;
	}
	
	if (this->velocity.x < 0 && (checkCollision(collisionPoints[LEFT]) || checkCollision(collisionPoints[UP_LEFT])))
	{
		this->velocity.x = 0;
	}
	if (this->velocity.x > 0 && (checkCollision(collisionPoints[RIGHT]) || checkCollision(collisionPoints[UP_RIGHT])))
	{
		this->velocity.x = 0;
	}
	
	if(isMoving)
		this->sprite.move(velocity);
	this->posX = this->sprite.getPosition().x;
	this->posY = this->sprite.getPosition().y;

	this->collisionPoints[UP] = { getWormX(), getWormY() };
	this->collisionPoints[UP_LEFT] = { left(), getWormY() + ((sprite.getLocalBounds().height*wormScale)  / 5) };
	this->collisionPoints[UP_RIGHT] = { right(), getWormY() + ((sprite.getLocalBounds().height*wormScale)  / 5) };
	this->collisionPoints[DOWN] = { getWormX(), bottom() };
	this->collisionPoints[DOWN_LEFT] = { left(), bottom() - ((sprite.getLocalBounds().height*wormScale) / 5) };
	this->collisionPoints[DOWN_RIGHT] = { right(), bottom() - ((sprite.getLocalBounds().height*wormScale) / 5) };
	this->collisionPoints[LEFT] = { left(),sprite.getPosition().y + (sprite.getLocalBounds().height*wormScale / 2) };
	this->collisionPoints[RIGHT] = { right(),sprite.getPosition().y + (sprite.getLocalBounds().height*wormScale / 2) };

	if((bottom() < windowHeight)&&!checkCollision(collisionPoints[DOWN]))
	{
		this->velocity.y += 1;
		if (this->velocity.y > 10)
			this->velocity.y = 10;
		if (this->velocity.y > 0 && getWormX() > 0 && getWormX() < 800 && collisionPoints[DOWN].y > 0 && collisionPoints[DOWN].y < 590)
		{
			for (int i = 0; i < this->velocity.y; ++i)
			{
				if (colMap->getPixel(getWormX(), collisionPoints[DOWN].y + i).a > 0)
				{
					velocity.y = 0;
				}
			}
		}

	}
	else
	{

		//sprite.setPosition(sprite.getPosition().x, windowHeight - sprite.getLocalBounds().height*wormScale);
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+ getOffsetY(collisionPoints[DOWN]));
		this->velocity.y = 0;
		isJumping = false;
	}

	this->hpShape.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y - 10);
	this->hpShape.setSize(sf::Vector2f(this->hp - 0.5f, this->hpShape.getSize().y));
	
	

}
void Worm::setColMap(sf::Image *image)
{
	colMap = image;
}
int Worm::getOffsetY(sf::Vector2f point)
{
	int difference = 0;
	if (point.x > 0 && point.x < 800 && point.y>0 && point.y < 600)
	{
		while (colMap->getPixel(point.x, point.y).a > 0)
		{
			point.y -= 1;
			difference -= 1;

		}
	}
	return difference;
}


bool Worm::checkCollision(sf::Vector2f point)
{
	if (point.x > 0 && point.x < 800 && point.y>0 && point.y < 600)
	{
		if (colMap->getPixel(point.x, point.y).a > 0)
			return true;
	}

	return false;
}




void Worm::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if(this->hp > 0.0f)
	{
		target.draw(this->sprite, states);
		target.draw(this->hpShape, states);
	}


}

float Worm::left() const
{
	return sprite.getPosition().x - (sprite.getLocalBounds().width* wormScale) / 2.f ;
}
float Worm::right() const
{
	return sprite.getPosition().x + (sprite.getLocalBounds().width* wormScale) / 2.f ;
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
	if(!checkCollision(collisionPoints[LEFT])&& !checkCollision(collisionPoints[UP_LEFT]) )
	{ 
		sprite.setTexture(texture2);
		if (this->velocity.x > 0.0f)
			this->velocity.x = 0;
		this->isMoving = true;
		//this->velocity.y = 0;
		this->velocity.x += -baseVelocity;
		if (this->velocity.x < -3)
			this->velocity.x = -3;

		sprite.setScale({ -wormScale, wormScale });
		std::cout << "LEFT\n";
	}
}

void Worm::moveRight()
{
	if (!checkCollision(collisionPoints[RIGHT]) && !checkCollision(collisionPoints[UP_RIGHT]) )
	{
		sprite.setTexture(texture2);
		if (this->velocity.x < 0.0f)
			this->velocity.x = 0;
		this->isMoving = true;
		//this->velocity.y = 0;
		this->velocity.x += baseVelocity;
		if (this->velocity.x > 3)
			this->velocity.x = 3;

		sprite.setScale({ wormScale, wormScale });
		std::cout << "RIGHT\n";
	}

}

void Worm::jump()
{
	if (!isJumping && (!checkCollision(collisionPoints[UP])) /*&& !checkCollision(collisionPoints[UP_LEFT]) && !checkCollision(collisionPoints[UP_RIGHT]))*/)
	{
		isJumping = true;
		GameWindow::GetGameWindowInstance()->GetGameSound()->StartSample();
		this->velocity.y = -10;
		//sprite.move(velocity);
	}
}

void Worm::damage(float dmg)
{
	this->hp -= dmg;
}

bool Worm::isAlive()
{
	return (this->hp > 0.0f);
}

sf::Text Worm::getDebugTxt()
{
	debugTxt.setString("Worm X:" + std::to_string(getWormX()) + " Y:" + std::to_string(getWormY()));
	return debugTxt;
}




