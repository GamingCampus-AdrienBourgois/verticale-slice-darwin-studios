#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "GameObject.h"
#include "Components/ObjectName.h"
#include "Maths/Vector2.h"

class Scene {
public:
    explicit Scene(const std::string& _name);
    virtual ~Scene() = default;


	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;

    void Render(sf::RenderWindow* _window) const;

    


	GameObject* CreateGameObject(const ObjectName& _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const ObjectName& _name) const;


private:
    std::string name;
    std::vector<GameObject*> gameObjects;
};