#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Bullet : public sf::Drawable
{
public:
	/*!
	 * \brief Konstruktor domyślny który jest usunięty
	 *
	 */
	Bullet() = delete;
	/*!
	 * \brief konstruktor pocisku
	 *
	 * \param x - współrzędna X pojawienia się pocisku na ekranie
	 * \param y - współrzędna Y pojawienia się pocisku na ekranie
	 */
	Bullet(float x, float y);
	/*!
	 * \brief Destruktor domyślny
	 *
	 */
	virtual ~Bullet() = default;
	/*!
	 * \brief Ustawia skale pocisku
	 *
	 * \param scale - skala pocisku
	 */
	void setScale(float scale);
	/*!
	 * \brief Ustawia rotacje pocisku
	 *
	 * \param rotation - rotacja pocisku
	 */
	void setRotation(float rotation);
	/*!
	 *
	 * \brief Zwraca obiekt wyświetlającego się pocisku
	 * \return obiekt sprite'a pocisku
	 */
	sf::Sprite getSprite() const;
	/*!
	 * \brief Ustawia wektor prędkości pocisku
	 *
	 * \param velocity - wektor prędkości pocisku
	 */
	void setVelocity(sf::Vector2f velocity);
	/*!
	 * \brief Ustawia wektor prędkości pocisku
	 *
	 * \param x - składowa X wektora prędkości pocisku
	 * \param y - składowa Y wektora prędkości pocisku
	 */
	void setVelocity(float x, float y = 0);
	/*!
	 * \brief Zwraca wektor prędkości pocisku
	 *
	 * \return wektor prędkości pocisku
	 */
	sf::Vector2f getVelocity() const;
	/*!
	 *
	 * \brief Zwraca X pozycji pocisku na ekranie
	 * \return X pozycji pocisku na ekranie
	 */
	float getPosX() const;
	/*!
	 *
	 * \brief Zwraca Y pozycji pocisku na ekranie
	 * \return Y pozycji pocisku na ekranie
	 */
	float getPosY() const;
	/*!
	 *
	 * \brief Ustawia wartość X pozycji pocisku na ekranie
	 * \param x - współrzędna X pocisku na ekranie
	 */
	void setPosX(float x);
	/*!
	 *
	 * \brief Ustawia wartość Y pozycji pocisku na ekranie
	 * \param y - współrzędna Y pocisku na ekranie
	 */
	void setPosY(float y);
	/*!
	 *
	 *  \brief Aktualizuje obiekt co klatke
	 */
	void update();
	/*!
	 *
	 * \brief Zwraca wartość skali pocisku
	 * \return wartość skali pocisku
	 */
	float getScale() const;
	/*!
	 * \brief Ustawia wektor skali pocisku
	 *
	 * \param scale - wektor skali pocisku
	 */
	void setScaleVector(sf::Vector2f scale);
	/*!
	 * \brief Zwraca wektor skali pocisku
	 *
	 * \return wektor skali pocisku
	 */
	sf::Vector2f getScaleVector() const;

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
	 * \brief Obiekt rysowany na ekranie
	 *
	 */
	sf::Sprite sprite;
	/*!
	 * \brief Tekstura pocisku
	 *
	 */
	sf::Texture texture;
	/*!
	 * \brief Ścieżka do tekstury pocisku
	 *
	 */
	std::string texturePath = "resources/images/bullet.png";
	/*!
	 * \brief Skala pocisku
	 *
	 */
	float scale = 0.2f;
	/*!
	 * \brief Wektor skali pocisku
	 *
	 */
	sf::Vector2f scaleVector = { scale,scale };
	/*!
	 * \brief Rotacja pocisku
	 *
	 */
	float rotation = 0.0f;
	/*!
	 * \brief Pozycja X pocisku na ekranie
	 *
	 */
	float posX;
	/*!
	 * \brief Pozycja Y pocisku na ekranie
	 *
	 */
	float posY;
	/*!
	 * \brief Wektor prędkości pocisku
	 *
	 */
	sf::Vector2f velocity{ 100.0f,0.0f };
};
