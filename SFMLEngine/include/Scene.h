#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"

class Scene
{
public:
	explicit Scene(const std::string& _name);
	virtual ~Scene() = default;

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;

	void Render(sf::RenderWindow* _window) const;

	std::string GetName() const;

	GameObject* CreateGameObject(const ObjectName& _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const ObjectName& _name) const;

private:
	std::string name;
	std::vector<GameObject*> gameObjects;
};
