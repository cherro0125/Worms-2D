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
	if (!revolverSoundBuffer.loadFromFile(revolverSoundPath))
		std::cout << "Error with initialization revolver sound" << std::endl;
	revolverSound.setBuffer(revolverSoundBuffer);
	revolverSound.setVolume(100);

	if(!bazookaSoundBuffer.loadFromFile(bazookaSoundPath))
		std::cout << "Error with initialization bazooka sound" << std::endl;
	bazookaSound.setBuffer(bazookaSoundBuffer);
	bazookaSound.setVolume(100);

	if(!deathSoundBuffer.loadFromFile(deathSoundPath))
		std::cout << "Error with initialization death sound" << std::endl;
	deathSound.setBuffer(deathSoundBuffer);
	deathSound.setVolume(60);

	if(!winSoundBuffer.loadFromFile(winSoundPath))
		std::cout << "Error with initialization win sound" << std::endl;
	winSound.setBuffer(winSoundBuffer);
	winSound.setVolume(90);


	
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

void GameSound::StartBazookaSound()
{
	bazookaSound.play();
}

void GameSound::StopBazookaSound()
{
	bazookaSound.stop();
}

void GameSound::PlayDeath()
{
	deathSound.play();
}

void GameSound::StopDeath()
{
	deathSound.stop();
}

void GameSound::PlayWin()
{
	winSound.play();
}

void GameSound::StopWin()
{
	winSound.stop();
}
