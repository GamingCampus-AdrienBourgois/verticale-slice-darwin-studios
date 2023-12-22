#pragma once
#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"

#include <random>

class TransitionScene : public Scene {
private:
	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();
	std::mt19937 gen; // Mersenne Twister 19937 comme générateur pseudo-aléatoire
	std::vector<Capacity> capacities;

	int tipLine;
	std::string tip;

	void CallBack();
	int randomNumber(int a, int b);
	

public:
	TransitionScene(std::vector<Capacity> params);
};