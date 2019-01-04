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
	sf::Sprite getSprite();
	void update();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string texturePath = "resources/images/bullet.png";
	float scale = 0.5f;
	float rotation = 0.0f;
	float posX;
	float posY;
	sf::Vector2f velocity{ 1.0f,0.0f };
};
