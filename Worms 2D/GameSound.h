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
	
private:
	sf::Music music;
	std::string musicPath = "resources/sounds/music_loop.ogg";
	std::string testSamplePath = "resources/sounds/test_sample.ogg";
	sf::SoundBuffer testSampleBuffer;
	sf::Sound testSampleSound;
	



};
