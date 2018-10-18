﻿#include "GameSound.h"

GameSound::GameSound()
{
	if (!music.openFromFile(musicPath))
		std::cout << "Error with initialization music!" << std::endl;
	music.setVolume(5);
	if(!testSampleBuffer.loadFromFile(testSamplePath))
		std::cout << "Error with initialization test sample!" << std::endl;
	testSampleSound.setBuffer(testSampleBuffer);
	testSampleSound.setVolume(100);

	
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