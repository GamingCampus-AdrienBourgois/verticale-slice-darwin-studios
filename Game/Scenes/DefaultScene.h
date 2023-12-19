#pragma once
#include "Capacity.h"
#include "Player.h"
#include "Scene.h"
#include "SquareCollider.h"
#include "WindowModule.h"

class Capacity;

class DefaultScene final : public Scene
{
public:
	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	DefaultScene(std::vector<Capacity> params);

	GameObject* CreateColliderObject(Scene* scene, const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f _size);

	GameObject* CreateSwitch(Scene* scene, const ObjectType& _type, std::string _name, const float _x, const float _y);

private:
	void SpawnObjectLevel3();

	GameObject* CreatePlayer(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color);
};
