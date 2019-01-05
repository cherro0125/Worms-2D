#include "Revolver.h"

Revolver::Revolver(float x, float y) :Weapon(x,y)
{
	this->texturePath = revolverTexturePath;
	if (!texture.loadFromFile(texturePath))
		return;
	this->sprite.setTexture(texture);
	this->scaleVector = { scale,scale };
	this->sprite.setScale(scaleVector);
}
