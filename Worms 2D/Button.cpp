#include "Button.h"


Button::Button(float position_x, float position_y, const char * label, int id)
{

	color_default = sf::Color(128, 128, 128);
	color_hovered = sf::Color(160, 160, 160);
	color_clicked = sf::Color(96, 96, 96);

	this->size.x = 400;
	this->size.y = 100;
	this->shape.setSize(size);
	this->shape.setFillColor(color_default);
	this->shape.setOrigin(size.x/2, size.y/2);
	this->shape.setPosition(position_x, position_y);

	this->font.loadFromFile("resources/fonts/sansation.ttf");
	this->txt.setFont(font);
	this->txt.setFillColor(sf::Color(255, 255, 255));
	this->txt.setCharacterSize(28);
	this->txt.setString(label);
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, (this->txt.getLocalBounds().height / 2) + (this->txt.getCharacterSize()/3));
	this->txt.setPosition(position_x, position_y);
	this->hovered = false;
	this->clicked = false;
	this->id = id;
	
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->shape, states);
	target.draw(this->txt, states);

}

sf::Vector2f Button::getSize()
{
	return this->size;
}

sf::Vector2f Button::getPosition()
{
	return this->shape.getPosition();
}

void Button::hover()
{
	this->hovered = true;
	this->setColorHovered();
}

void Button::click()
{
	this->clicked = true;
	this->setColorClicked();
}

void Button::clear()
{
	this->hovered = false;
	this->clicked = false;
	this->setColorDefault();
}

bool Button::isHovered()
{
	return this->hovered;
}

bool Button::isClicked()
{
	return this->clicked;
}

void Button::setColorDefault()
{
	this->shape.setFillColor(color_default);
}

void Button::setColorHovered()
{
	this->shape.setFillColor(color_hovered);
}

void Button::setColorClicked()
{
	this->shape.setFillColor(color_clicked);
}

int Button::getId()
{
	return this->id;
}