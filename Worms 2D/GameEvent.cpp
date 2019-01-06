#include "GameEvent.h"
#include <iostream>
#include "Revolver.h"


GameEvent::GameEvent()
{
	this->gWindow = GameWindow::GetGameWindowInstance();
	this->window = gWindow->GetInstance();
	current_worm = this->gWindow->GetCurrentWorm();
	worms = this->gWindow->GetWormsArray();
	worms_b = this->gWindow->GetWormsArrayB();
	worm_count = this->gWindow->GetWormCount();
	current_worm_id = this->gWindow->GetCurrentWormID();
	worm_count_b = this->gWindow->GetWormCountB();
	current_team = this->gWindow->GetCurrentTeam();
}

GameEvent::~GameEvent()
{
}

sf::Event GameEvent::GetInstance()
{
	return this->event;
}

void GameEvent::handleEvents()
{
	

	while (this->window->pollEvent(this->event))
	{
		worms = gWindow->GetWormsArray();
		worms_b = gWindow->GetWormsArrayB();
		worm_count = gWindow->GetWormCount();
		worm_count_b = gWindow->GetWormCountB();
		current_team = gWindow->GetCurrentTeam();
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		if(sf::Joystick::isConnected(0))
		{
			if(sf::Joystick::isButtonPressed(0,0))
			{
				(*current_worm)->jump();
			}

			if(sf::Joystick::isButtonPressed(0,4))
			{
				worm_count = gWindow->GetWormCount();
				*current_worm_id = (*current_worm_id + 1) % worm_count;
				(*current_worm)->stopMove();
				*current_worm = worms->at(*current_worm_id);
			}
			
		}
		if (this->event.type == sf::Event::KeyPressed)
		{
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			if (this->event.key.code == sf::Keyboard::Tab)
			{
				(*current_worm)->stopMove();
				if (*current_team == team::RED)
				{
					if (worm_count)
					{
						*current_worm_id = (*current_worm_id + 1) % worm_count;
						*current_worm = (worms->at(*current_worm_id));
					}
				}
				else
				{
					if (worm_count_b)
					{
						*current_worm_id = (*current_worm_id + 1) % worm_count_b;
						*current_worm = (worms_b->at(*current_worm_id));
					}
				}
					
			}
			if(this->event.key.code == sf::Keyboard::A)
			{
				if (worm_count)
				{
					*current_team = team::RED;
					(*current_worm)->stopMove();
					*current_worm_id = (*current_worm_id + 1) % worm_count;
					*current_worm = (worms->at(*current_worm_id));
				}
			}
			if(this->event.key.code == sf::Keyboard::S)
			{
				if (worm_count_b)
				{
					*current_team = team::BLUE;
					(*current_worm)->stopMove();
					*current_worm_id = (*current_worm_id + 1) % worm_count_b;
					*current_worm = (worms_b->at(*current_worm_id));
				}
			}
			if (this->event.key.code == sf::Keyboard::Space)
			{
				(*current_worm)->jump();
			}
			//Test
			if(this->event.key.code == sf::Keyboard::O)
			{
				(*current_worm)->damage(1);
			}

			if(this->event.key.code == sf::Keyboard::Q)
			{
				Weapon *newWeapon = new Bazooka((*current_worm)->getWormX(), (*current_worm)->getSprite().getPosition().y + (*current_worm)->getSprite().getLocalBounds().height*(*current_worm)->getScale() / 2);
				if((*current_worm)->isLookingOnLeft())
				{
	
					newWeapon->setScaleVector({ -newWeapon->getScale(),newWeapon->getScale() });
				}
				else
				{
					newWeapon->setScaleVector({ newWeapon->getScale(),newWeapon->getScale() });
				}
				newWeapon->update();
				(*current_worm)->setWeapon(newWeapon);
				(*current_worm)->update();
			}

			if(this->event.key.code == sf::Keyboard::W)
			{
				Weapon *newWeapon = new Revolver((*current_worm)->getWormX(), (*current_worm)->getSprite().getPosition().y + (*current_worm)->getSprite().getLocalBounds().height*(*current_worm)->getScale() / 2);
				if ((*current_worm)->isLookingOnLeft())
				{

					newWeapon->setScaleVector({ -newWeapon->getScale(),newWeapon->getScale() });
				}
				else
				{
					newWeapon->setScaleVector({ newWeapon->getScale(),newWeapon->getScale() });
				}
				newWeapon->update();
				(*current_worm)->setWeapon(newWeapon);
				(*current_worm)->update();
			}

			if(this->event.key.code == sf::Keyboard::E)
			{
				(*current_worm)->deleteWeapon();
			}

			if(this->event.key.code == sf::Keyboard::LControl)
			{
				if((*current_worm)->hasWeapon())
				{
					if ((*current_worm)->isLookingOnLeft())
					{
						(*current_worm)->getWeapon()->shoot((*current_worm)->getWeapon()->getRotation()-180);
					}
					else
					{
						(*current_worm)->getWeapon()->shoot((*current_worm)->getWeapon()->getRotation());
					}
				}
			
			}
			if (this->event.key.code == sf::Keyboard::Up)
			{
				if ((*current_worm)->hasWeapon())
				{
					if ((*current_worm)->isLookingOnLeft())
					{
						(*current_worm)->getWeapon()->setRotation((*current_worm)->getWeapon()->getRotation() + 2);
						if ((*current_worm)->getWeapon()->getRotation() > 90)
						{
							(*current_worm)->getWeapon()->setRotation(80);
							(*current_worm)->lookRight();
						}
					}
					else
					{
						(*current_worm)->getWeapon()->setRotation((*current_worm)->getWeapon()->getRotation() - 2);
						if ((*current_worm)->getWeapon()->getRotation() < -90)
						{
							(*current_worm)->getWeapon()->setRotation(-80);
							(*current_worm)->lookLeft();
						}
					}
						
					std::cout << (*current_worm)->getWeapon()->getRotation() << std::endl;
				}
			}
			if (this->event.key.code == sf::Keyboard::Down)
			{
				if ((*current_worm)->hasWeapon())
				{
					if ((*current_worm)->isLookingOnLeft())
					{
						(*current_worm)->getWeapon()->setRotation((*current_worm)->getWeapon()->getRotation() - 2);
						if ((*current_worm)->getWeapon()->getRotation() < -90)
						{
							(*current_worm)->getWeapon()->setRotation(-80);
							(*current_worm)->lookRight();
						}
					}
					else
					{
						(*current_worm)->getWeapon()->setRotation((*current_worm)->getWeapon()->getRotation() + 2);
						if ((*current_worm)->getWeapon()->getRotation() > 90)
						{
							(*current_worm)->getWeapon()->setRotation(80);
							(*current_worm)->lookLeft();
						}
					}

					std::cout << (*current_worm)->getWeapon()->getRotation() << std::endl;
				}
			}
		}
		if (this->event.type == sf::Event::MouseButtonPressed)
		{
			sf::CircleShape circ(20);
			circ.setOrigin(20, 20);
			circ.setFillColor(sf::Color(0, 0, 0,0));
			circ.setPosition(event.mouseButton.x, event.mouseButton.y);
			gWindow->terrain.erase(circ);
		}
		if (sf::Joystick::isConnected(0))
		{
			std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -15.0f) )
		{
			(*current_worm)->moveLeft();
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 15.0f))
		{

			(*current_worm)->moveRight();
		}
		else
		{
			(*current_worm)->stopMove();
		}

		
	

	
	}


	
	
}


GameEvent *GameEvent::ev = nullptr;

GameEvent* GameEvent::GetEventInstance()
{
	if (ev == nullptr) ev = new GameEvent();
	return ev;
}

