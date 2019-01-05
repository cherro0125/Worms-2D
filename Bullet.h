#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Bullet : public sf::Drawable
{
public:
	Bullet() = delete;
	Bullet(float x, float y);
	virtual ~Bullet() = default;
	void setScale(float scale);
	void setRotation(float rotation);
	sf::Sprite getSprite() const;
	void setVelocity(sf::Vector2f);
	void setVelocity(float x, float y = 0);
	sf::Vector2f getVelocity() const;
	float getPosX() const;
	float getPosY() const;
	void setPosX(float x);
	void setPosY(float y);
	void update();
	float getScale() const;
	void setScaleVector(sf::Vector2f scale);
	sf::Vector2f getScaleVector() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string texturePath = "resources/images/bullet.png";
	float scale = 0.2f;
	sf::Vector2f scaleVector = { scale,scale };
	float rotation = 0.0f;
	float posX;
	float posY;
	sf::Vector2f velocity{ 1.0f,0.0f };
};
