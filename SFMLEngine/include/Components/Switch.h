#pragma once
#include "GameObject.h"
#include "Scene.h"

class Switch : public Component
{
public:
	static void CreateSwitchObject(Scene* scene, const ObjectName& _name, const float _x, const float _y);
};