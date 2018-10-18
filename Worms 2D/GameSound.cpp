#include "GameSound.h"

GameSound::GameSound()
{
	if (!music.openFromFile(musicPath))
		std::cout << "Error with initialization music!" << std::endl;
	
}

void GameSound::PlayMainMusic()
{
	music.play();
}
