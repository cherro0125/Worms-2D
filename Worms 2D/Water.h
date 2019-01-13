#pragma once
#include <SFML/Graphics.hpp>
class Water : public sf::Drawable
{
public:
	/*!
	 * \brief Konstruktor
	 *
	 */
	Water();
	/*!
	 * \brief Aktualizuje obiekt wody co klatke
	 *
	 */
	void update();

protected:
	/*!
	 * \brief Rysuje obiekt na ekranie (dzidziczona z SFML)
	 *
	 * \param target
	 * \param states
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	/*!
	 * \brief Pierwsza warstwa obrazu wody
	 *
	 */
	sf::Sprite layer0;
	/*!
	 * \brief Druga warstwa obrazu wody
	 *
	 */
	sf::Sprite layer1;
	/*!
	 * \brief Trzecia warstwa obrazu wody
	 *
	 */
	sf::Sprite layer2;
	/*!
	 * \brief Czwarta warstwa obrazu wody
	 *
	 */
	sf::Sprite layer3;
	/*!
	 * \brief Tekstura wody
	 *
	 */
	sf::Texture texture;
	/*!
	 * \brief Obiekt rysowany na ekranie
	 *
	 */
	sf::RectangleShape bg;
	/*!
	 * \brief Wektor przesuniêcia
	 *
	 */
	sf::Vector2f offset;
	/*!
	 * \brief Zmiana X
	 *
	 */
	bool change_direction_x;
	/*!
	 * \brief Zmiana Y
	 *
	 */
	bool change_direction_y;
};
