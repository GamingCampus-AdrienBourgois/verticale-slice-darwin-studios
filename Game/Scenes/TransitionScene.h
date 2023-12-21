#pragma once
#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"

class TransitionScene : public Scene {
private:
	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

public:
	TransitionScene();
};