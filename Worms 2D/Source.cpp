#include "GameEvent.h"
#include "GameWindow.h"


int main()
{
	
	GameWindow *window = GameWindow::GetGameWindowInstance(800, 600, "Worms 2D");


	while (window->GetInstance()->isOpen())
	{
		GameEvent ev;
		ev.handleEvents();
		window->MainLoop();


	}



	return 0;
}