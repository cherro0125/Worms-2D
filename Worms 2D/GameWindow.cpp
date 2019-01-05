#include "GameWindow.h"
#include "Bullet.h"

GameWindow::GameWindow(unsigned int width, unsigned int height, std::string name) : width(width), height(height), windowName(name)
{
	if(this->window == nullptr)
	{
		this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
		this->window->setFramerateLimit(60);
		this->fpsCounter = new FPSCounter();
		this->gs = new GameSound();
		this->gs->PlayMainMusic();
		
		this->worm_count = 3;
		this->worms = new std::vector<Worm*>;
		for(int j = 0; j< worm_count;j++)
		{
			this->worms->push_back(new Worm());
		}
		this->current_worm_id = 0;
		this->current_worm = (worms->at(this->current_worm_id));
		for (int i = 0; i < worm_count; ++i)
		{
			worms->at(i)->setColMap(&(terrain.map));
		}
		
		
	}

}

GameWindow::~GameWindow()
{
	delete[] worms;
}

sf::RenderWindow* GameWindow::GetInstance() const
{
	return this->window;
}

void GameWindow::ChangeFrameLimit(unsigned int limit) const
{
	this->window->setFramerateLimit(limit);
}

void GameWindow::MainLoop()
{
	sf::RectangleShape cpoints[8];
	for (int i = 0; i < 8; ++i)
	{
		cpoints[i].setSize(sf::Vector2f(2.f, 2.f));
	}
	cpoints[0].setPosition(current_worm->collisionPoints[UP]);
	cpoints[1].setPosition(current_worm->collisionPoints[UP_LEFT]);
	cpoints[2].setPosition(current_worm->collisionPoints[UP_RIGHT]);
	cpoints[3].setPosition(current_worm->collisionPoints[DOWN]);
	cpoints[4].setPosition(current_worm->collisionPoints[DOWN_LEFT]);
	cpoints[5].setPosition(current_worm->collisionPoints[DOWN_RIGHT]);
	cpoints[6].setPosition(current_worm->collisionPoints[LEFT]);
	cpoints[7].setPosition(current_worm->collisionPoints[RIGHT]);

	sf::RectangleShape bulletorigin(sf::Vector2f(2.f, 2.f));

	this->fpsCounter->start();
	
	this->window->clear(sf::Color(71,71,71));
	this->window->draw(terrain);
	for (int i = 0; i < worm_count; ++i)
	{
		if((*current_worm).hasWeapon() && (*current_worm).getWeapon()->getIsShooting())
		{
			bulletorigin.setPosition((*current_worm).getWeapon()->getBullet()->getPosX(), (*current_worm).getWeapon()->getBullet()->getPosY());
			if(current_worm_id!=i)
			for(int j = 0; j<8;j++)
			{
				
				if(pow(worms->at(i)->collisionPoints[j].x - (*current_worm).getWeapon()->getBullet()->getPosX(),2) + pow((*current_worm).getWeapon()->getBullet()->getPosY() - worms->at(i)->collisionPoints[j].y,2) <= pow((35* (*current_worm).getWeapon()->getBullet()->getScale()) + 1,2))	
				{
					worms->at(i)->damage(20);
					current_worm->getWeapon()->setIsShooting(false);
					current_worm->getWeapon()->setBullet(nullptr);
					std::cout << "Trafiono worma " << i << " w collider " << j << std::endl;
					if (!worms->at(i)->isAlive())
					{
						std::vector<Worm*>::iterator it = std::find(worms->begin(), worms->end(), worms->at(i));
						worms->erase(it);
						
					}
						
					break;
				}
				
			}
		}
		if(worms->size() != worm_count)
		{
			worm_count--;
			gs->PlayDeath();
			break;
		}
		this->window->draw(*worms->at(i));
		this->UpdateWorms(i);
		
	}
	for (int i = 0; i < 8; ++i)
	{
		if((*current_worm).isAlive())
			this->window->draw(cpoints[i]);
	}
	//test
	this->window->draw(bulletorigin);
	this->window->draw(bullet);
	bullet.update();

	

	
	this->fpsCounter->drawFPS();
	this->window->draw((**(this->GetCurrentWorm())).getDebugTxt());
	this->window->display();



}


void GameWindow::UpdateWorms(int i)
{

	this->worms->at(i)->update();
	

	

}

Worm **GameWindow::GetCurrentWorm()
{
	return &(this->current_worm);
}

std::vector<Worm*>* GameWindow::GetWormsArray() const
{
	return this->worms;
}

int GameWindow::GetWormCount()
{
	return this->worm_count;
}

int *GameWindow::GetCurrentWormID()
{
	return &(this->current_worm_id);
}

void GameWindow::SetBackgroundColor(sf::Color color)
{
	this->bgColor = color;
}

GameSound* GameWindow::GetGameSound() const
{
	return this->gs;
}

//Static variables and methods

GameWindow* GameWindow::gw = nullptr;
sf::RenderWindow* GameWindow::window = nullptr;
GameSound* GameWindow::gs = nullptr;


GameWindow* GameWindow::GetGameWindowInstance(unsigned int width, unsigned int height, std::string name)
{
	if (gw == nullptr) 
		gw = new GameWindow(width, height, name);
	return gw;
}