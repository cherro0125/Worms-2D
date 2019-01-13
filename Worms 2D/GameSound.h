#pragma once
#include<string>
#include<SFML/Audio.hpp>
#include<iostream>
class GameSound
{
public:
	GameSound();
	void PlayMainMusic();
	void StartSample();
	void PauseSample();
	void StopSample();
	void StartRevolverSound();
	void StopRevolverSound();
	void StartBazookaSound();
	void StopBazookaSound();
	void PlayDeath();
	void StopDeath();
	void PlayWin();
	void StopWin();
	
	
private:
	sf::Music music;
	std::string musicPath = "resources/sounds/music_loop.ogg";
	std::string testSamplePath = "resources/sounds/test_sample.ogg";
	std::string revolverSoundPath = "resources/sounds/revolver_sound.ogg";
	std::string bazookaSoundPath = "resources/sounds/bazooka_sound.ogg";
	std::string deathSoundPath = "resources/sounds/death.ogg";
	std::string winSoundPath = "resources/sounds/fatality.ogg";
	sf::SoundBuffer testSampleBuffer;
	sf::Sound testSampleSound;
	sf::SoundBuffer revolverSoundBuffer;
	sf::Sound revolverSound;
	sf::SoundBuffer bazookaSoundBuffer;
	sf::Sound bazookaSound;
	sf::SoundBuffer deathSoundBuffer;
	sf::Sound deathSound;
	sf::SoundBuffer winSoundBuffer;
	sf::Sound winSound;
	



};
