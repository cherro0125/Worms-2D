#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::Drawable
{
public:
	/*!
	 * \brief konstruktor przycisku
	 *
	 * \param position_x - pozycja X przycisku na ekranie
	 * \param position_y - pozycja Y przycisku na ekranie
	 * \param label - tekst na przycisku
	 * \param id - id przycisku
	 */
	Button(float position_x, float position_y, const char * label, int id);
	/*!
	 * \brief Zwraca rozmiar buttona
	 *
	 * \return wektor rozmiaru buttona
	 */
	sf::Vector2f getSize();
	/*!
	 * \brief Zwraca wektor pozycji buttona
	 *
	 * \return wektor pozycji buttona
	 */
	sf::Vector2f getPosition();
	/*!
	 * \brief Podswietla przycisk
	 *
	 */
	void hover();
	/*!
	 * \brief Obs³uguje wciœniêcie przycisku
	 *
	 */
	void click();
	/*!
	 * \brief Czyœci przycisk
	 *
	 */
	void clear();
	/*!
	 * \brief Sprawdza czy myszka jest na przycisku
	 *
	 * \return czy myszka jest na przycisku
	 */
	bool isHovered();
	/*!
	 * \brief Sprawdza czy przycisk zosta³ kliniety
	 *
	 * \return czy przycisk zosta³ kliniety
	 */
	bool isClicked();
	/*!
	 * \brief Ustawia kolor domyœlny przycisku
	 *
	 */
	void setColorDefault();
	/*!
	 * \brief Ustawia kolor podœwietlenia przycisku
	 *
	 */
	void setColorHovered();
	/*!
	 * \brief Ustawia kolor klikniêtego przycisku
	 *
	 */
	void setColorClicked();
	/*!
	 * \brief Zwraca ID przycisku
	 *
	 * \return ID przycisku
	 */
	int getId();
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
	 * \brief Tekst przycisku
	 *
	 */
	sf::Text txt;
	/*!
	 * \brief Obiekt rysowany na ekranie
	 *
	 */
	sf::RectangleShape shape;
	/*!
	 * \brief Rozmiar przycisku
	 *
	 */
	sf::Vector2f size;
	/*!
	 * \brief Zmienna przechowuj¹ca informacje o tym czy coœ naje¿d¿a na przycisk
	 *
	 */
	bool hovered;
	/*!
	 * \brief Zmienna przechowuj¹ca informacje o tym czy przycisk zosta³ wciœniêty
	 *
	 */
	bool clicked;
	/*!
	 * \brief Podstawowy kolor
	 *
	 */
	sf::Color color_default;
	/*!
	 * \brief Kolor podœwietlenia
	 *
	 */
	sf::Color color_hovered;
	/*!
	 * \brief Kolor klikniêcia
	 *
	 */
	sf::Color color_clicked;
	/*!
	 * \brief ID przycisku
	 *
	 */
	int id;
};
