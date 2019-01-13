#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>
/*!
 * \brief Typ wyliczeniowy dla stan�w gry
 *
 */
enum game_states { GAME, PAUSE, MENU, HELP, HELP_PAUSE, RED_WIN, BLUE_WIN, EXIT, KEYBOARD, GAMEPAD };
/*!
 * \brief Klasa g��wnego menu
 *
 */
class Menu : public sf::Drawable
{
public:
	/*!
	 * \brief Konstruktor menu
	 *
	 */
	Menu();
	/*!
	 * \brief Zwraca wska�nik na przycisk o podanych wsp�rz�dnych
	 *
	 * \param x - Wsp�rz�dna X przycisku
	 * \param y - Wsp�rz�dna Y przycisku
	 * \return  wska�nik na przycisk
	 */
	Button* getButton(float x, float y);
	/*!
	 * \brief Czy�ci klikni�ty przycisk
	 *
	 */
	void clearClickedButton();
	/*!
	 * \brief Czy�ci menu
	 *
	 */
	void clear();
	/*!
	 * \brief Zmienia menu
	 *
	 * \param choice - wyb�r
	 */
	void changeMenu(int choice);


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
	 * \brief Czcionka
	 *
	 */
	sf::Font font;
	/*!
	 * \brief Tekst menu
	 *
	 */
	sf::Text txt;
	/*!
	 * \brief Wektor przycisk�w menu
	 *
	 */
	std::vector <Button*> buttons;
	/*!
	 * \brief Obrazek sterowania klawiatur�
	 *
	 */
	sf::Sprite keyboard_sprite;
	/*!
	 * \brief Tekstura do sterowania klawiatur�
	 *
	 */
	sf::Texture keyboard_texture;
	/*!
	 * \brief Obrazek sterowania gamepadem
	 *
	 */
	sf::Sprite gamepad_sprite;
	/*!
	 * \brief Tekstura do sterowania gamepadem
	 *
	 */
	sf::Texture gamepad_texture;
	/*!
	 * \brief Czy rysowany jest keyboard
	 *
	 */
	bool draw_keyboard;
	/*!
	 * \brief Czy rysowany jest gamepade
	 *
	 */
	bool draw_gamepad;
	/*!
	 * \brief Obs�uguje i rysuje g��wne menu
	 *
	 */
	void mainMenu();
	/*!
	 * \brief Wywo�uje menu pauzy
	 *
	 */
	void pauseMenu();
	/*!
	 * \brief Wywo�uje menu pomocy g��wnego menu
	 *
	 */
	void helpMainMenu();
	/*!
	 * \brief Wywo�uje menu pomocy
	 *
	 */
	void helpMenu();
	/*!
	 * \brief Zmienia karte na t� z klawiatur�
	 *
	 */
	void changeDrawKeyboard();
	/*!
	 * \brief Zmienia karte na t� z kontrolerem
	 *
	 */
	void changeDrawGamepad();
	/*!
	 * \brief Wywo�uje menu z tekstem informuj�cym o wygranej czerwonego team'u
	 *
	 */
	void redWinScreen();
	/*!
	 * \brief Wywo�uje menu z tekstem informuj�cym o wygranej niebieskiego team'u
	 *
	 */
	void blueWinScreen();
};
