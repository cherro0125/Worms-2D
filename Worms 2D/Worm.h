#pragma once
#include <SFML/Graphics.hpp>
class Worm : public sf::Drawable
{
public:
	Worm(float width, float height);
	Worm() = delete;
	virtual ~Worm();
	void update();
	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	float getWormX() const;
	float getWormY() const;
	void stopMove();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	sf::Text getDebugTxt();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	//sf::CircleShape sprite;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font font;
	std::string fontPath = "resources/fonts/sansation.ttf";
	std::string textureImagePath = "resources/images/worm.png";
	sf::Text debugTxt;
	const float wormRadius{ 10.0f };
	const float wormVelocity{ 0.0f };
	const float baseVelocity{ 5.0f };
	sf::Vector2f velocity{ wormVelocity,wormVelocity };
	float posX;
	float posY;
	float windowHeight;
	float windowWidth;
	bool isMoving;
};
