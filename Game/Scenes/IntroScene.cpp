#include "Scene.h"
#include "Engine.h"
#include "WindowModule.h"
#include <functional>
#include "Components/TextRenderer.h"
#include "IntroScene.h"
#include "SceneModule.h"
#include "MainMenuScene.h"
#include "LaunchFunction.h"

IntroScene::IntroScene() : Scene("IntroScene", [] {}) {
    FadeInBlack();
    SetTexture("darwin_logo", "Assets/background/darwin_logo.png");
    SetBackground("darwin_logo");
    FadeOutBlack();
    LaunchFunction::LaunchScene<MainMenuScene>();
}

void IntroScene::FadeInBlack() {
    sf::Vector2u window_size = _window.getSize();

    GameObject* fadeRectObject = CreateShapeAlone(
        ShapeType, "rectangle_noir", Maths::Vector2f(window_size.x / 2, window_size.y / 2), sf::Color::Black, sf::Vector2f(window_size.x, window_size.y)
    );
}

void IntroScene::FadeOutBlack() {
    sf::Vector2u window_size = _window.getSize();

    GameObject* fadeRectObject = CreateShapeAlone(
        ShapeType, "rectangle_noir", Maths::Vector2f(window_size.x / 2, window_size.y / 2), sf::Color::Black, sf::Vector2f(window_size.x, window_size.y)
    );
}

