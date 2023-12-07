#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Maths/Vector2.h"
#include <unordered_map>
#include <SFML/Window/Event.hpp>
#include "Components/ObjectName.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Component;

class GameObject
{
public:
	GameObject() = default;
	~GameObject();

	ObjectName GetName() const { return name; }
	Maths::Vector2<float> GetPosition() const { return position; }
	float GetRotation() const { return rotation; }
	Maths::Vector2<float> GetScale() const { return scale; }

	void SetName(const ObjectName& _name) { name = _name; }
	void SetPosition(const Maths::Vector2<float>& _position) { position = _position; }
	void SetRotation(const float _rotation) { rotation = _rotation; }
	void SetScale(const Maths::Vector2<float>& _scale) { scale = _scale; }

	template<typename T>
	T* CreateComponent();

	template<typename T>
	T* GetComponent();

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;
	void Render(sf::RenderWindow* _window) const;
	sf::FloatRect getBounds(sf::RectangleShape object) const;

private:
	ObjectName name = ObjectName::GameObjectName;

	Maths::Vector2<float> position = Maths::Vector2f::Zero;
	float rotation = 0.0f;
	Maths::Vector2<float> scale = Maths::Vector2f::One;

	std::vector<Component*> components;
};

template<typename T>
T* GameObject::CreateComponent()
{
	T* component = new T();
	component->SetOwner(this);
	components.push_back(component);
	return component;
}

template<typename T>
T* GameObject::GetComponent()
{
	for (Component* component : components)
	{
		T* result = dynamic_cast<T*>(component);
		if (result != nullptr)
			return result;
	}

	return nullptr;
}
