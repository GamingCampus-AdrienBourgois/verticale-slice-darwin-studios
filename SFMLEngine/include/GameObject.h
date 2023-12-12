#pragma once
#include <string>
#include <vector>

#include "Component.h"
#include "Maths/Vector2.h"
#include <unordered_map>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Components/ObjectType.h"
#include "Capacity.h"

class Component;
class Capacity;

class GameObject
{
public:
	GameObject() = default;
	~GameObject();

	ObjectType GetType() const { return type; }
	std::string GetName() const { return name; }
	Maths::Vector2<float> GetPosition() const { return position; }
	float GetRotation() const { return rotation; }
	Maths::Vector2<float> GetScale() const { return scale; }

	void SetType(const ObjectType& _type) { type = _type; }
	void SetName(const std::string& _name) { name = _name; }
	void SetPosition(const Maths::Vector2<float>& _position) { position = _position; }
	void SetRotation(const float _rotation) { rotation = _rotation; }
	void SetScale(const Maths::Vector2<float>& _scale) { scale = _scale; }
	void SetSwitchOn(bool value) {switchOn = value;}
	bool GetSwitchOn() { return switchOn; }
	template<typename T>
	T* CreateComponent();

	template<typename T>
	T* GetComponent();

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);

	template<typename T>
	T* CreateCapacity();

	template<typename T>
	T* GetCapacity();

	void AddCapacity(Capacity* _capacity);
	void RemoveCapacity(Capacity* _capacity);

	void Update(float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) const;
	void Render(sf::RenderWindow* _window) const;
	sf::FloatRect getBounds(sf::RectangleShape object) const;

private:
	ObjectType type = ObjectType::GameObjectType;
	std::string name = "GameObject";

	Maths::Vector2<float> position = Maths::Vector2f::Zero;
	float rotation = 0.0f;
	Maths::Vector2<float> scale = Maths::Vector2f::One;

	std::vector<Component*> components;
	std::vector<Capacity*> capacitys;

	bool is_rendering = true;
	bool switchOn = false;
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

template<typename T>
T* GameObject::CreateCapacity()
{
	T* capacity = new T();
	capacity->SetOwner(this);
	capacitys.push_back(capacity);
	return capacity;
}

template<typename T>
T* GameObject::GetCapacity()
{
	for (Capacity* capacity : capacitys)
	{
		T* result = dynamic_cast<T*>(capacity);
		if (result != nullptr)
			return result;
	}

	return nullptr;
}
