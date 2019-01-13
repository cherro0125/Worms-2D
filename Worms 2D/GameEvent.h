#pragma once
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include<vector>
/*!
 * \brief Klasa zdarzeń gry
 *
 */
class GameEvent
{
public:
	/*!
	 * \brief Konstruktor zdarzeń
	 *
	 */
	GameEvent();
	/*!
	 * \brief Destruktor zdarzeń
	 *
	 */
	virtual ~GameEvent();
	/*!
	 * \brief Zwraca instancje zdarzeń SFML'a
	 *
	 * \return instancje zdarzeń SFML'a
	 */
	sf::Event GetInstance();
	/*!
	 * \brief Obsługuje zdarzenia co klatke
	 *
	 */
	void handleEvents();
	/*!
	 * \brief Zwraca statyczny wskaźnik na obiekt Zdarzeń gry (Singleton)
	 *
	 * \return wskaźnik na obiekt Zdarzeń gry
	 */
	static GameEvent* GetEventInstance();




private:
	/*!
	 * \brief Statyczny wskaźnik na obiekt zdarzeń gry
	 *
	 */
	static GameEvent *ev;
	/*!
	 * \brief Wskaźnik na okno gry
	 *
	 */
	GameWindow *gWindow;
	/*!
	 * \brief Obiekt eventu z SFML
	 *
	 */
	sf::Event event{};
	/*!
	 * \brief wskaźnik na obiekt okna z SFML'a
	 *
	 */
	sf::RenderWindow* window;
	/*!
	 * \brief podwójny wskaźnik na aktualnego worma
	 *
	 */
	Worm **current_worm;
	/*!
	 * \brief Wskaźnik na wektor 1 drużyny
	 *
	 */
	std::vector<Worm*> *worms = new std::vector<Worm*>;
	/*!
	 * \brief Wskaźnik na wektor 2 drużyny
	 *
	 */
	std::vector<Worm*> *worms_b = new std::vector<Worm*>;
	/*!
	 * \brief Ilość wormów w 1 drużynie
	 *
	 */
	int worm_count;
	/*!
	 * \brief Ilość wormów w 2 drużynie
	 *
	 */
	int worm_count_b;
	/*!
	 * \brief Wskaźnik na ID Aktualnego worma
	 *
	 */
	int *current_worm_id;
	/*!
	 * \brief Wskaźnik na ID Aktualnego team'u
	 *
	 */
	int *current_team;



};
