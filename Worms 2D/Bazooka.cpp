#include "Bazooka.h"

Bazooka::Bazooka(float x, float y): Weapon(x,y)
{

	this->texturePath = bazookaTexturePath;
	if (!texture.loadFromFile(texturePath))
		return;
	this->sprite.setTexture(texture);
	this->scaleVector = { scale,scale };
	this->sprite.setScale(scaleVector);
	this->damage = bazookaDamage;
}

void Bazooka::playShootSound()
{
}


