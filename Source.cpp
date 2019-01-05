#include "GameEvent.h"
#include "GameWindow.h"
#include "GameSound.h"


int main()
{
	
	GameWindow *window = GameWindow::GetGameWindowInstance(800, 600, "Worms 2D");

	while (window->GetInstance()->isOpen())
	{
		GameEvent *ev = GameEvent::GetEventInstance() ;
		ev->handleEvents();
		window->MainLoop();
		


	}



	return 0;
}
