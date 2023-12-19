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
	sf::Sprite* GetSprite() { return sprite; }
	sf::Texture* GetTextureSprite() { return texture; }

	void SetWidth(const float _width) { width = _width; }
	void SetHeight(const float _height) { height = _height; }
	void SetOrigin(float x, float y);
	void SetSpriteFirstPosition(Maths::Vector2f _sprite_first_position) { sprite_first_position = _sprite_first_position; }

	void SetSprite(sf::Texture* new_texture, Maths::Vector2f _size);
	void SetSpriteRect(sf::Texture* new_texture, Maths::Vector2f _size, Maths::Vector2f _sprite_size, Maths::Vector2f _position, Maths::Vector2f _sprite_space);
	void SetNextSpriteRect(int num_sprite_on_sheet);
	void SetOneSprite(sf::Texture* new_texture, sf::Sprite* new_sprite, Maths::Vector2f(_size));

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
