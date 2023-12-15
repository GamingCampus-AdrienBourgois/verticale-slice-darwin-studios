#include "Components/SpriteRenderer.h"
#include "SFML/Graphics.hpp"

SpriteRenderer::SpriteRenderer()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
}

SpriteRenderer::~SpriteRenderer()
{
	delete sprite;
	delete texture;
	sprite = nullptr;
	texture = nullptr;
}

void SpriteRenderer::SetSprite(sf::Texture* new_texture, Maths::Vector2f _size)
{
	texture = new_texture;
	width = _size.x;
	height = _size.y;
	sprite->setTexture(*texture);
	sprite->setScale(_size.x / texture->getSize().x, _size.y / texture->getSize().y);
}

void SpriteRenderer::SetSpriteRect(sf::Texture* new_texture, Maths::Vector2f _size, Maths::Vector2f _sprite_size, Maths::Vector2f _position, Maths::Vector2f _sprite_space)
{
	texture = new_texture;
	width = _size.x;
	height = _size.y;
	sprite_first_position = _position;
	sprite_size = _sprite_size;
	sprite_space = _sprite_space;
	sprite->setTexture(*texture);
	sprite->setTextureRect(sf::IntRect(_position.x, _position.y, _sprite_size.x, _sprite_size.y));
	sprite->setScale(_size.x / _sprite_size.x, _size.y / _sprite_size.y);
}

void SpriteRenderer::SetNextSpriteRect(int num_sprite_on_sheet) {
	sprite->setTextureRect(sf::IntRect(0+ ( num_sprite_on_sheet * sprite_space.x), 0 + (num_sprite_on_sheet * (sprite_size.y + sprite_space.y)), sprite_size.x, sprite_size.y));
	sprite->setScale(width / sprite_size.x, height / sprite_size.y);
}

void SpriteRenderer::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);

	sprite->setPosition(GetOwner()->GetPosition().GetX(), GetOwner()->GetPosition().GetY());
	_window->draw(*sprite);
}

void SpriteRenderer::SetOrigin(float x, float y)
{
	sprite->setOrigin(x, y);
}