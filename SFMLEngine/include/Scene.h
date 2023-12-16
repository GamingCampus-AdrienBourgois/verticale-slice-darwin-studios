#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Capacity.h"
#include "Components/Button.h"
#include <functional>

#include "Components/RectangleShapeRenderer.h"
#include "Components/TextRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/SpriteRenderer.h"


class Scene
{
public:
	explicit Scene(const std::string& _name);
	virtual ~Scene() = default;

	std::unordered_map<std::string, sf::Texture>* GetTexture() {return &texture; }
	Capacity* GetBigCapacity() { return capacity_for_big_doll; }
	Capacity* GetMidCapacity() { return capacity_for_mid_doll; }
	Capacity* GetSmallCapacity() { return capacity_for_small_doll; }

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;

	void Render(sf::RenderWindow* _window) const;

	void SetBackground(std::string nom_texture);

	std::string GetName() const;
	void SetName(std::string _name) { name = _name; }
	std::vector<GameObject*>* GetGameObjects() { return &gameObjects; }


	sf::Font* GetFont() { return &font_scene; }
	void SetFont(std::string chemin_font) { font_scene.loadFromFile(chemin_font); }

	GameObject* CreateGameObject(const ObjectType& _type, const std::string _name);
	void DestroyGameObject(const GameObject* _game_object);
	GameObject* FindGameObject(const std::string& _name) const;
	void ReplaceListGameObject(std::vector<GameObject*> new_list) { gameObjects = new_list; }

	GameObject* CreateButton(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, sf::Color _outlineColor, sf::Color _hoverColor, sf::Color _clickColor, Maths::Vector2u size, std::function<void()> _callback, Capacity* _object);
	GameObject* CreateSpriteButton(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, sf::Color _outlineColor, sf::Color _hoverColor, sf::Color _clickColor, Maths::Vector2f size, std::function<void()> _callback, Capacity* _object, std::string nom_texture);
	GameObject* CreateSpriteButton_forMainMenu(const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f size, std::function<void()> _callback, Capacity* _object, std::string nom_texture, Maths::Vector2f _sprite_size, Maths::Vector2f sprite_space);
	GameObject* CreateButtonWithText(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, sf::Color _outlineColor, sf::Color _hoverColor, sf::Color _clickColor, Maths::Vector2u size, std::function<void()> _callback, Capacity* _object, std::string button_text, sf::Color text_color, int _caractere_size);
	GameObject* CreateSpriteButtonWithText(const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f size, std::function<void()> _callback, Capacity* _object, std::string nom_texture, Maths::Vector2f _sprite_size, Maths::Vector2f sprite_space, std::string button_text, sf::Color text_color, int _caractere_size);

	GameObject* CreateText(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color, Maths::Vector2u size, int _caractere_size);


	int SetTexture(std::string nom_texture, std::string chemin_fichier);


private:
	Capacity* capacity_for_big_doll = new Capacity();
	Capacity* capacity_for_mid_doll = new Capacity();
	Capacity* capacity_for_small_doll = new Capacity();

	std::string name;
	std::unordered_map<std::string, sf::Texture> texture;
	std::vector<GameObject*> gameObjects;
	sf::Sprite* background;
	sf::Font font_scene;
};