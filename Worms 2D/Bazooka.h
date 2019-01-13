#pragma once
#include "Weapon.h"

class Bazooka : public Weapon
{
public:
	/*!
	 * \brief Konstruktor domyślny który jest usunięty
	 *
	 */
	Bazooka() = delete;
	/*!
	 *
	 * \brief Konstruktor broni
	 * \param x - współrzędna x wyświetlenia miejsca broni
	 * \param y - współrzędna y wyświetlenia miejsca broni
	 */
	Bazooka(float x, float y);
	/*!
	 *\brief Domyślny destruktor
	 *
	 */
	virtual ~Bazooka() = default;
	/*!
	 * \brief Przeciążona funkcja odtwarzająca odgłos wystrzału z broni
	 *
	 */
	void playShootSound() override;
private:
	/*!
	 * \brief Ścieżka do tekstury bazooki
	 *
	 */
	std::string bazookaTexturePath = "resources/images/bazooka.png";
	/*!
	 * \brief Obrażenia bazooki
	 *
	 */
	float bazookaDamage = 20;


};
