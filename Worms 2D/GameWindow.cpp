#include "GameWindow.h"
#include "Bullet.h"

GameWindow::GameWindow(unsigned int width, unsigned int height, std::string name) : width(width), height(height),
                                                                                    windowName(name)
{
	if (this->window == nullptr)
	{
		this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
		this->window->setFramerateLimit(60);
		this->fpsCounter = new FPSCounter();
		this->gs = new GameSound();
		this->gs->PlayMainMusic();

		this->game_state = MENU;
		this->black_overlay.setFillColor(sf::Color(0, 0, 0, 64));
		this->black_overlay.setPosition(0, 0);
		this->black_overlay.setSize(sf::Vector2f(800, 600));
		this->menu.changeMenu(game_state);
		this->game_started = false;

		
	}
}

GameWindow::~GameWindow()
{
	delete[] worms;
	delete[] worms_b;
}

sf::RenderWindow* GameWindow::GetInstance() const
{
	return this->window;
}

void GameWindow::ChangeFrameLimit(unsigned int limit) const
{
	this->window->setFramerateLimit(limit);
}

void GameWindow::startGame()
{
	this->game_started = true;
	this->worm_count = 3;
	this->worm_count_b = worm_count;
	this->worms = new std::vector<Worm*>;
	this->worms_b = new std::vector<Worm*>;
	for (int j = 0; j < worm_count; j++)
	{
		Worm* newWormA = new Worm();
		newWormA->setTeam(team::RED);
		this->worms->push_back(newWormA);
		Worm* newWormB = new Worm();
		newWormB->setTeam(team::BLUE);
		this->worms_b->push_back(newWormB);
	}

	this->current_worm_id = 0;
	this->current_team = team::RED;
	this->current_worm = (worms->at(this->current_worm_id));
	for (int i = 0; i < worm_count; ++i)
	{
		worms->at(i)->setColMap(&(terrain.map));
		worms_b->at(i)->setColMap(&(terrain.map));
	}
}

void GameWindow::endGame()
{
	this->game_started = false;
	delete this->worms;
	delete this->worms_b;
	this->terrain.reset();
}



void GameWindow::MainLoop()
{

	//this->fpsCounter->start();
	water.update();

	if (this->game_started == false && this->game_state == GAME)
		this->startGame();
	else if (this->game_started == true && this->game_state == MENU)
		this->endGame();
	if (this->game_started == true)
	{
		if (this->worm_count <= 0)
		{
			this->endGame();
			this->game_state = BLUE_WIN;
			this->menu.changeMenu(game_state);
		}
		else if (this->worm_count_b <= 0)
		{
			this->endGame();
			this->game_state = RED_WIN;
			this->menu.changeMenu(game_state);
		}
	}
		

	this->window->clear(sf::Color(30, 40, 70));
	this->window->draw(water);
	
	if (game_started)
	{
		this->timer = this->clock.getElapsedTime();
		this->window->draw(terrain);
		for (int i = 0; i < worm_count; ++i)
		{
			if ((*current_worm).hasWeapon() && (*current_worm).getWeapon()->getIsShooting())
			{
				if (current_worm != worms->at(i))
					for (int j = 0; j < 8; j++)
					{
						if (pow(worms->at(i)->collisionPoints[j].x - (*current_worm).getWeapon()->getBullet()->getPosX(), 2)
							+ pow((*current_worm).getWeapon()->getBullet()->getPosY() - worms->at(i)->collisionPoints[j].y,
								2) <= pow((35 * (*current_worm).getWeapon()->getBullet()->getScale()) + 1, 2))
						{
							worms->at(i)->damage(current_worm->getWeapon()->getDamage());
							destroyTerrain();
							current_worm->getWeapon()->setIsShooting(false);
							current_worm->getWeapon()->setBullet(nullptr);
							std::cout << "Trafiono worma " << i << " w collider " << j << std::endl;


							break;
						}

					
					}
			}
			if (worms->size() != worm_count)
			{
				worm_count--;
				gs->PlayDeath();
				break;
			}

			this->window->draw(*worms->at(i));
			this->UpdateWorms(i);
			if (!worms->at(i)->isAlive())
			{
				std::vector<Worm*>::iterator it = std::find(worms->begin(), worms->end(), worms->at(i));
				worms->erase(it);
				i -= 1;
			}

		}

		//if(current_worm->hasWeapon() && current_worm->getWeapon()->getIsShooting())
		//{
		//	if(current_worm->getWeapon()->getBullet()->getPosX() > this->width-1 || current_worm->getWeapon()->getBullet()->getPosX() > this->width - 1  < 1 
		//		|| current_worm->getWeapon()->getBullet()->getPosY() > this->height - 1 || current_worm->getWeapon()->getBullet()->getPosY() < 0 )
		//	{
		//		//delete current_worm->getWeapon()->getBullet();
		//		current_worm->getWeapon()->setIsShooting(false);
		//		current_worm->getWeapon()->setBullet(nullptr);


		//	}
		//}

		for (int i = 0; i < worm_count_b; ++i)
		{
			if ((*current_worm).hasWeapon() && (*current_worm).getWeapon()->getIsShooting())
			{
				if (current_worm != worms_b->at(i))
					for (int j = 0; j < 8; j++)
					{
						if (pow(worms_b->at(i)->collisionPoints[j].x - (*current_worm).getWeapon()->getBullet()->getPosX(),
							2) + pow(
							(*current_worm).getWeapon()->getBullet()->getPosY() - worms_b->at(i)->collisionPoints[j].y,
								2)
							<= pow((35 * (*current_worm).getWeapon()->getBullet()->getScale()) + 1, 2))
						{
							worms_b->at(i)->damage(current_worm->getWeapon()->getDamage());
							destroyTerrain();
							current_worm->getWeapon()->setIsShooting(false);
							current_worm->getWeapon()->setBullet(nullptr);
							std::cout << "Trafiono worma " << i << " w collider " << j << std::endl;


							break;
						}
					}
			}
			if (worms_b->size() != worm_count_b)
			{
				worm_count_b--;
				gs->PlayDeath();
				break;
			}

			this->window->draw(*worms_b->at(i));

			this->UpdateWormsB(i);
			if (!worms_b->at(i)->isAlive())
			{
				std::vector<Worm*>::iterator it = std::find(worms_b->begin(), worms_b->end(),
					worms_b->at(i));
				worms_b->erase(it);
				i-=1;
			}

		}

		if (current_worm->hasWeapon() && current_worm->getWeapon()->getIsShooting())
		{
			if (current_worm->getWeapon()->getBullet()->getPosX() < -50 || current_worm->getWeapon()->getBullet()->getPosX() > 850 || current_worm->getWeapon()->getBullet()->getPosY() < -50 || current_worm->getWeapon()->getBullet()->getPosY() > 650)
			{
				current_worm->getWeapon()->setIsShooting(false);
				current_worm->getWeapon()->setBullet(nullptr);
			}
			else if (current_worm->checkCollision({ current_worm->getWeapon()->getBullet()->getPosX() ,current_worm->getWeapon()->getBullet()->getPosY() }))
			{
				destroyTerrain();
				current_worm->getWeapon()->setIsShooting(false);
				current_worm->getWeapon()->setBullet(nullptr);
			}
		}
		std::cout << "TIMER:" << this->timer.asSeconds() << std::endl;
		if(static_cast<int>(this->timer.asSeconds()) == 8)
		{
			if(*GetCurrentTeam() == team::RED)
			{
				this->SwitchToBlueTeam();
			}
			else
			{
				this->SwitchToRedTeam();
			}
			this->timer = this->clock.restart();
		}

		this->SetChooseStates();

		
			
	}
	//test
	if (game_state != GAME)
	{
		this->window->draw(black_overlay);
		this->window->draw(menu);
	}

	//this->fpsCounter->drawFPS();
	//this->window->draw((**(this->GetCurrentWorm())).getDebugTxt());
	this->window->display();
}


