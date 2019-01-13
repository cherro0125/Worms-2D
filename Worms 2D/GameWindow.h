#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include<vector>
#include "FPSCounter.h"
#include "Worm.h"
#include "GameSound.h"
#include "Terrain.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Bazooka.h"
#include "Water.h"
#include "Menu.h"
class GameWindow
{
public:
	/*!
	 * \brief konstruktor usunięty
	 *
	 */
	GameWindow() = delete;
	/*!
	 *
	 * \brief Destruktor
	 */
	~GameWindow();
	/*!
	 *
	 * \brief Konstruktor tworzący okno główne
	 * \param width - szerokość okna
	 * \param height - wysokość okna
	 * \param name - nazwa okna
	 */
	GameWindow(unsigned int width, unsigned int height, std::string name);
	/*!
	 * \brief Zwraca wskaźnik na instacje okna głównego
	 *
	 * \return wskaźnik na instacje okna głównego
	 */
	sf::RenderWindow* GetInstance() const;
	/*!
	 * \brief Zwraca wskaźnik na instacje okna głównego lub tworzy je jeśli nie istniało
	 *
	 * \return wskaźnik na instacje okna głównego
	 */
	static GameWindow* GetGameWindowInstance(unsigned int width = 1280, unsigned int height = 1024, std::string name = "Worms 2D");
	/*!
	 * \brief Zmienia limit klatek
	 *
	 * \param limit - limit klatek
	 */
	void ChangeFrameLimit(unsigned int limit = 60) const;
	/*!
	 * \brief Przetwarza główną pętle okna co klatke
	 *
	 */
	void MainLoop();
	/*!
	 * \brief Aktualizuje odpowiedniego worma z wektora 1 drużyny
	 *
	 * \param i - numer worma w wektorze
	 */
	void UpdateWorms(int i);
	/*!
	 * \brief Aktualizuje odpowiedniego worma z wektora 2 drużyny
	 *
	 * \param i - numer worma w wektorze
	 */
	void UpdateWormsB(int i);
	/*!
	 * \brief Zwraca podwójny wskaźnik na aktualnego worma
	 *
	 * \return podwójny wskaźnik na aktualnego worma
	 */
	Worm **GetCurrentWorm();
	/*!
	 * \brief Zweraca wskaźnik na wektor 1 team'u
	 *
	 * \return wskaźnik na wektor 1 team'u
	 */
	std::vector<Worm*>* GetWormsArray() const;
	/*!
	 * \brief Zweraca wskaźnik na wektor 2 team'u
	 *
	 * \return wskaźnik na wektor 2 team'u
	 */
	std::vector<Worm*>* GetWormsArrayB() const;
	/*!
	 * \brief Zwraca wielkość 1 drużyny
	 *
	 * \return wielkość 1 drużyny
	 */
	int GetWormCount() const;
	/*!
	 * \brief Zwraca wielkość 2 drużyny
	 *
	 * \return wielkość 2 drużyny
	 */
	int GetWormCountB() const;
	/*!
	 * \brief Zwraca wskaźnik na ID aktualnego team'u
	 *
	 * \return wskaźnik na ID aktualnego team'u
	 */
	int *GetCurrentTeam();
	/*!
	 * \brief Zwraca wskaźnik na ID aktualnego worma
	 *
	 * \return wskaźnik na ID aktualnego worma
	 */
	int *GetCurrentWormID();
	/*!
	 * \brief Ustawia kolor tła
	 *
	 * \param color - kolor tła
	 */
	void SetBackgroundColor(sf::Color color);
	/*!
	 * \brief Zwraca wskaźnik na obiekt dźwięków gry
	 *
	 * \return wskaźnik na obiekt dźwięków gry
	 */
	GameSound* GetGameSound() const;
	/*!
	 * \brief Obiekt terenu
	 *
	 */
	Terrain terrain;
	/*!
	 * \brief Obiekt Menu
	 *
	 */
	Menu menu;
	/*!
	 * \brief Aktualny stan gry
	 *
	 */
	int game_state;
	/*!
	 * \brief Informacja czy gra została wystartowana
	 *
	 */
	bool game_started;
	/*!
	 * \brief Zmienia aktualny team na Czerwony (zmiana tury)
	 *
	 */
	void SwitchToRedTeam();
	/*!
	 * \brief Zmienia aktualny team na Niebieski (zmiana tury)
	 *
	 */
	void SwitchToBlueTeam();
	/*!
	 * \brief Ustawia stan aktualnego worma na wybrany a wszystkich innych na normalny
	 *
	 */
	void SetChooseStates();

private:
	/*!
	 * \brief Statyczny wskaźnik na obiekt okna (Singleton)
	 *
	 */
	static GameWindow *gw;
	/*!
	 * \brief Nazwa okna
	 *
	 */
	std::string windowName;
	/*!
	 * \brief Szerokość okna
	 *
	 */
	unsigned int width;
	/*!
	 * \brief Wysokośc okna
	 *
	 */
	unsigned int height;
	/*!
	 * \brief Statyczny wskaźnik na obiekt okna do wyświetlenia przez SFML
	 *
	 */
	static sf::RenderWindow* window;
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
	 * \brief ID Aktualnego worma
	 *
	 */
	int current_worm_id;
	/*!
	 * \brief ID Aktualnego team'u
	 *
	 */
	int current_team;
	/*!
	 * \brief Wskaźnik na aktualnie sterowanego worma
	 *
	 */
	Worm *current_worm;
	/*!
	 * \brief Wskaźnik na wektor 1 drużyny
	 *
	 */
	std::vector<Worm*>*worms = new std::vector<Worm*>;
	/*!
	 * \brief Wskaźnik na wektor 2 drużyny
	 *
	 */
	std::vector<Worm*>*worms_b = new std::vector<Worm*>;
	/*!
	 * \brief Kolor tła
	 *
	 */
	sf::Color bgColor;
	/*!
	 * \brief Licznik FPS'ów
	 *
	 */
	FPSCounter *fpsCounter;
	/*!
	 * \brief Statyczny wskaźnik na obiekt dźwięków gry
	 *
	 */
	static GameSound* gs;
	/*!
	 * \brief Wskaźnik na aktualną broń
	 *
	 */
	Weapon *weapon = new Bazooka(200, 20);
	/*!
	 * \brief Obiekt wody
	 *
	 */
	Water water;
	/*!
	 * \brief Obiekt potrzebny do niszczenia terenu
	 *
	 */
	sf::RectangleShape black_overlay;
	/*!
	 * \brief Startuje gre
	 *
	 */
	void startGame();
	/*!
	 * \brief Kończy gre
	 *
	 */
	void endGame();
	/*!
	 * \brief Timer
	 *
	 */
	sf::Time timer;
	/*!
	 * \brief Zegar
	 *
	 */
	sf::Clock clock;
	/*!
	 * \brief Zmiana team'u na wskazany w parametrze
	 *
	 * \param t
	 */
	void SwitchTeam(team t);
	/*!
	 * \brief Usuwa teren mapy
	 *
	 */
	void destroyTerrain();
};

