#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Modules/WindowModule.h"

class Doll
{
public:
	void SetHp(int new_hp) { hp = new_hp; }
	void SetSpeed(int new_speed) { speed = new_speed; }

	int GetHp() { return hp; }
	int GetSpeed() { return speed; }
	int GetGravity() { return gravity; }

	Doll() {
		sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();
		speed = window_size.x / 11;
	}

private:
	int hp = 0;
	int speed = 0;
	int gravity = 100;
};

