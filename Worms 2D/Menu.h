#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>
/*!
 * \brief Typ wyliczeniowy dla stanów gry
 *
 */
enum game_states { GAME, PAUSE, MENU, HELP, HELP_PAUSE, RED_WIN, BLUE_WIN, EXIT, KEYBOARD, GAMEPAD };
/*!
 * \brief Klasa g³ównego menu
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
	 * \brief Zwraca wskaŸnik na przycisk o podanych wspó³rzêdnych
	 *
	 * \param x - Wspó³rzêdna X przycisku
	 * \param y - Wspó³rzêdna Y przycisku
	 * \return  wskaŸnik na przycisk
	 */
	Button* getButton(float x, float y);
	/*!
	 * \brief Czyœci klikniêty przycisk
	 *
	 */
	void clearClickedButton();
	/*!
	 * \brief Czyœci menu
	 *
	 */
	void clear();
	/*!
	 * \brief Zmienia menu
	 *
	 * \param choice - wybór
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
	 * \brief Wektor przycisków menu
	 *
	 */
	std::vector <Button*> buttons;
	/*!
	 * \brief Obrazek sterowania klawiatur¹
	 *
	 */
	sf::Sprite keyboard_sprite;
	/*!
	 * \brief Tekstura do sterowania klawiatur¹
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
	 * \brief Obs³uguje i rysuje g³ówne menu
	 *
	 */
	void mainMenu();
	/*!
	 * \brief Wywo³uje menu pauzy
	 *
	 */
	void pauseMenu();
	/*!
	 * \brief Wywo³uje menu pomocy g³ównego menu
	 *
	 */
	void helpMainMenu();
	/*!
	 * \brief Wywo³uje menu pomocy
	 *
	 */
	void helpMenu();
	/*!
	 * \brief Zmienia karte na t¹ z klawiatur¹
	 *
	 */
	void changeDrawKeyboard();
	/*!
	 * \brief Zmienia karte na t¹ z kontrolerem
	 *
	 */
	void changeDrawGamepad();
	/*!
	 * \brief Wywo³uje menu z tekstem informuj¹cym o wygranej czerwonego team'u
	 *
	 */
	void redWinScreen();
	/*!
	 * \brief Wywo³uje menu z tekstem informuj¹cym o wygranej niebieskiego team'u
	 *
	 */
	void blueWinScreen();
};
