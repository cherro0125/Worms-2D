#pragma once
#include <SFML/Graphics.hpp>
class FPSCounter
{
public:
	/*!
	 * Konstruktor licznika FPS'ów (dla DEBBUGE'a)
	 *
	 * \param fontSize - rozmiar czcionki
	 */
	FPSCounter(unsigned int fontSize = 12);
	/*!
	 * \brief Uruchamia licznik
	 *
	 */
	void start();
	/*!
	 * \brief Rysuje ilość FPS na ekranie
	 *
	 */
	void drawFPS();
	/*!
	 * \brief Ustawia kolor licznika
	 *
	 * \param color - kolor licznika
	 */
	void setColor(sf::Color color);


private:
	/*!
	 * \brief Wskaźnik na okno
	 *
	 */
	sf::RenderWindow* window;
	/*!
	 * \brief Czcionka
	 *
	 */
	sf::Font font;
	/*!
	 * \brief Przechowywany tekst o ilośći FPS'ów
	 *
	 */
	sf::Text txt;
	/*!
	 * \brief Zegar do obliczania
	 *
	 */
	sf::Clock clock;
	/*!
	 * \brief Obiekt czasu
	 *
	 */
	sf::Time time = sf::Time::Zero;
	/*!
	 * \brief kolor licznika
	 *
	 */
	sf::Color fpsColor = sf::Color::Green;
	/*!
	 * \brief Ścieżka do czcionki
	 *
	 */
	std::string fontPath = "resources/fonts/sansation.ttf";
	/*!
	 * \brief Rozmiar czcionki
	 *
	 */
	unsigned int fontSize;
	/*!
	 * \brief Ilość FPS przed konwersją
	 *
	 */
	float fps_f;
	/*!
	 * \brief Ilość FPS po konwersji
	 *
	 */
	int fps_i;
	/*!
	 * \brief Zatrzymuje odliczanie czasu i aktualizuje licznik FPS
	 *
	 */
	void stop();

};
