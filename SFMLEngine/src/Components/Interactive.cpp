#include "Components/Interactive.h"
#include <iostream>

void Interactive::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	if (can_be_activated) {
		TextRenderer* text_renderer = GetOwner()->CreateComponent<TextRenderer>();
		text_renderer->SetTextName("interagir");
		text_renderer->SetSpecialPosition(Maths::Vector2f(GetOwner()->GetPosition().x + GetOwner()->GetComponent<SquareCollider>()->GetWidth() + 10, GetOwner()->GetPosition().y));
		text_renderer->SetColor(sf::Color::Black);
		text_renderer->SetSize(Maths::Vector2f(120, 20));
		text_renderer->SetCaracterSize(20);
		text_renderer->SetString("E pour interagir");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
			if (can_activate_clock.getElapsedTime().asSeconds() >= 0.1) {
				callback();
				can_activate_clock.restart();
			}
		}
		else {
			can_activate_clock.restart();
		}
	}
	else {
		TextRenderer* text_renderer = GetOwner()->GetComponent<TextRenderer>();
		if (text_renderer != nullptr) {
			GetOwner()->RemoveComponent(text_renderer);
		}
	}
}

void Interactive::SwitchStateLamp() {
	if (is_activated) {
		GetOwner()->GetComponent<SpriteRenderer>()->SetNextSpriteRect(1);
		object->GetComponent<SpriteRenderer>()->SetNextSpriteRect(0);
		is_activated = false;
	}
	else {
		GetOwner()->GetComponent<SpriteRenderer>()->SetNextSpriteRect(0);
		object->GetComponent<SpriteRenderer>()->SetNextSpriteRect(1);
		is_activated = true;
	}
}