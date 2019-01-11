#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::Drawable
{
public:
	Button(float position_x, float position_y, const char * label,int id);
	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	void hover();
	void click();
	void clear();
	bool isHovered();
	bool isClicked();
	void setColorDefault();
	void setColorHovered();
	void setColorClicked();
	int getId();
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font font;
	sf::Text txt;
	sf::RectangleShape shape;
	sf::Vector2f size;
	bool hovered;
	bool clicked;
	sf::Color color_default;
	sf::Color color_hovered;
	sf::Color color_clicked;
	int id;
};
