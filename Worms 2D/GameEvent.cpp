#include "GameEvent.h"
#include <iostream>
#include "Revolver.h"


GameEvent::GameEvent()
{
	this->gWindow = GameWindow::GetGameWindowInstance();
	this->window = gWindow->GetInstance();
	current_worm = this->gWindow->GetCurrentWorm();
	worms = this->gWindow->GetWormsArray();
	worm_count = this->gWindow->GetWormCount();
	current_worm_id = this->gWindow->GetCurrentWormID();
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
				*current_worm_id = (*current_worm_id + 1) % worm_count;
				(*current_worm)->stopMove();
				*current_worm = (worms->at(*current_worm_id));
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
				(*current_worm)->setWeapon(nullptr);
			}

			if(this->event.key.code == sf::Keyboard::LControl)
			{
				if((*current_worm)->hasWeapon())
				{
					if ((*current_worm)->isLookingOnLeft())
						(*current_worm)->getWeapon()->shoot(SHOOT_LEFT);
					else
						(*current_worm)->getWeapon()->shoot(SHOOT_RIGHT);
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

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -15.0f) && (*current_worm)->left() > 0)
		{
			(*current_worm)->moveLeft();
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 15.0f) && (*current_worm)->right() < this->window->getSize().x)
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

