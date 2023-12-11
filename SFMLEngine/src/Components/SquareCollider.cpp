#include "Components/SquareCollider.h"
#include "Maths/Vector2.h"
#include <iostream>

bool SquareCollider::IsColliding(const SquareCollider& _collider_a, const SquareCollider& _collider_b)
{
	sf::RectangleShape rPlayer;
	sf::RectangleShape rObject;

	rPlayer.setPosition(sf::Vector2f(_collider_a.GetOwner()->GetPosition().GetX(), _collider_a.GetOwner()->GetPosition().GetY()));
	rPlayer.setSize(sf::Vector2f(_collider_a.GetWidth(), _collider_a.GetHeight()));
	rObject.setPosition(sf::Vector2f(_collider_b.GetOwner()->GetPosition().GetX(), _collider_b.GetOwner()->GetPosition().GetY()));
	rObject.setSize(sf::Vector2f(_collider_b.GetWidth(), _collider_b.GetHeight()));

	sf::FloatRect playerBounds = _collider_a.GetOwner()->getBounds(rPlayer);
	sf::FloatRect objectBounds = _collider_b.GetOwner()->getBounds(rObject);

	if (_collider_b.GetOwner()->GetType() == MoveType && _collider_a.GetOwner()->GetType() == PlayerType) 
	{
		if (playerBounds.intersects(objectBounds))
		{
			return true;
		}
		return false;
	}

	else if(playerBounds.intersects(objectBounds))
	{
		int collisionWidth = std::min(playerBounds.left + playerBounds.width, objectBounds.left + objectBounds.width) - std::max(playerBounds.left, objectBounds.left);
		int collisionHeight = std::min(playerBounds.top + playerBounds.height, objectBounds.top + objectBounds.height) - std::max(playerBounds.top, objectBounds.top);
		// top collision
		if (playerBounds.top > objectBounds.top && playerBounds.top <= objectBounds.top + objectBounds.height && ((playerBounds.left <= objectBounds.left && playerBounds.left + playerBounds.width >= objectBounds.left) || (playerBounds.left >= objectBounds.left && playerBounds.left <= objectBounds.left + objectBounds.width)) && (collisionWidth > collisionHeight && collisionWidth > 5))
		{
			_collider_a.GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("up", false);
		}
		// bottom collision
		if (playerBounds.top <= objectBounds.top && playerBounds.top + playerBounds.height >= objectBounds.top && ((playerBounds.left <= objectBounds.left && playerBounds.left + playerBounds.width >= objectBounds.left) || (playerBounds.left >= objectBounds.left && playerBounds.left <= objectBounds.left + objectBounds.width)) && (collisionWidth > collisionHeight && collisionWidth > 5))
		{
			_collider_a.GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("down", false);
		}
		//left collision
		if (playerBounds.left >= objectBounds.left && playerBounds.left + playerBounds.width >= objectBounds.left + objectBounds.width && ((playerBounds.top <= objectBounds.top && playerBounds.top + playerBounds.height >= objectBounds.top) || (playerBounds.top >= objectBounds.top && playerBounds.top <= objectBounds.top + objectBounds.height)) && (collisionWidth < collisionHeight && collisionHeight > 5))
		{
			_collider_a.GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("left", false);

		}
		//right collision
		if (playerBounds.left <= objectBounds.left && playerBounds.left + playerBounds.width <= objectBounds.left + objectBounds.width && ((playerBounds.top <= objectBounds.top && playerBounds.top + playerBounds.height >= objectBounds.top) || (playerBounds.top >= objectBounds.top && playerBounds.top <= objectBounds.top + objectBounds.height)) && (collisionWidth < collisionHeight && collisionHeight > 5))
			{
				_collider_a.GetOwner()->GetComponent<SquareCollider>()->SetCanMoving("right", false);
			}
		return true;
	}
	return false;
}
