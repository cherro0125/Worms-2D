#include "Weapon.h"
#include <iostream>

Weapon::Weapon(float x, float y)
{
	this->posX = x;
	this->posY = y;
	this->sprite.setPosition(posX, posY);
	this->sprite.setOrigin((this->sprite.getLocalBounds().width*scale), 0);
	this->sprite.setRotation(rotation);
	this->sprite.setScale(scaleVector);
	
}

void Weapon::setScale(float scale)
{
	this->scale = scale;
}

void Weapon::setRotation(float rotation)
{
	this->rotation = rotation;
}

float Weapon::getScale() const
{
	return this->scale;
}

sf::Sprite Weapon::getSprite() const
{
	return this->sprite;
}

float Weapon::getPosX() const
{
	return this->posX;
}

float Weapon::getPosY() const
{
	return this->posY;
}

void Weapon::setPosX(float x)
{
	this->posX = x;
}

void Weapon::setPosY(float y)
{
	this->posY = y;
}

void Weapon::setBullet(Bullet* bullet)
{
	this->bullet = bullet;
}

void Weapon::setScaleVector(sf::Vector2f scale)
{
	this->scaleVector = scale;
}

sf::Vector2f Weapon::getScaleVector() const
{
	return this->scaleVector;
}

Bullet* Weapon::getBullet() const
{
	return this->bullet;
}

void Weapon::update()
{
	this->sprite.setPosition(sf::Vector2f(posX,posY));
	this->sprite.setScale(scaleVector);
	if(isShooting)
		this->bullet->update();
}

void Weapon::shoot(Shoot_Direction direction)
{
	bullet = new Bullet(posX, posY);
	if(direction == SHOOT_RIGHT)
	{
		bullet->setScaleVector({ bullet->getScale(),bullet->getScale() });
		bullet->setVelocity(bullet->getVelocity().x);
		bullet->update();
	}
	else if(direction == SHOOT_LEFT)
	{
		bullet->setScaleVector({ -bullet->getScale(),bullet->getScale() });
		bullet->setVelocity(-bullet->getVelocity().x);
		bullet->update();
	}
	isShooting = true;
	playShootSound();
}



bool Weapon::getIsShooting() const
{
	return this->isShooting;
}

void Weapon::setIsShooting(bool isShooting)
{
	this->isShooting = isShooting;
}

void Weapon::playShootSound()
{
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}
