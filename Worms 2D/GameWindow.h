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
	Worm **GetCurrentWorm();
	std::vector<Worm*>* GetWormsArray() const;
	int GetWormCount();
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
	int current_worm_id;
	Worm *current_worm;
	std::vector<Worm*>*worms = new std::vector<Worm*>;
	sf::Color bgColor;
	FPSCounter *fpsCounter;
	static GameSound* gs;
	//test
	Bullet bullet{ 20, 50 };
	Weapon *weapon = new Bazooka(200,20);
	
	
};

