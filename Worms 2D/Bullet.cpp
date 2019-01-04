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

sf::Sprite Bullet::getSprite()
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

void Bullet::update()
{
	this->sprite.move(velocity);
	this->posX = this->sprite.getPosition().x;
	this->posY = this->sprite.getPosition().y;
}


void Bullet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite,states);
}
