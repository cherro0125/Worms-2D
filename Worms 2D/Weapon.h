#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Bullet.h"



/**
 * \brief Klasa bazowa broni
 **/
class Weapon : public sf::Drawable
{
public:
	/**
	 * \brief Konstruktor domyślny broni który jest usunięty
	 **/
	Weapon() = delete;
	/*!
	 *
	 * \brief Konstruktor broni
	 * \param x - współrzędna x wyświetlenia miejsca broni
	 * \param y - współrzędna y wyświetlenia miejsca broni
	 */
	Weapon(float x, float y);
	/*!
	 * \brief Domyślny destruktor wirtualny broni
	 *
	 */
	virtual ~Weapon() = default;
	/*!
	 *
	 * \brief Metoda ustawiająca skale broni
	 * \param scale - skala broni
	 */
	void setScale(float scale);
	/*!
	 * \brief Metoda ustawiająca rotacje broni
	 *
	 * \param rotation - rotacja broni
	 */
	void setRotation(float rotation);
	/*!
	 *
	 * \brief Metoda zwracająca skale broni
	 * \return Zwraca skale broni
	 */
	float getScale() const;
	/*!
	 *
	 * \brief Metoda zwracająca rotacje broni
	 * \return Zwraca rotacje broni jako float
	 */
	float getRotation() const;
	/*!
	 *
	 * \brief Metoda zwracająca obiekt sprite'a broni
	 * \return  obiekt sf::Sprite broni
	 */
	sf::Sprite getSprite() const;
	/*!
	 *
	 *\brief Zwraca wspołrzędną X broni
	 * \return  współrzędną X broni
	 */
	float getPosX() const;
	/*!
	 *
	 *\brief Zwraca współrzędną Y broni
	 * \return  współrzędną Y broni
	 */
	float getPosY() const;
	/*!
	 *
	 * \brief Ustawia współrzędną X broni
	 * \param x - Współrzędna x dla broni
	 */
	void setPosX(float x);
	/*!
	 *
	 * \brief Ustawia współrzedną Y broni
	 * \param y - współrzedna y dla broni
	 */
	void setPosY(float y);
	/*!
	 *
	 * \brief Ustawia pocisk broni na wskazany w parametrze obiekt
	 * \param bullet - wskaźnik na obiekt pocisku
	 */
	void setBullet(Bullet *bullet);
	/*!
	 *
	 * \brief Ustawia wektor skali broni
	 * \param scale - wektor skali
	 */
	void setScaleVector(sf::Vector2f scale);
	/*!
	 *
	 *\brief Zwraca wektor skali broni
	 * \return Wektor skali broni
	 */
	sf::Vector2f getScaleVector() const;
	/*!
	 *
	 *\brief Zwraca wskaźnik na obiekt pocisku danej broni
	 * \return Wskaźnik obiekt pocisku danej broni
	 */
	Bullet* getBullet();
	/*!
	 * \brief Metoda aktualizująca obiekt broni co klatke
	 *
	 */
	void update();
	/*!
	 * \brief Wirtualna metoda sprawiająca, że broń wystrzeli
	 *
	 * \param angle - kąt pod jakim wystrzelony zostanie pocisk
	 */
	virtual void shoot(float angle);
	/*!
	 *
	 *\brief Zwraca wartość informującą o tym czy broń aktualnie strzela
	 * \return  wartość informującą o tym czy broń aktualnie strzela
	 */
	bool getIsShooting() const;
	/*!
	 *
	 * \brief Ustawia stan strzelania broni na podany w parametrze
	 * \param isShooting - czy broń strzela (true - tak, false - nie )
	 */
	void setIsShooting(bool isShooting);
	/*!
	 * \brief Odtwarza dźwięk wystrzału broni
	 *
	 */
	virtual void playShootSound();
	/*!
	 *
	 * \brief Ustawia obrażenia od danej broni
	 * \param damage - obrażenia broni
	 */
	void setDamage(float damage);
	/*!
	 * \brief Zwraca obrażenia danej broni
	 *
	 * \return obrażenia broni
	 */
	float getDamage() const;

protected:
	/*!
	 * \brief Rysuje obiekt na ekranie (dzidziczona z SFML)
	 *
	 * \param target
	 * \param states
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	/*!
	 * \brief Obiekt rysowany na ekranie
	 *
	 */
	sf::Sprite sprite;
	/*!
	 * \brief Tekstura obiektu
	 *
	 */
	sf::Texture texture;
	/*!
	 * \brief Ścieżka do tekstury obiektu
	 *
	 */
	std::string texturePath;
	/*!
	 * /brief Wskaźnik na pocisk
	 *
	 */
	Bullet *bullet = nullptr;
	/*!
	 * \brief Wartość rotacji broni
	 *
	 */
	float rotation = 0.0f;
	/*!
	 * \brief Wartość skali broni
	 *
	 */
	float scale = 0.2f;
	/*!
	 * \brief Pozycja X broni na ekranie
	 *
	 */
	float posX;
	/*!
	 * \brief Pozycja Y broni na ekranie
	 *
	 */
	float posY;
	/*!
	 * \brief Wektor skali broni
	 *
	 */
	sf::Vector2f scaleVector = { scale,scale };
	/*!
	 * \brief Przechowuje informacje o tym czy broń strzela
	 *
	 */
	bool isShooting = false;
	/*!
	 * \brief Obrażenia broni
	 *
	 */
	float damage = 0.0f;

};