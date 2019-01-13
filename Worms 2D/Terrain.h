#pragma once
#include <SFML/Graphics.hpp>
/*!
 * \brief Klasa terenu(mapy)
 *
 */
class Terrain : public sf::Drawable
{
public:
	/*!
	 * \brief Konstruktor
	 *
	 */
	Terrain();
	/*!
	 * \brief Usuwa element z mapy
	 *
	 * \param eraser
	 */
	void erase(const sf::Drawable &eraser);
	/*!
	 * \brief Resetuje mape
	 *
	 */
	void reset();
	/*!
	 * \brief Obiekt mapy
	 *
	 */
	sf::Image map;

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
	 * \brief Obiekt mapy rysowany na ekranie
	 *
	 */
	sf::Sprite sprite;
	/*!
	 * \brief Tekstura
	 *
	 */
	sf::RenderTexture rTexture;
	/*!
	 * \brief Tekstura
	 *
	 */
	sf::Texture texture;
	/*!
	 * \brief Kopia mapy
	 *
	 */
	sf::Image map_copy;

};