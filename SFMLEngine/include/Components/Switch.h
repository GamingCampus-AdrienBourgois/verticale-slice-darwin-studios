#pragma once
#include "GameObject.h"
#include "Scene.h"

class Switch : public Component
{
public:
	static void CreateSwitch(Scene* scene, const ObjectType& _type, const float _x, const float _y);
	bool GetOn() { return on; }
	void SetOn(bool value) {
		on = value;
	}
private:
	bool on;
};