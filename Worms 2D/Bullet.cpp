#include "Bullet.h"



Bullet::Bullet(float x, float y)
{
	this->posX = x;
	this->posY = y;
	this->sprite.setPosition(posX, posY);
	if (!texture.loadFromFile(texturePath))
		return;
	this->sprite.setTexture(texture);
	this->sprite.setOrigin((this->sprite.getLocalBounds().width*scale), 0);
	this->sprite.setScale(scale, scale);
	this->sprite.setRotation(rotation);
}

void Bullet::setScale(float scale)
{
	this->scale = scale;
}

void Bullet::setRotation(float rotation)
{
	this->rotation = rotation;
}

sf::Sprite Bullet::getSprite() const
{
	return this->sprite;
}

void Bullet::setVelocity(sf::Vector2f)
{
	this->velocity = velocity;
}

void Bullet::setVelocity(float x, float y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

sf::Vector2f Bullet::getVelocity() const
{
	return this->velocity;
}

float Bullet::getPosX() const
{
	return this->posX;
}

float Bullet::getPosY() const
{
	return this->posY;
}

void Bullet::setPosX(float x)
{
	this->posX = x;
}

void Bullet::setPosY(float y)
{
	this->posY = y;
}

void Bullet::update()
{
	this->sprite.setScale(scaleVector);
	this->sprite.move(velocity);
	this->posX = this->sprite.getPosition().x;
	this->posY = this->sprite.getPosition().y;
}

float Bullet::getScale() const
{
	return this->scale;
}

void Bullet::setScaleVector(sf::Vector2f scale)
{
	this->scaleVector = scale;
}

sf::Vector2f Bullet::getScaleVector() const
{
	return this->scaleVector;
}


void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite,states);
}
