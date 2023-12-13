#pragma once
#include "Doll.h"
#include "Engine.h"

#include "Modules/WindowModule.h"
#include "Modules/SceneModule.h"
#include "Scene.h"

class Player : public Component
{
public:
	void SetSpawn(Scene spawn) { *checkpoint0 = spawn; }

	void SetHp(int new_hp) { hp = new_hp; }
	void SetSpeed(int new_speed) { speed = new_speed; }
	void SetGravity(int _gravity) { gravity = _gravity; }

	int GetHp() { return hp; }
	int GetSpeed() { return speed; }
	int GetGravity() { return gravity; }


	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
	int hp = 0;
	int speed = 300;
	int gravity = 100;

	// Variables jump & switch
	bool can_jump = false;
	bool is_jumping = false;
	sf::Clock jumping_time;

	bool can_switch = false;
	bool is_switching = false;

	bool can_check = false;
	bool is_check = false;

	// GameObject Doll
	int actuall_doll_int = 0;
	int checkpoint_nbr = 0;

	GameObject* big_dollOff = nullptr;
	GameObject* mid_dollOff = nullptr;


	bool copiedSpawn = false;
	Scene* checkpoint0 = nullptr;
	std::vector<GameObject*> gameObjectsCheckpoint0;

	Scene* checkpoint1 = nullptr;
	std::vector<GameObject*> gameObjectsCheckpoint1;

	Scene* checkpoint2 = nullptr;
	std::vector<GameObject*> gameObjectsCheckpoint2;

	sf::Color colorBig = sf::Color::Red;
	sf::Color colorMid = sf::Color::Blue;
	sf::Color colorSmall = sf::Color::Green;


	// Get modules
	Engine* engine = Engine::GetInstance();
	ModuleManager* moduleManager = engine->GetModuleManager();

	WindowModule* windowModule = moduleManager->GetModule<WindowModule>();
	sf::Vector2u sizeWindow = windowModule->GetWindowSize();
	
	SceneModule* sceneModule = moduleManager->GetModule<SceneModule>();

	// Functions
	void Move(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects );
	void Jump(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, std::vector<GameObject*>* gameObjects );

	GameObject* CreateDollOff(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color);
	void SwitchDoll(std::unordered_map<sf::Keyboard::Key, bool>* pressed_input, Scene* scene);
	void ReturnCheckpoint(Scene* scene, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);
};
