#pragma once
#include "GameObject.h"
#include "Scene.h"
#include <functional>


class Button : public Component
{
public:
	Button() = default;
	~Button() = default;

	void SetObject(Capacity* _object) { object = _object; }
	void SetCallback(std::function<void()> _callback) { callback = _callback; }

	Capacity* GetObject() { return object; }

	void CheckHover();

	void Execute();
	void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input);

	void DollSelectCapacity();
	void SelectCapacity();

	bool is_clicked = false;
	bool is_disabled = false;
	GameObject* has_select = nullptr;
	GameObject* is_selected_by = nullptr;

private:

	std::function<void()> callback;
	Capacity* object = nullptr;
};
