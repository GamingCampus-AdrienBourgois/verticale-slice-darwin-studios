#pragma once
#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Components/Capacity.h"
#include "Components/Button.h"

#include "Components/RectangleShapeRenderer.h"
#include "Components/TextRenderer.h"
#include "Components/SquareCollider.h"


class Scene
{
public:
	explicit Scene(const std::string& _name);
	virtual ~Scene() = default;

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;

	void Render(sf::RenderWindow* _window) const;

	std::string GetName() const;
	std::vector<GameObject*>* GetGameObjects() { return &gameObjects; }


	sf::Font* GetFont() { return &font_scene; }
	void SetFont(std::string chemin_font) { font_scene.loadFromFile(chemin_font); }

	GameObject* CreateGameObject(const ObjectType& _type, const std::string _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const std::string& _name) const;

private:
	std::string name;
	std::vector<GameObject*> gameObjects;
	sf::Font font_scene;

protected:
	GameObject* CreateButton(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, Maths::Vector2u size, std::string button_text, Capacity* _object);
	GameObject* CreateText(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, Maths::Vector2u size, int _caractere_size);
};
