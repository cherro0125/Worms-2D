#pragma once
#include "Weapon.h"
/*!
 * \brief Klasa rewolwera
 *
 */
class Revolver : public Weapon
{
public:
	/*!
	 * \brief Konstruktor domyślny który jest usunięty
	 *
	 */
	Revolver() = delete;
	/*!
	 *
	 * \brief Konstruktor broni
	 * \param x - współrzędna x wyświetlenia miejsca broni
	 * \param y - współrzędna y wyświetlenia miejsca broni
	 */
	Revolver(float x, float y);
	/*!
	 *\brief Domyślny destruktor
	 *
	 */
	virtual ~Revolver() = default;
	/*!
	 * \brief Przeciążona funkcja odtwarzająca odgłos wystrzału z broni
	 *
	 */
	void playShootSound() override;
private:
	/*!
	 * \brief Ścieżka do tekstury rewolweru
	 *
	 */
	std::string revolverTexturePath = "resources/images/gun.png";
	/*!
	 * \brief Obrażenia rewolweru
	 *
	 */
	float revorverDamage = 5.0f;
};
