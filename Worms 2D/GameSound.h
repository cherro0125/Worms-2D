#pragma once
#include<string>
#include<SFML/Audio.hpp>
#include<iostream>
class GameSound
{
public:
	GameSound();
	void PlayMainMusic();
	
private:
	sf::Music music;
	std::string musicPath = "resources/sounds/music_loop.ogg";



};
