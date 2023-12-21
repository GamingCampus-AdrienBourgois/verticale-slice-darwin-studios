#include "TransitionScene.h"
#include "LaunchFunction.h"

TransitionScene::TransitionScene() : Scene("TransitionScene")
{
	GameObject* background = CreateShapeAlone(ShapeType, "shapeBackground", Maths::Vector2f(), sf::Color::Black, window_size);

	GameObject* text1 = CreateText(TextType, "text1", Maths::Vector2f(), sf::Color::White, Maths::Vector2u(100, 100), 50);
	text1->GetComponent<TextRenderer>()->SetString("Coucou");
}