void GameWindow::UpdateWorms(int i)
{
	this->worms->at(i)->update();
}

void GameWindow::UpdateWormsB(int i)
{
	this->worms_b->at(i)->update();
}

Worm** GameWindow::GetCurrentWorm()
{
	return &(this->current_worm);
}

std::vector<Worm*>* GameWindow::GetWormsArray() const
{
	return this->worms;
}

std::vector<Worm*>* GameWindow::GetWormsArrayB() const
{
	return this->worms_b;
}

int GameWindow::GetWormCount() const
{
	return this->worm_count;
}

int GameWindow::GetWormCountB() const
{
	return this->worm_count_b;
}

int* GameWindow::GetCurrentTeam()
{
	return &(this->current_team);
}

int* GameWindow::GetCurrentWormID()
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

void GameWindow::SwitchTeam(team t)
{
	current_team = t;
	current_worm->stopMove();
	current_worm_id = (current_worm_id + 1) % worm_count;
	if (t == team::RED)
		current_worm = (worms->at(current_worm_id));
	else
		current_worm = (worms_b->at(current_worm_id));
}

void GameWindow::SwitchToRedTeam()
{
	if (worm_count)
	{
		SwitchTeam(team::RED);
	}
}

void GameWindow::SwitchToBlueTeam()
{
	if(worm_count_b)
	{
		SwitchTeam(team::BLUE);
	}
}

void GameWindow::SetChooseStates()
{
	for(int i =0; i < worms->size(); i++)
	{
		if (current_worm != worms->at(i))
			this->worms->at(i)->setNormal();
	}

	for (int j = 0; j < worms_b->size(); j++)
	{
		if (current_worm != worms_b->at(j))
			this->worms_b->at(j)->setNormal();
	}

	current_worm->setChoosen();
}

void GameWindow::destroyTerrain()
{
	sf::CircleShape circ(30);
	circ.setOrigin(30, 30);
	circ.setFillColor(sf::Color(0, 0, 0, 0));
	circ.setPosition(current_worm->getWeapon()->getBullet()->getPosX(), current_worm->getWeapon()->getBullet()->getPosY());
	gw->terrain.erase(circ);
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
