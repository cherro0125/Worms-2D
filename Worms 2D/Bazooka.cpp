#include "Bazooka.h"

Bazooka::Bazooka(float x, float y): Weapon(x,y)
{

	this->texturePath = bazookaTexturePath;
	if (!texture.loadFromFile(texturePath))
		return;
	this->sprite.setTexture(texture);
	this->sprite.setOrigin((this->sprite.getLocalBounds().width*scale / 2), (this->sprite.getLocalBounds().height*scale / 2));
	this->scaleVector = { scale,scale };
	this->sprite.setScale(scaleVector);
	this->damage = bazookaDamage;
}

void Bazooka::playShootSound()
{
}


