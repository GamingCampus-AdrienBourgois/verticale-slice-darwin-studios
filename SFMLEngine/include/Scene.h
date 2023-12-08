#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Components/ObjectName.h"
#include "Maths/Vector2.h"

class Scene {
public:
    explicit Scene(const std::string& _name);
    virtual ~Scene() = default;

    std::unordered_map<std::string, sf::Texture>* GetTexture() {return &texture; }
    
    std::vector<GameObject*>* GetGameObjects() { return &gameObjects; }

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;

    void Render(sf::RenderWindow* _window) const;

    void SetBackground(std::string nom_texture);


	GameObject* CreateGameObject(const ObjectName& _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const ObjectName& _name) const;

    std::string GetName() const;

    int SetTexture(std::string nom_texture, std::string chemin_fichier);


private:
    std::string name;
    std::unordered_map<std::string, sf::Texture> texture;
    std::vector<GameObject*> gameObjects;
    sf::Sprite* background;
};