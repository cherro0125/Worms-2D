#include "Menu.h"
#include <iostream>
#include "GameSound.h"
#include "GameWindow.h"

Menu::Menu()
{
	this->font.loadFromFile("resources/fonts/sansation.ttf");
	this->txt.setFont(font);
	this->txt.setFillColor(sf::Color(255,255,255));
	this->txt.setCharacterSize(32);
	this->txt.setString("MAIN MENU");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->txt.setPosition(400, 50);

	this->keyboard_texture.loadFromFile("resources/images/keyboard.png");
	this->keyboard_sprite.setTexture(keyboard_texture, true);
	this->keyboard_sprite.setPosition(0, 0);
	this->gamepad_texture.loadFromFile("resources/images/gamepad.png");
	this->gamepad_sprite.setTexture(gamepad_texture, true);
	this->gamepad_sprite.setPosition(0, 0);
	
	this->draw_keyboard = false;
	this->draw_gamepad = false;

	
}


void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (draw_keyboard)
		target.draw(this->keyboard_sprite, states);
	else if (draw_gamepad)
		target.draw(this->gamepad_sprite, states);
	for (unsigned int i = 0; i < this->buttons.size(); ++i)
	{
		target.draw(*(this->buttons[i]), states);
	}
	
	
	
	target.draw(this->txt, states);

}

Button* Menu::getButton(float mouse_x, float mouse_y)
{
	Button *tmp = nullptr;
	for (int i = 0; i < buttons.size(); ++i)
	{
		if (mouse_x > (buttons[i]->getPosition().x - (buttons[i]->getSize().x / 2))
			&& mouse_x < (buttons[i]->getPosition().x + (buttons[i]->getSize().x / 2))
			&& mouse_y >(buttons[i]->getPosition().y - (buttons[i]->getSize().y / 2))
			&& mouse_y < (buttons[i]->getPosition().y + (buttons[i]->getSize().y / 2))
			)
		{
			tmp = buttons[i];
		}
		else if(!buttons[i]->isClicked())
		{
			buttons[i]->clear();
		}
	}
	return tmp;
}

void Menu::clearClickedButton()
{
	for (int i = 0; i < buttons.size(); ++i)
	{
		if(buttons[i]->isClicked())
			buttons[i]->clear();
		
	}
}

void Menu::clear()
{
	draw_keyboard = false;
	draw_gamepad = false;
	this->txt.setFillColor(sf::Color(255, 255, 255));
	buttons.clear();
}

void Menu::changeMenu(int choice)
{
	
	if (choice == PAUSE)
	{
		this->clear();
		this->pauseMenu();
	}
	else if (choice == MENU)
	{
		this->clear();
		this->mainMenu();
	}
	else if (choice == HELP)
	{
		this->clear();
		this->helpMainMenu();
	}
	else if (choice == HELP_PAUSE)
	{
		this->clear();
		this->helpMenu();
	}
	else if (choice == RED_WIN)
	{
		this->clear();
		this->redWinScreen();
	}
	else if (choice == BLUE_WIN)
	{
		this->clear();
		this->blueWinScreen();
	}
	else if (choice == KEYBOARD)
	{
		this->changeDrawKeyboard();
		this->clearClickedButton();
	}
	else if (choice == GAMEPAD)
	{
		this->changeDrawGamepad();
		this->clearClickedButton();
	}
}

void Menu::mainMenu()
{
	this->txt.setString("MAIN MENU");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->buttons.push_back(new Button(400, txt.getPosition().y * 3 + txt.getCharacterSize(), "Start", GAME));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Help", HELP));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Exit", EXIT));
}
void Menu::pauseMenu()
{
	this->txt.setString("PAUSE");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->buttons.push_back(new Button(400, txt.getPosition().y * 3 + txt.getCharacterSize(), "Resume", GAME));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Help", HELP_PAUSE));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Exit to menu", MENU));
}
void Menu::helpMainMenu()
{
	draw_keyboard = true;
	this->txt.setString("");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->buttons.push_back(new Button(400, 550, "Back", MENU));
	this->buttons.push_back(new Button(400 - buttons.back()->getSize().x/2, buttons.back()->getSize().y/2, "Keyboard", KEYBOARD));
	this->buttons.push_back(new Button(400 + buttons.back()->getSize().x/2, buttons.back()->getSize().y/2, "Gamepad", GAMEPAD));
}
void Menu::helpMenu()
{
	draw_keyboard = true;
	this->txt.setString("");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->buttons.push_back(new Button(400, 550, "Back", PAUSE));
	this->buttons.push_back(new Button(400 - buttons.back()->getSize().x / 2, buttons.back()->getSize().y / 2, "Keyboard", KEYBOARD));
	this->buttons.push_back(new Button(400 + buttons.back()->getSize().x / 2, buttons.back()->getSize().y / 2, "Gamepad", GAMEPAD));
}
void Menu::redWinScreen()
{
	this->txt.setString("RED TEAM WINS");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->txt.setFillColor(sf::Color(255, 0, 0));
	this->buttons.push_back(new Button(400, txt.getPosition().y * 3 + txt.getCharacterSize(), "Retry", GAME));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Help", HELP_PAUSE));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Exit to menu", MENU));
	GameSound *gs = GameWindow::GetGameWindowInstance()->GetGameSound();
	gs->PlayWin();
}
void Menu::blueWinScreen()
{
	this->txt.setString("BLUE TEAM WINS");
	this->txt.setOrigin(this->txt.getLocalBounds().width / 2, this->txt.getLocalBounds().height / 2);
	this->txt.setFillColor(sf::Color(0, 0, 255));
	this->buttons.push_back(new Button(400, txt.getPosition().y * 3 + txt.getCharacterSize(), "Retry", GAME));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Help", HELP_PAUSE));
	this->buttons.push_back(new Button(400, buttons.back()->getPosition().y + buttons.back()->getSize().y, "Exit to menu", MENU));
	GameSound *gs = GameWindow::GetGameWindowInstance()->GetGameSound();
	gs->PlayWin();
}
void Menu::changeDrawKeyboard()
{
	this->draw_keyboard = true;
	this->draw_gamepad = false;
}
void Menu::changeDrawGamepad()
{
	this->draw_keyboard = false;
	this->draw_gamepad = true;
}