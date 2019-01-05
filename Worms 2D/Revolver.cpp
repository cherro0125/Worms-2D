#include "Revolver.h"
#include "GameSound.h"
#include "GameWindow.h"

Revolver::Revolver(float x, float y) :Weapon(x,y)
{
	this->texturePath = revolverTexturePath;
	if (!texture.loadFromFile(texturePath))
		return;
	this->sprite.setTexture(texture);
	this->scaleVector = { scale,scale };
	this->sprite.setScale(scaleVector);
	this->damage = revorverDamage;
}

void Revolver::playShootSound()
{
	GameSound *gs = GameWindow::GetGameWindowInstance()->GetGameSound();
	gs->StartRevolverSound();
}

void Revolver::shoot(Shoot_Direction direction)
{
	bullet = new Bullet(posX, posY);
	bullet->setVelocity(20);
	if (direction == SHOOT_RIGHT)
	{
		bullet->setScaleVector({ bullet->getScale(),bullet->getScale() });
		bullet->setVelocity(bullet->getVelocity().x);
		bullet->update();
	}
	else if (direction == SHOOT_LEFT)
	{
		bullet->setScaleVector({ -bullet->getScale(),bullet->getScale() });
		bullet->setVelocity(-bullet->getVelocity().x);
		bullet->update();
	}
	isShooting = true;
	playShootSound();
}
