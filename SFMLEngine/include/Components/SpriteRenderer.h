#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "ARendererComponent.h"

class SpriteRenderer : public ARendererComponent
{
public:
	SpriteRenderer();
	~SpriteRenderer() override;

	float GetHeight() const { return height; }
	float GetWidth() const { return width; }
	void SetWidth(const float _width) { width = _width; }
	void SetHeight(const float _height) { height = _height; }
	void SetOrigin(float x, float y);
	sf::Sprite* GetSprite() { return sprite; }

	void SetSprite(sf::Texture* new_texture, Maths::Vector2f _size);
	void SetSpriteRect(sf::Texture* new_texture, Maths::Vector2f _size, Maths::Vector2f _sprite_size, Maths::Vector2f _position, Maths::Vector2f _sprite_space);
	void SetNextSpriteRect(int num_sprite_on_sheet);

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	int width = 100;
	int height = 100;
	Maths::Vector2f sprite_size;
	Maths::Vector2f sprite_space;
	Maths::Vector2f sprite_first_position;
};
