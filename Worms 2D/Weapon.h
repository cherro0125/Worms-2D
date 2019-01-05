#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Bullet.h"

enum Shoot_Direction
{
	SHOOT_LEFT,
	SHOOT_RIGHT
};


class Weapon : public sf::Drawable
{
public:
	Weapon() = delete;
	Weapon(float x, float y);
	virtual ~Weapon() = default;
	void setScale(float scale);
	void setRotation(float rotation);
	float getScale() const;
	sf::Sprite getSprite() const;
	float getPosX() const;
	float getPosY() const;
	void setPosX(float x);
	void setPosY(float y);
	void setBullet(Bullet *bullet);
	void setScaleVector(sf::Vector2f scale);
	sf::Vector2f getScaleVector() const;
	Bullet* getBullet() const;
	void update();
	void shoot(Shoot_Direction direction);
	bool getIsShooting() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite sprite;
	sf::Texture texture;
	std::string texturePath;
	Bullet *bullet = nullptr;
	float rotation = 0.0f;
	float scale = 0.5f;
	float posX;
	float posY;
	sf::Vector2f scaleVector = { scale,scale };
	bool isShooting = false;

};