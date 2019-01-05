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
	
private:
	sf::Music music;
	std::string musicPath = "resources/sounds/music_loop.ogg";
	std::string testSamplePath = "resources/sounds/test_sample.ogg";
	std::string revolverSoundPath = "resources/sounds/revolver_sound.ogg";
	sf::SoundBuffer testSampleBuffer;
	sf::Sound testSampleSound;
	sf::SoundBuffer revolverSoundBuffer;
	sf::Sound revolverSound;
	



};
