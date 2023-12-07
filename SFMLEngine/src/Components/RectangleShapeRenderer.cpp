#include "Components/RectangleShapeRenderer.h"

#include "SFML/Graphics/Shape.hpp"
#include "Components/Button.h"
#include "Engine.h"
#include "Modules/SceneModule.h"

RectangleShapeRenderer::RectangleShapeRenderer()
{
	shape = new sf::RectangleShape();
	text = new sf::Text();
}

RectangleShapeRenderer::~RectangleShapeRenderer()
{
	delete shape;
	shape = nullptr;
	delete text;
	text = nullptr;
}

void RectangleShapeRenderer::Render(sf::RenderWindow* _window)
{
	ARendererComponent::Render(_window);

	GameObject* owner = GetOwner();

	const Maths::Vector2<float> position = owner->GetPosition();
	shape->setPosition(position.x, position.y);
	shape->setSize(static_cast<sf::Vector2f>(owner->GetScale() * size));
	shape->setRotation(owner->GetRotation());
	shape->setFillColor(color);

	_window->draw(*shape);

	if (owner->GetType() == ButtonType) {
		std::string button_text = owner->GetComponent<Button>()->GetText();
		if (button_text != "") {
			Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
			text->setString(button_text);
			text->setFont(*scene->GetFont());
			text->setCharacterSize(20);
			text->setPosition(position.x, position.y);
			text->setFillColor(sf::Color::White);
			_window->draw(*text);
		}
	}
}
