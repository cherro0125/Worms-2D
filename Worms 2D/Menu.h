#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>

enum game_states{GAME,PAUSE,MENU,HELP,HELP_PAUSE,EXIT};
class Menu : public sf::Drawable
{
public:
	Menu();
	Button* getButton(float x, float y);
	void clearClickedButton();
	void clear();
	void changeMenu(int choice);
	

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	
private:
	sf::Font font;
	sf::Text txt;
	std::vector <Button*> buttons;
	sf::Sprite keyboard_sprite;
	sf::Texture keyboard_texture;
	bool draw_help;
	void mainMenu();
	void pauseMenu();
	void helpMainMenu();
	void helpMenu();
};
