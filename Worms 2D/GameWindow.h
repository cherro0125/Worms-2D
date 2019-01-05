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
class GameWindow
{
public:
	GameWindow() = delete;
	~GameWindow();
	GameWindow(unsigned int width, unsigned int height, std::string name);
	sf::RenderWindow* GetInstance() const;
	static GameWindow* GetGameWindowInstance(unsigned int width = 1280, unsigned int height = 1024, std::string name = "Worms 2D");
	void ChangeFrameLimit(unsigned int limit = 60) const;
	void MainLoop();
	void UpdateWorms(int i);
	void UpdateWormsB(int i);
	Worm **GetCurrentWorm();
	std::vector<Worm*>* GetWormsArray() const;
	std::vector<Worm*>* GetWormsArrayB() const;
	int GetWormCount() const;
	int GetWormCountB() const;
	int *GetCurrentTeam();
	int *GetCurrentWormID();
	void SetBackgroundColor(sf::Color color);
	GameSound* GetGameSound() const;
	Terrain terrain;

private:
	static GameWindow *gw;
	std::string windowName;
	unsigned int width;
	unsigned int height;
	static sf::RenderWindow* window;
	int worm_count;
	int worm_count_b;
	int current_worm_id;
	int current_team;
	Worm *current_worm;
	std::vector<Worm*>*worms = new std::vector<Worm*>;
	std::vector<Worm*>*worms_b = new std::vector<Worm*>;
	sf::Color bgColor;
	FPSCounter *fpsCounter;
	static GameSound* gs;
	Weapon *weapon = new Bazooka(200,20);
	Water water;
	
};

