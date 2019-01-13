#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon.h"

//enum collision{UP,DOWN,LEFT,RIGHT};
/*!
 * \brief Typ wyliczeniowy dla kolizji
 *
 */
enum collision { UP, UP_LEFT, UP_RIGHT, DOWN, DOWN_LEFT, DOWN_RIGHT, LEFT, RIGHT };
/*!
 * \brief Typ wyliczeniowy dla drużyny
 *
 */
enum team { RED, BLUE };
/*!
 * \brief Klasa worma (gracza)
 *
 */
class Worm : public sf::Drawable
{
public:
	/*!
	 * \brief Konstruktor domyślny
	 *
	 */
	Worm();
	/*!
	 * \brief Destruktor
	 *
	 */
	virtual ~Worm();
	/*!
	 * \brief Aktualizuje obiekt worma co klatke
	 *
	 */
	void update();
	/*!
	 * \brief Zwraca lewą pozycje obiektu worma
	 *
	 * \return lewą pozycje obiektu worma
	 */
	float left() const;
	/*!
	 * \brief Zwraca prawą pozycje obiektu worma
	 *
	 * \return prawą pozycje obiektu worma
	 */
	float right() const;
	/*!
	 * \brief Zwraca górną pozycje obiektu worma
	 *
	 * \return górną pozycje obiektu worma
	 */
	float top() const;
	/*!
	 * \brief Zwraca dolna pozycje obiektu worma
	 *
	 * \return dolna pozycje obiektu worma
	 */
	float bottom() const;
	/*!
	 * \brief Zwraca współrzędną X pozycji worma na ekranie
	 *
	 * \return współrzędną X pozycji worma na ekranie
	 */
	float getWormX() const;
	/*!
	 * \brief Zwraca współrzędną Y pozycji worma na ekranie
	 *
	 * \return współrzędną Y pozycji worma na ekranie
	 */
	float getWormY() const;
	/*!
	 * \brief Zatrzymuje worma
	 *
	 */
	void stopMove();
	/*!
	 * \brief Porusza worma w lewo
	 *
	 */
	void moveLeft();
	/*!
	 * \brief Porusza worma w prawo
	 *
	 */
	void moveRight();
	/*!
	 * \brief Sprawia, że worm skacze
	 *
	 */
	void jump();
	/*!
	 * \brief Zadaje obrażenia podane w parametrze wormowi
	 *
	 * \param dmg - obrażenia dla worma
	 */
	void damage(float dmg);
	/*!
	 * \brief Sprawdza czy worm jeszcze żyje
	 *
	 * \return true - jeśli worm żyje lub false - jeśli nie żyje
	 */
	bool isAlive();
	/*!
	 * \brief Sprawdza kolizje worma z danym punktem
	 *
	 * \param point - punkt do sprawdznia kolizji
	 * \return  true - jeśli kolizja nastąpi lub false - jeśli nie nastąpi
	 */
	bool checkCollision(sf::Vector2f point);
	/*!
	 * \brief Zwraca offset w płaszczyźnie Y względem punktu
	 *
	 * \param point
	 * \return offset w płaszczyźnie Y
	 */
	int getOffsetY(sf::Vector2f point);
	/*!
	 * \brief Zwraca skale worma
	 *
	 * \return skale worma
	 */
	float getScale() const;
	/*!
	 * \brief Zwraca obiekt rysowanego worma
	 *
	 * \return
	 */
	sf::Sprite getSprite() const;
	/*!
	 * \brief Tablica wektorów punktów kolizji worma
	 *
	 */
	sf::Vector2f collisionPoints[8];
	/*!
	 * \brief Ustawia wormowi daną broń na tą do której podamy wskaźnik
	 *
	 * \param weapon - wskaźnik na broń dla worma
	 */
	void setWeapon(Weapon* weapon);
	/*!
	 * \brief Zwraca wskaźnik na obiekt aktualnie trzymanej broni przez worma
	 *
	 * \return wskaźnik na obiekt broni lub nullptr gdy worm nie trzyma żadnej broni
	 */
	Weapon* getWeapon() const;
	/*!
	 * \brief Usuwa broń którą trzyma worm
	 *
	 */
	void deleteWeapon();
	/*!
	 * \brief Ustawia kolizje mapy
	 *
	 * \param image - obraz mapy
	 */
	void setColMap(sf::Image *image);
	/*!
	 * \brief Zwraca tekst dla debbuge'a
	 *
	 * \return tekst dla debbuge'a
	 */
	sf::Text getDebugTxt();
	/*!
	 * \brief Sprawdza czy worm patrzy w lewo
	 *
	 * \return true - jeśli parzy w lewo lub false - jeśli parzy w prawo
	 */
	bool isLookingOnLeft() const;
	/*!
	 * \brief Sprawdza czy worm ma broń
	 *
	 * \return true - jeśli worm ma broń lub false - jeśli jej nie ma
	 */
	bool hasWeapon() const;
	/*!
	 * \brief Ustawia team dla danego worma
	 *
	 * \param t - team dla worma
	 */
	void setTeam(team t);
	/*!
	 * \brief Sprawia, że worm patrzy w lewo
	 *
	 */
	void lookLeft();
	/*!
	 * \brief Sprawia, że worm patrzy w prawo
	 *
	 */
	void lookRight();
	/*!
	 * \brief Ustawia worma jako wybranego aktualnie do sterowania
	 *
	 */
	void setChoosen();
	/*!
	 * \brief Ustawia worma jako normalnego (nie sterujemy nim)
	 *
	 */
	void setNormal();

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
	 * \brief Punkty życia worma
	 *
	 */
	float hp;
	/*!
	 * \brief Pasek życia
	 *
	 */
	sf::RectangleShape hpShape;
	/*!
	 * \brief Informacja o tym czy worm skacze
	 *
	 */
	bool isJumping = false;
	/*!
	 * \brief Obiekt worma rysowany na ekranie
	 *
	 */
	sf::Sprite sprite;
	/*!
	 * \brief Podstawowa tekstura worma
	 *
	 */
	sf::Texture texture;
	/*!
	 * \brief Drugi wariant tekstury worma
	 *
	 */
	sf::Texture texture2;
	/*!
	 * \brief Trzeci wariant tekstury worma
	 *
	 */
	sf::Texture texture3;
	/*!
	 * Obiekt przechowujący informacje o czcionce
	 *
	 */
	sf::Font font;
	/*!
	 * \brief Ścieżka do czcionki
	 *
	 */
	std::string fontPath = "resources/fonts/sansation.ttf";
	/*!
	 * \Brief Ścieżka do tekstury worma
	 *
	 */
	std::string textureImagePath = "resources/images/janusz.png";
	/*!
	 * \Brief Ścieżka do tekstury worma
	 *
	 */
	std::string textureImagePath2 = "resources/images/janusz_zdziwiony.png";
	/*!
	 * \Brief Ścieżka do tekstury worma
	 *
	 */
	std::string textureImagePath3 = "resources/images/janusz_aiming.png";
	/*!
	 * \brief Tekst do debbugowania
	 *
	 */
	sf::Text debugTxt;
	/*!
	 * \brief Prędkość worma
	 *
	 */
	const float wormVelocity{ 0.0f };
	const float baseVelocity{ 1.0f };
	/*!
	 * \brief Bazowa prędkość worma
	 *
	 */
	 /*!
	  * \brief Wektor prędkości worma
	  *
	  */
	sf::Vector2f velocity{ wormVelocity,wormVelocity };
	/*!
	 * \brief Mapa
	 *
	 */
	sf::Image *colMap;
	/*!
	 * \brief Skala worma
	 *
	 */
	float wormScale = 0.2f;
	/*!
	 * \brief Pozycja X worma na mapie
	 *
	 */
	float posX;
	/*!
	 * \brief Pozycja Y worma na mapie
	 *
	 */
	float posY;
	/*!
	 * \brief Wysokość okna
	 *
	 */
	float windowHeight;
	/*!
	 * \brief Szerokość okna
	 *
	 */
	float windowWidth;
	/*!
	 * \brief Przechowuje informacje o tym czy worm aktualnie się porusza
	 *
	 */
	bool isMoving;
	/*!
	 * \brief Przechowuje informacje o tym czy worm aktualnie patrzy się w lewo
	 *
	 */
	bool lookingLeft = false;
	/*!
	 * \brief Aktualna broń worma
	 *
	 */
	Weapon *weapon = nullptr;


};
