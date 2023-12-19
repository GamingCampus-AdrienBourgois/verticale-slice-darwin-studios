#pragma once
#include "Capacity.h"
#include <SFML/Audio.hpp>

class InversionGravite : public Capacity
{
public:
	InversionGravite();
	~InversionGravite();

	void GraviteInversion(GameObject* player, const float _delta_time);
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

	void PlaySound();
	void StopSound();

private:
	bool inversion = false;
	int count = 0;
	sf::Clock inversionClock;
	int timeInversion = 10;

	bool soundPlayed = false;
	sf::SoundBuffer* soundBufferInversionGravite;
	sf::Sound* soundInversionGravite;
};
