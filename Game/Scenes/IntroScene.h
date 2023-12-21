#pragma once

#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"
#include <functional>
#include "Components/TextRenderer.h"

class IntroScene final : public Scene
{
public:
	IntroScene();
private:
	sf::RenderWindow _window;
	void FadeInBlack();
	void FadeOutBlack();
};