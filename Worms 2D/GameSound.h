#pragma once
#include<string>
#include<SFML/Audio.hpp>
#include<iostream>
/*!
 * \brief Klasa dźwięków gry
 *
 */
class GameSound
{
public:
	/*!
	 * \brief Konstruktor
	 *
	 */
	GameSound();
	/*!
	 * \brief Odtwarza główne audio w grze
	 *
	 */
	void PlayMainMusic();
	/*!
	 * \brief Odtwarza odgłos worma
	 *
	 */
	void StartSample();
	/*!
	 * \brief Pauzuje odgłos worma
	 *
	 */
	void PauseSample();
	/*!
	 * \brief Stopuje odgłos worma
	 *
	 */
	void StopSample();
	/*!
	 * \brief Odtwarza odgłos wystrzału rewolwera
	 *
	 */
	void StartRevolverSound();
	/*!
	 * \brief Stopuje odtwarzanie odgłosu wystrzału rewolwera
	 *
	 */
	void StopRevolverSound();
	/*!
	 * \brief Odtwarza odgłos wystrzału bazooki
	 *
	 */
	void StartBazookaSound();
	/*!
	 * \brief Stopuje odtwarzanie odgłosu wystrzału bazooki
	 *
	 */
	void StopBazookaSound();
	/*!
	 * \brief Odtwarza dźwięk śmierci worma
	 *
	 */
	void PlayDeath();
	/*!
	 * \brief Stopuje dźwięk śmierci worma
	 *
	 */
	void StopDeath();
	/*!
	 * \brief Odtwarza dźwięk zwycięstwa
	 *
	 */
	void PlayWin();
	/*!
	 * \brief Stopuje dźwięk zwycięstwa
	 *
	 */
	void StopWin();


private:
	/*!
	 * \brief Główna muzyka
	 *
	 */
	sf::Music music;
	/*!
	 * \brief Ścieżka do pliku zawierającego muzyke
	 *
	 */
	std::string musicPath = "resources/sounds/music_loop.ogg";
	/*!
	 * \brief Ścieżka do pliku zawierającego odgłos
	 *
	 */
	std::string testSamplePath = "resources/sounds/test_sample.ogg";
	/*!
	 * \brief Ścieżka do pliku zawierającego odgłos broni
	 *
	 */
	std::string revolverSoundPath = "resources/sounds/revolver_sound.ogg";
	/*!
	 * \brief Ścieżka do pliku zawierającego odgłos broni
	 *
	 */
	std::string bazookaSoundPath = "resources/sounds/bazooka_sound.ogg";
	/*!
	 * \brief Ścieżka do pliku zawierającego odgłos śmierci
	 *
	 */
	std::string deathSoundPath = "resources/sounds/death.ogg";
	/*!
	 * \brief Ścieżka do pliku zawierającego odgłos wygranej
	 *
	 */
	std::string winSoundPath = "resources/sounds/fatality.ogg";
	/*!
	 * \brief Buffor dla dźwięku worma
	 *
	 */
	sf::SoundBuffer testSampleBuffer;
	/*!
	 * \brief Obiekt dźwięku worma
	 *
	 */
	sf::Sound testSampleSound;
	/*!
	 * \brief Buffor dla dźwięku rewolwera
	 *
	 */
	sf::SoundBuffer revolverSoundBuffer;
	/*!
	 * \brief Obiekt dźwięku rewolwera
	 *
	 */
	sf::Sound revolverSound;
	/*!
	 * \brief Buffor dla dźwięku bazooki
	 *
	 */
	sf::SoundBuffer bazookaSoundBuffer;
	/*!
	 * \brief Obiekt dźwięku bazooki
	 *
	 */
	sf::Sound bazookaSound;
	/*!
	 * \brief Buffor dla dźwięku śmierci
	 *
	 */
	sf::SoundBuffer deathSoundBuffer;
	/*!
	 * \brief Obiekt dźwięku śmierci
	 *
	 */
	sf::Sound deathSound;
	/*!
	 * \brief Buffor dla dźwięku wygranej
	 *
	 */
	sf::SoundBuffer winSoundBuffer;
	/*!
	 * \brief Obiekt dźwięku wygranej
	 *
	 */
	sf::Sound winSound;




};
