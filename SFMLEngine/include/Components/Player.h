#pragma once
#include "GameObject.h"
#include "Doll.h"
#include "Engine.h"
#include "Modules/WindowModule.h"

class Player : public Component
{
private:
	Doll* small_doll = nullptr;
	Doll* medium_doll = nullptr;
	Doll* big_doll = nullptr;

	int actuall_doll_int = 0; //0 big / 1 medium / 2 small
	Doll* actual_doll = nullptr;

public:
	Player();
	~Player();

	void Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
	void Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
	void SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
	bool can_jump = true;
	bool is_jumping = false;
	sf::Clock jumping_time;

	bool can_switch = true;
	bool is_switching = false;


	Engine* engine = Engine::GetInstance();
	ModuleManager* moduleManager = engine->GetModuleManager();
	WindowModule* windowModule = moduleManager->GetModule<WindowModule>();

	sf::Vector2u sizeWindow = windowModule->GetWindowSize();
};
