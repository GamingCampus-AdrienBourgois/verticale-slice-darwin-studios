#pragma once
#include "Doll.h"
#include "Engine.h"

#include "Modules/WindowModule.h"
#include "Modules/SceneModule.h"
#include "Scene.h"

class Player : public Component
{
public:
	Player();
	~Player();
	void SetHp(int new_hp) { hp = new_hp; }
	void SetSpeed(int new_speed) { speed = new_speed; }
	void SetGravity(int _gravity) { gravity = _gravity; }

	int GetHp() { return hp; }
	int GetSpeed() { return speed; }
	int GetGravity() { return gravity; }


	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
	int hp = 0;
	int speed = 100;
	int gravity = 100;

	// Variables jump & switch
	bool can_jump = false;
	bool is_jumping = false;
	sf::Clock jumping_time;

	bool can_switch = false;
	bool is_switching = false;

	// GameObject Doll
	int actuall_doll_int = 0;

	GameObject* big_dollOff = nullptr;
	GameObject* mid_dollOff = nullptr;


	// Get modules
	Engine* engine = Engine::GetInstance();
	ModuleManager* moduleManager = engine->GetModuleManager();

	WindowModule* windowModule = moduleManager->GetModule<WindowModule>();
	sf::Vector2u sizeWindow = windowModule->GetWindowSize();
	
	SceneModule* sceneModule = moduleManager->GetModule<SceneModule>();

	// Functions
	void Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects );
	void Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects );

	GameObject* CreateDollOff(const ObjectName& _name, Maths::Vector2f _position, const sf::Color _color);
	void SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
};
