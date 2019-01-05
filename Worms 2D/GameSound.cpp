#include "GameSound.h"

GameSound::GameSound()
{
	if (!music.openFromFile(musicPath))
		std::cout << "Error with initialization music!" << std::endl;
	music.setVolume(5);
	if(!testSampleBuffer.loadFromFile(testSamplePath))
		std::cout << "Error with initialization test sample!" << std::endl;

	testSampleSound.setBuffer(testSampleBuffer);
	testSampleSound.setVolume(100);
	if (!revolverSoundBuffer.loadFromFile(revolverSoundPath))
		std::cout << "Error with initialization revolver sound" << std::endl;
	revolverSound.setBuffer(revolverSoundBuffer);
	revolverSound.setVolume(100);

	if(!deathSoundBuffer.loadFromFile(deathSoundPath))
		std::cout << "Error with initialization death sound" << std::endl;
	deathSound.setBuffer(deathSoundBuffer);
	deathSound.setVolume(100);

	
}

void GameSound::PlayMainMusic()
{
	music.play();
}

void GameSound::StartSample()
{
	testSampleSound.play();
}

void GameSound::PauseSample()
{
	testSampleSound.pause();
}

void GameSound::StopSample()
{
	testSampleSound.stop();
}

void GameSound::StartRevolverSound()
{
	revolverSound.play();
}

void GameSound::StopRevolverSound()
{
	revolverSound.stop();
}

void GameSound::PlayDeath()
{
	deathSound.play();
}

void GameSound::StopDeath()
{
	deathSound.stop();
}
