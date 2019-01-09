#include "Weapon.h"
#include <iostream>

Weapon::Weapon(float x, float y)
{
	this->posX = x;
	this->posY = y;
	this->sprite.setPosition(posX, posY);
	this->sprite.setOrigin((this->sprite.getLocalBounds().width*scale / 2), (this->sprite.getLocalBounds().height*scale / 2));
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

float Weapon::getRotation() const
{
	return this->rotation;
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

Bullet* Weapon::getBullet() 
{
	return this->bullet;
}

void Weapon::update()
{
	this->sprite.setPosition(sf::Vector2f(posX,posY));
	if(this->sprite.getScale() != scaleVector)
		this->sprite.setScale(scaleVector);
	this->sprite.setRotation(rotation);
	if(isShooting)
		this->bullet->update();
}

void Weapon::shoot(float angle)
{
	bullet = new Bullet(posX, posY);
	
	bullet->setScaleVector({ bullet->getScale(),bullet->getScale() });
	std::cout << angle << std::endl;
	bullet->setVelocity(sf::Vector2f(3 * cosf(angle*355/113/180), 3 * sinf(angle * 355 / 113 / 180)));
	bullet->setRotation(angle);
	bullet->update();
	
	
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

void Weapon::setDamage(float damage)
{
	this->damage = damage;
}

float Weapon::getDamage() const
{
	return this->damage;
}

void Weapon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}
