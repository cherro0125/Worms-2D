#include "GameEvent.h"
#include "GameWindow.h"
#include "GameSound.h"


int main()
{
	
	GameWindow *window = GameWindow::GetGameWindowInstance(1240, 1024, "Worms 2D");

	while (window->GetInstance()->isOpen())
	{
		GameEvent ev;
		ev.handleEvents();
		window->MainLoop();
		


	}



	return 0;
}
